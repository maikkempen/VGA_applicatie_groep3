/**
  ******************************************************************************
  * @file    IO_func.h
  * @author  Bob Rip
  * @author  Maik Kempen
  * @brief   Header file for IO_func.c
  ******************************************************************************
  */

#ifndef DRAWBITMAP_H_
#define DRAWBITMAP_H_

/* INCLUDES ******************************/
#include <stdio.h>

#include "main.h"
#include "resources/bitmaps.h"

/* DEFINES ******************************/

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
void IO_drawBitmap(uint8_t nr, int16_t x1, int16_t y1, uint8_t color);

#endif /* DRAWBITMAP_H_ */
