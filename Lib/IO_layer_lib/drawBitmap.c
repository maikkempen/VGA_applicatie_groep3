/**
  ******************************************************************************
  * @file    drawLine.c
  * @author  Maik Kempen
  * @brief   This file can draw a hardcoded bitmap image loaded in memory 
  *           on a screen with VGA input.
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include "drawBitmap.h"


/** @brief Reads bitmap pixels from bitmap pixel-array and draws it with UB_VGA API
 *
 *  @param x Top left corner x coordinate of bitmap picture on screen
 *  @param y Top left corner y coordinate of bitmap picture on screen
 *  @param bitmap Index of bitmap pixel-array from bitmaps.h file
 *  @param w Width in pixels of the specified bitmap
 *  @param h Height in pixels of the specified bitmap
 *  @param color color of monochrome bitmap picture
 */
void IO_drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color) {

  int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
  uint8_t byte = 0;

  // scan through all the bytes in bitmap pixel-array
  for (int16_t j = 0; j < h; j++, y++) {
    for (int16_t i = 0; i < w; i++) {
      if (i & 7)
        byte <<= 1;
      else
        byte = &bitmap[j * byteWidth + i / 8];
      if (byte & 0x80)
        UB_VGA_SetPixel(x + i, y, color);
    }
  }
}