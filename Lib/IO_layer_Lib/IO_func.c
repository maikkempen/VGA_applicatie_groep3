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
  * @retval	error code
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
  * @param  color selects color for background.
  * @retval returns a zero for no errors
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
  * @retval	error code
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
  *  @retval error code.
  */
uint8_t IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color)
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
	return 0;
}


/**
  * @brief 	Draws a rectangle on the screen. The rectangle can be filled or unfilled
  * @param	x_lup x coordinate of the left upper corner
  * @param	y_lup y coordinate of the left upper corner
  * @param	width width of the rectangle
  * @param	height height of the rectangle
  * @param	color 	color of the rectangle
  * @param	filled 0 = then rectangle is filled, >0 = thickness of unfilled rectangle
  * @retval error code.
  */
uint8_t IO_drawRectangle(uint16_t x_lup, uint16_t y_lup, uint16_t width, uint16_t height, uint8_t color, uint16_t filled)
{
	//not filled rectangle
	if(filled)
	{
		IO_drawLine(x_lup, y_lup, x_lup + width, y_lup, color, filled); // draw upper side
		IO_drawLine(x_lup, y_lup, x_lup, y_lup + height, color, filled); // draw left side
		IO_drawLine(x_lup + width - filled + 1, y_lup, x_lup + width - filled + 1, y_lup + height, color, filled); // draw right side. The (- filled + 1) is for the offset of the thickness
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
	return 0;
}


/**
  * @brief  Finds character symbol (glyph) index in font
  * bitmap array
  * @param	c character symbol to search for
  * @retval index of character symbol in font bitmap array (-1 = corresponding glyph not found)
  */
int8_t findGlyph(char c)
{
	uint8_t index = 0;

	// return 127 if it found a space, there's no glyph available for space character
	if (c == ' ')
		return 127;
	
	// look through ASCII array of glyphs until array end indicator (0)
	while (glyphs_ascii_list[index] != 0)
	{
		if (c == glyphs_ascii_list[index])
			return index;	// found the character
		else
			index++;
	}

	return -1;	// error: character glyph not found in ASCII array of glyphs
}


/**
  * @brief 	Draws text on the screen. The text can be of different colors, 
  * font names, font sizes and normal, cursive or bold.
  * @param x1 x coordinate of the left upper corner of the first letter
  * @param y1 y coordinate of the left upper corner of the first letter
  * @param color color of the the text
  * @param textString the string that contains the text
  * @param fontName the index of the font name (0 = arial, 1 = consolas)
  * @param fontSize the size of the font (1 = 16px font-height, 2 = 32px font-height)
  * @param fontStyle the style of the font (0 = normal, 1 = bold, 2 = cursive)
  */
void IO_drawText(uint16_t x1, uint16_t y1, uint8_t color, uint8_t *textString, uint8_t fontName, uint8_t fontSize, uint8_t fontStyle)
{
	uint8_t byte_pixels = 0;			   // byte with 8 monochrome pixel bits of font glyph



}
