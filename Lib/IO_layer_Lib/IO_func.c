/**
  ******************************************************************************
  * @file    IO_func.c
  * @author  B.J. Rip
  * @brief   This file contains all the functions to draw on the VGA screen
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include "IO_func.h"

void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{

  int16_t steep = abs(y1 - y0) > abs(x1 - x0);
  if (steep) {
    _swap_int16_t(&x0, &y0);
    _swap_int16_t(&x1, &y1);
  }

  if (x0 > x1) {
    _swap_int16_t(&x0, &x1);
    _swap_int16_t(&y0, &y1);
  }

  int16_t dx, dy;
  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int16_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  for (; x0 <= x1; x0++) {
    if (steep) {
    	UB_VGA_SetPixel(y0, x0, color);
    } else {
    	UB_VGA_SetPixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
  }
}

void _swap_int16_t (int16_t *a, int16_t *b)
{
	int16_t temp = b;
	b = a;
	a = temp;
}
