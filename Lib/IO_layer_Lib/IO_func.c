/**
  ******************************************************************************
  * @file    IO_func.c
  * @author  B.J. Rip
  * @brief   This file contains all the functions to draw on the VGA screen
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include "IO_func.h"

void IO_drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, uint16_t width)
{
	uint16_t tempx0, tempx1, tempy0, tempy1;
	for(int i = 0; i < width; i++)
	{
		int16_t steep = abs(y1 - y0) > abs(x1 - x0); //check how steep the line is. If the angle is more then 45 degrees steep = true

		if (steep) {
			//assign x to y and y to x because the difference between y coordinates is greater then x
			tempx0 = y0;
			tempy0 = x0;
			tempx1 = y1;
			tempy1 = x1;
		}
		else {

			tempx0 = x0;
			tempy0 = y0;
			tempx1 = x1;
			tempy1 = y1;
		}

		if (x0 > x1) { 			//check if the values are switched around
			_swap_int16_t(&tempx0, &tempx1);
			_swap_int16_t(&tempy0, &tempy1);
		}

		int16_t dx, dy;
		dx = tempx1 - tempx0; 			// delta x
		dy = abs(tempy1 - tempy0); 		// delta y

		int16_t err = dx / 2;
		int16_t ystep;

		if (tempy0 < tempy1) {
			ystep = 1;
		} else {
			ystep = -1;
		}

		for (; tempx0 <= tempx1; tempx0++) {
			if (steep) {
				UB_VGA_SetPixel(tempy0, tempx0, color);
			} else {
				UB_VGA_SetPixel(tempx0, tempy0, color);
			}
			err -= dy;
			if (err < 0) {
				tempy0 += ystep;
				err += dx;

			}
		}

		//add an extra layer to the line for the width
		if(y0 == y1){ 		// if the line is horizontal
			y0++; y1++;
		}
		else{				// if the line is diagonal or vertical
		x0++; x1++;
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
  * @brief  fills the screen with a color.
  * @param  color selects color for background
  */
void IO_clearScreen(uint8_t color){
	UB_VGA_FillScreen(color);
}
