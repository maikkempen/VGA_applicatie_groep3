/**
  ******************************************************************************
  * @file    font.h
  * @author  Maik Kempen
  * @brief   Header file for font.c
  ******************************************************************************
  */

#ifndef FONT_H_
#define FONT_H_


/* INCLUDES ******************************/
#include <stdio.h>
#include <stdint.h>


/* DEFINES ******************************/
#define STANDARD_FONT_SIZE 16   /*!< Standard font height in pixels */

/* ENUMS ******************************/

/* STRUCTS ******************************/

/*! Struct for storing bitmap information about glyphs (font characters) */
typedef struct _font_glyph_desc
{
	uint8_t width_px;        /*!< Width in pixels of the glyph */
	uint16_t offset;         /*!< Byte offset of the glyph in the bitmap array */ 
} font_glyph_desc;

/* EXTERN VARIABLES ******************************/
extern const uint32_t glyphs_ascii_list[];

extern const uint8_t arial_regular_bitmap[];
extern const uint8_t arial_bold_bitmap[];
extern const uint8_t arial_cursive_bitmap[];
extern const uint8_t consolas_regular_bitmap[];
extern const uint8_t consolas_bold_bitmap[];
extern const uint8_t consolas_cursive_bitmap[];

extern const font_glyph_desc arial_regular_glyph_dsc[];
extern const font_glyph_desc arial_bold_glyph_dsc[];
extern const font_glyph_desc arial_cursive_glyph_dsc[];
extern const font_glyph_desc consolas_regular_glyph_dsc[];
extern const font_glyph_desc consolas_bold_glyph_dsc[];
extern const font_glyph_desc consolas_cursive_glyph_dsc[];

extern const char *font_types_list[];
extern const uint8_t *font_bitmaps_list[];
extern const font_glyph_desc *font_dsc_list[];


/* PROTOTYPE ******************************/


#endif /* FONT_H_ */
