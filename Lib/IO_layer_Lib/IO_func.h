/**
  ******************************************************************************
  * @file    IO_func.h
  * @author  Bob Rip
  * @author  Max Besseling
  * @author  Maik Kempen
  * @brief   Header file for IO_func.c
  ******************************************************************************
  */

#ifndef IO_FUNC_H_
#define IO_FUNC_H_

/* INCLUDES ******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "resources/bitmaps.h"
#include "resources/text_font/font.h"
#include "stm32_ub_vga_screen.h"


/* DEFINES ******************************/

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPE ******************************/
uint8_t IO_drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t color, uint16_t width);
void _swap_int16_t (uint16_t *a, uint16_t *b);
uint8_t IO_clearScreen(uint8_t color);
uint8_t IO_drawCircle (uint16_t x1, uint16_t y1, int16_t r, uint8_t color);
uint8_t IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color);
uint8_t IO_drawRectangle(uint16_t x_lup, uint16_t y_lup, uint16_t width, uint16_t height, uint8_t color, uint16_t filled);
int8_t findGlyph(char c);
void IO_drawGlyph(int8_t index_glyph, int16_t x1, int16_t y1, uint8_t color, uint8_t font_size, const uint8_t *font_bitmap, const font_glyph_desc *font_desc);
void IO_drawText(uint16_t x1, uint16_t y1, uint8_t color, char *textString, char *fontName, uint8_t fontSize, char *fontStyle);

#endif /* IO_FUNC_H_ */
