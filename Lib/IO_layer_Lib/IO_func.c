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
uint8_t IO_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color, uint16_t weight)
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
	return 0;
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
uint8_t IO_clearScreen(uint8_t color){
	UB_VGA_FillScreen(color);
	return 0;
}

/**
  * @brief  This function draws a circle on the VGA-screen. The circle can be adjusted in origin point, color and radius
  * @param  x1 		Origin point x coordinate
  * @param	y1 		Origin point y coordinate
  * @param	r 		Radius of the circle
  * @param	color	Defines color if the circle
  */
uint8_t IO_drawCircle (uint16_t x1, uint16_t y1, int16_t r, uint8_t color)
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
	return 0;
}

/** 
  * @brief Read monochrome bitmap pixels from bitmap pixel-array and draw it with UB_VGA API
  * using specified color (set bits are transparent)
  *  @param nr Index of bitmap picture (choose between four arrow directions and happy/angry smiley face)
  *  @param x Top left corner x coordinate of bitmap picture on screen
  *  @param y Top left corner y coordinate of bitmap picture on screen
  *  @param color 8-bit hex color for monochrome bitmap picture
  */
void IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color)
{
	int16_t ind = 0;		 // byte index in 2D bitmap-array
	uint8_t byte_pixels = 0; // byte with 8 monochrome pixel bits

	// amount of bytes per picture row
	// 8 pixels per byte are stored, so divide width and current x position by 8
	int16_t row_width = (BMP_WIDTH) / 8;

	// scan through bitmap array with current y position and x position
	for (int16_t ypos = 0; ypos < BMP_HEIGHT - 1; ypos++)
	{
		for (int16_t xpos = 0; xpos < BMP_WIDTH - 1; xpos++)
		{
			if (xpos & 7) // left-shift byte_pixels for every xpos increment
				byte_pixels <<= 1;
			else // update bitmap array index and value every 8 pixels
			{
				// calculate bitmap-array index
				// start drawing at bottom left, because bitmap pixel-data is horizontally flipped (left to right, bottom to top)
				ind = (BMP_HEIGHT - 1 - ypos) * row_width + xpos / 8;
				byte_pixels = arr_bitmap[nr][ind];
			}

			// draw pixel with color if bit is not set
			if (!(byte_pixels & 0x80))
				UB_VGA_SetPixel(xpos + x1, ypos + y1, color);
		}
	}
}
