
#ifndef BITMAPS_H_
#define BITMAPS_H_

/* INCLUDES ******************************/
#include <stdio.h>
//#include "main.h"

/* DEFINES *******************************/
#define NUM_BITMAPS 7       /*!< Amount of bitmap pictures in 2D array */
#define BYTES_BITMAP 2048   /*!< Amount of bytes per bitmap */

#define BMP_WIDTH 128       /*!< Width in pixels of every bitmap picture */
#define BMP_HEIGHT 128      /*!< Height in pixels of every bitmap picture */

extern const uint8_t arr_bitmap[NUM_BITMAPS][BYTES_BITMAP];
#endif /* BITMAPS_H_ */
