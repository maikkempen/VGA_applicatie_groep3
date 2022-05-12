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
void IO_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint8_t color, uint16_t width);
void _swap_int16_t (uint16_t *a, uint16_t *b);

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

#endif /* LL_H_ */
