/**
  ******************************************************************************
  * @file    IO_func.c
  * @author  B.J. Rip; M.M. Besseling
  * @brief   This file contains all the functions to draw on the VGA screen
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include "IO_func.h"

void IO_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, uint16_t width)
{
	uint16_t tempx1, tempx2, tempy1, tempy2;
	for(int i = 0; i < width; i++)
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

		int16_t err = dx / 2;
		int16_t ystep;

		if (tempy1 < tempy2) {
			ystep = 1;
		} else {
			ystep = -1;
		}

		for (; tempx1 <= tempx2; tempx1++) {
			if (steep) {
				UB_VGA_SetPixel(tempy1, tempx1, color);
			} else {
				UB_VGA_SetPixel(tempx1, tempy1, color);
			}
			err -= dy;
			if (err < 0) {
				tempy1 += ystep;
				err += dx;

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
  * @retval none
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
