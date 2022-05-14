/**
  ******************************************************************************
  * @file    IO_func.c
  * @author  Bob Rip
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
  * @brief  fills the screen with a color.
  * @param  color selects color for background
  */
void IO_clearScreen(uint8_t color)
{
	UB_VGA_FillScreen(color);
}


/**
  * @brief 	Draws a rectangle on the screen. The rectangle can be filled or unfilled
  * @param	x_lup x coordinate of the left upper corner
  * @param	y_lup y coordinate of the left upper corner
  * @param	width width of the rectangle
  * @param	height height of the rectangle
  * @param	color 	color of the rectangle
  * @param	filled 0 = then rectangle is filled, >0 = thickness of unfilled rectangle
  */
void IO_drawRectangle(uint16_t x_lup, uint16_t y_lup, uint16_t width, uint16_t height, uint8_t color, uint16_t filled)
{
	//not filled rectangle
	if(filled)
	{
		IO_drawLine(x_lup, y_lup, x_lup + width, y_lup, color, filled); // draw upper side
		IO_drawLine(x_lup, y_lup, x_lup, y_lup + height, color, filled); // draw left side
		IO_drawLine(x_lup + width - filled + 1, y_lup, x_lup + width - filled + 1, y_lup + height, color, filled); // draw right side
		IO_drawLine(x_lup, y_lup + height, x_lup + width, y_lup + height, color, filled); // draw down side
	}
	//filled rectangle
	else
	{
		for(int i = x_lup; i <= x_lup + width; i++)
		{
			for(int n = y_lup; n <= y_lup + height; n++)
			{
				UB_VGA_SetPixel(i, n, color);
			}
		}
	}

}




