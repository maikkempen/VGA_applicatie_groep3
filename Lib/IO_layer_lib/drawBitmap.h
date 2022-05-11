/**
  ******************************************************************************
  * @file    drawBitmap.h
  * @author  Maik Kempen
  * @brief   Header file for drawBitmap.c
  ******************************************************************************
  */

#ifndef LL_H_
#define LL_H_

/* INCLUDES ******************************/
#include <stdio.h>
#include "main.h"

/* DEFINES ******************************/

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
void IO_drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[], int16_t w, int16_t h, uint8_t color);

#endif /* LL_H_ */
