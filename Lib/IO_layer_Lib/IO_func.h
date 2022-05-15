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
void IO_clearScreen(uint8_t color);
void IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color);
void IO_drawRectangle(uint16_t x_lup, uint16_t y_lup, uint16_t breedte, uint16_t hoogte, uint8_t kleur, uint16_t gevuld);
int8_t findGlyph(char c);
void IO_drawText(uint16_t x1, uint16_t y1, uint8_t color, uint8_t *textString, uint8_t fontName, uint8_t fontSize, uint8_t fontStyle);

#endif /* IO_FUNC_H_ */
