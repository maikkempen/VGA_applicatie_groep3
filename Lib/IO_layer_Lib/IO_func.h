/**
  ******************************************************************************
  * @file    IO_func.h
  * @author  Bob Rip
  * @author  Maik Kempen
  * @brief   Header file for IO_func.c
  ******************************************************************************
  */

#ifndef LL_H_
#define LL_H_

/* INCLUDES ******************************/
#include <stdio.h>
#include <stdlib.h>

#include "stm32_ub_vga_screen.h"


/* DEFINES ******************************/

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPE ******************************/
void IO_drawLine(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint8_t color, uint16_t width);
void _swap_int16_t (uint16_t *a, uint16_t *b);
void IO_drawFigure (uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3,
		uint16_t x4, uint16_t y4,uint16_t x5, uint16_t y5, uint8_t color);
void IO_drawCircle (uint16_t x1, uint16_t y1, int16_t r, uint8_t color);
void IO_clearScreen(uint8_t color);

#endif /* LL_H_ */
