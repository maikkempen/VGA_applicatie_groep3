/**
  ******************************************************************************
  * @file    IO_func.h
  * @author  Bob Rip
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
#include "stm32_ub_vga_screen.h"

/* DEFINES ******************************/

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
void IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color);

#endif /* IO_FUNC_H_H */
