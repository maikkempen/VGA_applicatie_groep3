/**
  ******************************************************************************
  * @file    IO_func.c
  * @author  Bob Rip
  * @author  Max Besseling
  * @author  Maik Kempen
  * @brief   This file contains all the functions to draw on the VGA screen
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include "IO_func.h"


/**
  * @brief  Draws a line on the VGA screen
  * @param	x1 first x coordinate of the line
  * @param  y1 first y coordinate of the line
  * @param  x2 second x coordinate of the line
  * @param  y2 second y coordinate of the line
  * @param  color color of the line
  * @param  weight width of the line
  */
void IO_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color, uint16_t weight)
{
	uint16_t tempx1, tempx2, tempy1, tempy2;
	for(int i = 0; i < weight; i++)
	{
		int16_t steep = abs(y2 - y1) > abs(x2 - x1); //check how steep the line is. If the angle is more then 45 degrees steep = true

		if (steep) {
			//assign x to y and y to x because the difference between y coordinates is greater then x
			tempx1 = y1;
			tempy1 = x1;
			tempx2 = y2;
			tempy2 = x2;
		}
		else {

			tempx1 = x1;
			tempy1 = y1;
			tempx2 = x2;
			tempy2 = y2;
		}

		if (x1 > x2) { 			//check if the values are switched around
			_swap_int16_t(&tempx1, &tempx2);
			_swap_int16_t(&tempy1, &tempy2);
		}

		int16_t dx, dy;
		dx = tempx2 - tempx1; 			// delta x
		dy = abs(tempy2 - tempy1); 		// delta y

		int16_t dev = dx / 2;			//dev starts with half delta x for the angle of the line
		int16_t ystep;

		//decide the direction of the line
		if (tempy1 < tempy2) {
			ystep = 1;
		} else {
			ystep = -1;
		}

		for (; tempx1 <= tempx2; tempx1++) {
			if (steep) {		// if steep values are switched around
				UB_VGA_SetPixel(tempy1, tempx1, color);
			} else {
				UB_VGA_SetPixel(tempx1, tempy1, color);
			}

			//decide when the line moves down a bit
			dev -= dy;
			if (dev < 0) {
				tempy1 += ystep;
				dev += dx;
			}
		}

		//add an extra layer to the line for the width
		if(y1 == y2){ 		// if the line is horizontal
			y1++; y2++;
		}
		else{				// if the line is diagonal or vertical
		x1++; x2++;
		}
	}

}


/**
  * @brief  switch the values of two integers
  * @param	*a pointer to the first integer
  * @param	*b pointer to the second integer
  */
void _swap_int16_t (uint16_t *a, uint16_t *b)
{
	uint16_t temp = *b;
	*b = *a;
	*a = temp;
}

/**
  * @brief  This function draws a circle on the VGA-screen. The circle can be adjusted in origin point, color and radius
  * @param  x1 		Origin point x coordinate
  * @param	y1 		Origin point y coordinate
  * @param	r 		Radius of the circle
  * @param	color	Defines color if the circle
  */
void IO_drawCircle (uint16_t x1, uint16_t y1, int16_t r, uint8_t color)
{
	int16_t f = 1 - r;								// defines when to pull up the y coordinate
	int16_t ddF_x = 1;								// this parameter keeps track of when to increase the x value
	int16_t ddF_y = -2 * r;							// this parameter keeps track of when to decrease the y value
	int16_t x = 0;									// defines x coordinate pixel
	int16_t y = r;									// defines y coordinate pixel

	UB_VGA_SetPixel(x1, y1 + r, color);				// defines border pixel and it's color
	UB_VGA_SetPixel(x1, y1 - r, color);
	UB_VGA_SetPixel(x1 + r, y1, color);
	UB_VGA_SetPixel(x1 - r, y1, color);

	while (x < y)									// as long x value is smaller than the y value, go through this loop
	{
		if (f >= 0)									// this statement defines when to decrease the y coordinate with 1
		{											// only if the f value is greater than 0
			y--;
			ddF_y += 2;
			f += ddF_y;
	    }											// at the end of this statement, the f value will be negative

	    x++; 										// increase the x coordinate with 1
	    ddF_x += 2;									// this and the following line increase the the f value
	    f += ddF_x;									// when the f value is grater than 0, the code will know to decrease the y coordinate

	    UB_VGA_SetPixel(x1 + x, y1 + y, color);		// put's a pixel on the VGA screen with the correct xy coordinates
	    UB_VGA_SetPixel(x1 - x, y1 + y, color);
	    UB_VGA_SetPixel(x1 + x, y1 - y, color);
	    UB_VGA_SetPixel(x1 - x, y1 - y, color);
	    UB_VGA_SetPixel(x1 + y, y1 + x, color);
	    UB_VGA_SetPixel(x1 - y, y1 + x, color);
	    UB_VGA_SetPixel(x1 + y, y1 - x, color);
	    UB_VGA_SetPixel(x1 - y, y1 - x, color);
	}
}

void IO_drawFigure (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3,
		uint16_t x4, uint16_t y4,uint16_t x5, uint16_t y5, uint8_t color)
{
	IO_drawLine(x1,y1, x2,y2, color, 1);
	IO_drawLine(x2,y2, x3,y3, color, 1);
	IO_drawLine(x3,y3, x4,y4, color, 1);
	IO_drawLine(x4,y4, x5,y5, color, 1);
	IO_drawLine(x5,y5, x1,y1, color, 1);
}
