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


/** @brief Read monochrome bitmap pixels from bitmap pixel-array and draw it with UB_VGA API
 * using specified color (set bits are transparent)
 * 
 *  @param nr Index of bitmap picture (choose between four arrow directions and happy/angry smiley face)
 *  @param x Top left corner x coordinate of bitmap picture on screen
 *  @param y Top left corner y coordinate of bitmap picture on screen
 *  @param color 8-bit hex color for monochrome bitmap picture
 */
void IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color) 
{
  int16_t ind = 0;          // byte index in 2D bitmap-array
  uint8_t byte_pixels = 0;  // byte with 8 monochrome pixel bits

  // amount of bytes per picture row
  // 8 pixels per byte are stored, so divide width and current x position by 8
  int16_t row_width = (BMP_WIDTH) / 8;

  // scan through bitmap array with current y position and x position
  for (int16_t ypos = 0; ypos < BMP_HEIGHT-1; ypos++) 
  {
    for (int16_t xpos = 0; xpos < BMP_WIDTH-1; xpos++)
    {   
      if (xpos & 7) // left-shift byte_pixels for every xpos increment
        byte_pixels <<= 1;
      else  // update bitmap array index and value every 8 pixels
      {
        // calculate bitmap-array index
        // start drawing at bottom left, because bitmap pixel-data is horizontally flipped (left to right, bottom to top)
        ind = (BMP_HEIGHT-1 - ypos) * row_width + xpos / 8;
        byte_pixels = arr_bitmap[nr][ind];
      }

      // draw pixel with color if bit is not set
      if (!(byte_pixels & 0x80))
        UB_VGA_SetPixel(xpos + x1, ypos + y1, color);
    }
  }
}
