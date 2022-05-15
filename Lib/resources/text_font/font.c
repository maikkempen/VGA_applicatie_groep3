/**
 ******************************************************************************
 * @file    font.c
 * @author  Maik Kempen
 * @brief   Utility file to use with fonts for VGA text generation
 ******************************************************************************
 */

#include "font.h"

/*! Array of ASCII values of glyphs in order */
const uint32_t glyphs_ascii_list[] = {
	33,	 /*ASCII: 0021 (!)*/
	44,	 /*ASCII: 002c (,)*/
	46,	 /*ASCII: 002e (.)*/
	63,	 /*ASCII: 003f (?)*/
	65,	 /*ASCII: 0041 (A)*/
	66,	 /*ASCII: 0042 (B)*/
	67,	 /*ASCII: 0043 (C)*/
	68,	 /*ASCII: 0044 (D)*/
	69,	 /*ASCII: 0045 (E)*/
	70,	 /*ASCII: 0046 (F)*/
	71,	 /*ASCII: 0047 (G)*/
	72,	 /*ASCII: 0048 (H)*/
	73,	 /*ASCII: 0049 (I)*/
	74,	 /*ASCII: 004a (J)*/
	75,	 /*ASCII: 004b (K)*/
	76,	 /*ASCII: 004c (L)*/
	77,	 /*ASCII: 004d (M)*/
	78,	 /*ASCII: 004e (N)*/
	79,	 /*ASCII: 004f (O)*/
	80,	 /*ASCII: 0050 (P)*/
	81,	 /*ASCII: 0051 (Q)*/
	82,	 /*ASCII: 0052 (R)*/
	83,	 /*ASCII: 0053 (S)*/
	84,	 /*ASCII: 0054 (T)*/
	85,	 /*ASCII: 0055 (U)*/
	86,	 /*ASCII: 0056 (V)*/
	87,	 /*ASCII: 0057 (W)*/
	88,	 /*ASCII: 0058 (X)*/
	89,	 /*ASCII: 0059 (Y)*/
	90,	 /*ASCII: 005a (Z)*/
	97,	 /*ASCII: 0061 (a)*/
	98,	 /*ASCII: 0062 (b)*/
	99,	 /*ASCII: 0063 (c)*/
	100, /*ASCII: 0064 (d)*/
	101, /*ASCII: 0065 (e)*/
	102, /*ASCII: 0066 (f)*/
	103, /*ASCII: 0067 (g)*/
	104, /*ASCII: 0068 (h)*/
	105, /*ASCII: 0069 (i)*/
	106, /*ASCII: 006a (j)*/
	107, /*ASCII: 006b (k)*/
	108, /*ASCII: 006c (l)*/
	109, /*ASCII: 006d (m)*/
	110, /*ASCII: 006e (n)*/
	111, /*ASCII: 006f (o)*/
	112, /*ASCII: 0070 (p)*/
	113, /*ASCII: 0071 (q)*/
	114, /*ASCII: 0072 (r)*/
	115, /*ASCII: 0073 (s)*/
	116, /*ASCII: 0074 (t)*/
	117, /*ASCII: 0075 (u)*/
	118, /*ASCII: 0076 (v)*/
	119, /*ASCII: 0077 (w)*/
	120, /*ASCII: 0078 (x)*/
	121, /*ASCII: 0079 (y)*/
	122, /*ASCII: 007a (z)*/
	0,	 /*End indicator*/
};

/*! Array of Arial regular type glyph descriptions */
const font_glyph_desc arial_regular_glyph_dsc[] =
{
	{.width_px = 2, .offset = 0},	  /*ASCII: 0021 (!)*/
	{.width_px = 2, .offset = 16},	  /*ASCII: 002c (,)*/
	{.width_px = 2, .offset = 32},	  /*ASCII: 002e (.)*/
	{.width_px = 8, .offset = 48},	  /*ASCII: 003f (?)*/
	{.width_px = 10, .offset = 64},	  /*ASCII: 0041 (A)*/
	{.width_px = 8, .offset = 96},	  /*ASCII: 0042 (B)*/
	{.width_px = 10, .offset = 112},  /*ASCII: 0043 (C)*/
	{.width_px = 9, .offset = 144},	  /*ASCII: 0044 (D)*/
	{.width_px = 8, .offset = 176},	  /*ASCII: 0045 (E)*/
	{.width_px = 7, .offset = 192},	  /*ASCII: 0046 (F)*/
	{.width_px = 11, .offset = 208},  /*ASCII: 0047 (G)*/
	{.width_px = 8, .offset = 240},	  /*ASCII: 0048 (H)*/
	{.width_px = 2, .offset = 256},	  /*ASCII: 0049 (I)*/
	{.width_px = 6, .offset = 272},	  /*ASCII: 004a (J)*/
	{.width_px = 9, .offset = 288},	  /*ASCII: 004b (K)*/
	{.width_px = 7, .offset = 320},	  /*ASCII: 004c (L)*/
	{.width_px = 10, .offset = 336},  /*ASCII: 004d (M)*/
	{.width_px = 8, .offset = 368},	  /*ASCII: 004e (N)*/
	{.width_px = 11, .offset = 384},  /*ASCII: 004f (O)*/
	{.width_px = 8, .offset = 416},	  /*ASCII: 0050 (P)*/
	{.width_px = 11, .offset = 432},  /*ASCII: 0051 (Q)*/
	{.width_px = 9, .offset = 464},	  /*ASCII: 0052 (R)*/
	{.width_px = 9, .offset = 496},	  /*ASCII: 0053 (S)*/
	{.width_px = 9, .offset = 528},	  /*ASCII: 0054 (T)*/
	{.width_px = 8, .offset = 560},	  /*ASCII: 0055 (U)*/
	{.width_px = 10, .offset = 576},  /*ASCII: 0056 (V)*/
	{.width_px = 13, .offset = 608},  /*ASCII: 0057 (W)*/
	{.width_px = 10, .offset = 640},  /*ASCII: 0058 (X)*/
	{.width_px = 10, .offset = 672},  /*ASCII: 0059 (Y)*/
	{.width_px = 9, .offset = 704},	  /*ASCII: 005a (Z)*/
	{.width_px = 8, .offset = 736},	  /*ASCII: 0061 (a)*/
	{.width_px = 8, .offset = 752},	  /*ASCII: 0062 (b)*/
	{.width_px = 7, .offset = 768},	  /*ASCII: 0063 (c)*/
	{.width_px = 7, .offset = 784},	  /*ASCII: 0064 (d)*/
	{.width_px = 8, .offset = 800},	  /*ASCII: 0065 (e)*/
	{.width_px = 5, .offset = 816},	  /*ASCII: 0066 (f)*/
	{.width_px = 7, .offset = 832},	  /*ASCII: 0067 (g)*/
	{.width_px = 7, .offset = 848},	  /*ASCII: 0068 (h)*/
	{.width_px = 3, .offset = 864},	  /*ASCII: 0069 (i)*/
	{.width_px = 3, .offset = 880},	  /*ASCII: 006a (j)*/
	{.width_px = 7, .offset = 896},	  /*ASCII: 006b (k)*/
	{.width_px = 3, .offset = 912},	  /*ASCII: 006c (l)*/
	{.width_px = 11, .offset = 928},  /*ASCII: 006d (m)*/
	{.width_px = 7, .offset = 960},	  /*ASCII: 006e (n)*/
	{.width_px = 8, .offset = 976},	  /*ASCII: 006f (o)*/
	{.width_px = 8, .offset = 992},	  /*ASCII: 0070 (p)*/
	{.width_px = 7, .offset = 1008},  /*ASCII: 0071 (q)*/
	{.width_px = 5, .offset = 1024},  /*ASCII: 0072 (r)*/
	{.width_px = 7, .offset = 1040},  /*ASCII: 0073 (s)*/
	{.width_px = 4, .offset = 1056},  /*ASCII: 0074 (t)*/
	{.width_px = 7, .offset = 1072},  /*ASCII: 0075 (u)*/
	{.width_px = 7, .offset = 1088},  /*ASCII: 0076 (v)*/
	{.width_px = 10, .offset = 1104}, /*ASCII: 0077 (w)*/
	{.width_px = 7, .offset = 1136},  /*ASCII: 0078 (x)*/
	{.width_px = 7, .offset = 1152},  /*ASCII: 0079 (y)*/
	{.width_px = 7, .offset = 1168},  /*ASCII: 007a (z)*/
};

/*! Array of Arial bold type glyph descriptions */
const font_glyph_desc arial_bold_glyph_dsc[] =
{
	{.width_px = 3, .offset = 0},	  /*ASCII: 0021 (!)*/
	{.width_px = 3, .offset = 16},	  /*ASCII: 002c (,)*/
	{.width_px = 2, .offset = 32},	  /*ASCII: 002e (.)*/
	{.width_px = 8, .offset = 48},	  /*ASCII: 003f (?)*/
	{.width_px = 10, .offset = 64},	  /*ASCII: 0041 (A)*/
	{.width_px = 9, .offset = 96},	  /*ASCII: 0042 (B)*/
	{.width_px = 10, .offset = 128},  /*ASCII: 0043 (C)*/
	{.width_px = 9, .offset = 160},	  /*ASCII: 0044 (D)*/
	{.width_px = 8, .offset = 192},	  /*ASCII: 0045 (E)*/
	{.width_px = 7, .offset = 208},	  /*ASCII: 0046 (F)*/
	{.width_px = 11, .offset = 224},  /*ASCII: 0047 (G)*/
	{.width_px = 9, .offset = 256},	  /*ASCII: 0048 (H)*/
	{.width_px = 3, .offset = 288},	  /*ASCII: 0049 (I)*/
	{.width_px = 7, .offset = 304},	  /*ASCII: 004a (J)*/
	{.width_px = 9, .offset = 320},	  /*ASCII: 004b (K)*/
	{.width_px = 8, .offset = 352},	  /*ASCII: 004c (L)*/
	{.width_px = 11, .offset = 368},  /*ASCII: 004d (M)*/
	{.width_px = 8, .offset = 400},	  /*ASCII: 004e (N)*/
	{.width_px = 11, .offset = 416},  /*ASCII: 004f (O)*/
	{.width_px = 8, .offset = 448},	  /*ASCII: 0050 (P)*/
	{.width_px = 11, .offset = 464},  /*ASCII: 0051 (Q)*/
	{.width_px = 9, .offset = 496},	  /*ASCII: 0052 (R)*/
	{.width_px = 9, .offset = 528},	  /*ASCII: 0053 (S)*/
	{.width_px = 9, .offset = 560},	  /*ASCII: 0054 (T)*/
	{.width_px = 8, .offset = 592},	  /*ASCII: 0055 (U)*/
	{.width_px = 10, .offset = 608},  /*ASCII: 0056 (V)*/
	{.width_px = 14, .offset = 640},  /*ASCII: 0057 (W)*/
	{.width_px = 10, .offset = 672},  /*ASCII: 0058 (X)*/
	{.width_px = 10, .offset = 704},  /*ASCII: 0059 (Y)*/
	{.width_px = 9, .offset = 736},	  /*ASCII: 005a (Z)*/
	{.width_px = 8, .offset = 768},	  /*ASCII: 0061 (a)*/
	{.width_px = 8, .offset = 784},	  /*ASCII: 0062 (b)*/
	{.width_px = 8, .offset = 800},	  /*ASCII: 0063 (c)*/
	{.width_px = 8, .offset = 816},	  /*ASCII: 0064 (d)*/
	{.width_px = 8, .offset = 832},	  /*ASCII: 0065 (e)*/
	{.width_px = 5, .offset = 848},	  /*ASCII: 0066 (f)*/
	{.width_px = 8, .offset = 864},	  /*ASCII: 0067 (g)*/
	{.width_px = 7, .offset = 880},	  /*ASCII: 0068 (h)*/
	{.width_px = 2, .offset = 896},	  /*ASCII: 0069 (i)*/
	{.width_px = 3, .offset = 912},	  /*ASCII: 006a (j)*/
	{.width_px = 8, .offset = 928},	  /*ASCII: 006b (k)*/
	{.width_px = 2, .offset = 944},	  /*ASCII: 006c (l)*/
	{.width_px = 12, .offset = 960},  /*ASCII: 006d (m)*/
	{.width_px = 8, .offset = 992},	  /*ASCII: 006e (n)*/
	{.width_px = 9, .offset = 1008},  /*ASCII: 006f (o)*/
	{.width_px = 8, .offset = 1040},  /*ASCII: 0070 (p)*/
	{.width_px = 8, .offset = 1056},  /*ASCII: 0071 (q)*/
	{.width_px = 6, .offset = 1072},  /*ASCII: 0072 (r)*/
	{.width_px = 8, .offset = 1088},  /*ASCII: 0073 (s)*/
	{.width_px = 5, .offset = 1104},  /*ASCII: 0074 (t)*/
	{.width_px = 8, .offset = 1120},  /*ASCII: 0075 (u)*/
	{.width_px = 8, .offset = 1136},  /*ASCII: 0076 (v)*/
	{.width_px = 11, .offset = 1152}, /*ASCII: 0077 (w)*/
	{.width_px = 8, .offset = 1184},  /*ASCII: 0078 (x)*/
	{.width_px = 8, .offset = 1200},  /*ASCII: 0079 (y)*/
	{.width_px = 7, .offset = 1216},  /*ASCII: 007a (z)*/
};

/*! Array of Arial cursive type glyph descriptions */
const font_glyph_desc arial_cursive_glyph_dsc[] =
{
	{.width_px = 5, .offset = 0},	  /*ASCII: 0021 (!)*/
	{.width_px = 3, .offset = 16},	  /*ASCII: 002c (,)*/
	{.width_px = 3, .offset = 32},	  /*ASCII: 002e (.)*/
	{.width_px = 7, .offset = 48},	  /*ASCII: 003f (?)*/
	{.width_px = 9, .offset = 64},	  /*ASCII: 0041 (A)*/
	{.width_px = 10, .offset = 96},	  /*ASCII: 0042 (B)*/
	{.width_px = 10, .offset = 128},  /*ASCII: 0043 (C)*/
	{.width_px = 10, .offset = 160},  /*ASCII: 0044 (D)*/
	{.width_px = 10, .offset = 192},  /*ASCII: 0045 (E)*/
	{.width_px = 10, .offset = 224},  /*ASCII: 0046 (F)*/
	{.width_px = 10, .offset = 256},  /*ASCII: 0047 (G)*/
	{.width_px = 11, .offset = 288},  /*ASCII: 0048 (H)*/
	{.width_px = 5, .offset = 320},	  /*ASCII: 0049 (I)*/
	{.width_px = 8, .offset = 336},	  /*ASCII: 004a (J)*/
	{.width_px = 11, .offset = 352},  /*ASCII: 004b (K)*/
	{.width_px = 8, .offset = 384},	  /*ASCII: 004c (L)*/
	{.width_px = 13, .offset = 400},  /*ASCII: 004d (M)*/
	{.width_px = 11, .offset = 432},  /*ASCII: 004e (N)*/
	{.width_px = 10, .offset = 464},  /*ASCII: 004f (O)*/
	{.width_px = 10, .offset = 496},  /*ASCII: 0050 (P)*/
	{.width_px = 10, .offset = 528},  /*ASCII: 0051 (Q)*/
	{.width_px = 11, .offset = 560},  /*ASCII: 0052 (R)*/
	{.width_px = 9, .offset = 592},	  /*ASCII: 0053 (S)*/
	{.width_px = 9, .offset = 624},	  /*ASCII: 0054 (T)*/
	{.width_px = 10, .offset = 656},  /*ASCII: 0055 (U)*/
	{.width_px = 10, .offset = 688},  /*ASCII: 0056 (V)*/
	{.width_px = 14, .offset = 720},  /*ASCII: 0057 (W)*/
	{.width_px = 11, .offset = 752},  /*ASCII: 0058 (X)*/
	{.width_px = 10, .offset = 784},  /*ASCII: 0059 (Y)*/
	{.width_px = 9, .offset = 816},	  /*ASCII: 005a (Z)*/
	{.width_px = 8, .offset = 848},	  /*ASCII: 0061 (a)*/
	{.width_px = 8, .offset = 864},	  /*ASCII: 0062 (b)*/
	{.width_px = 8, .offset = 880},	  /*ASCII: 0063 (c)*/
	{.width_px = 9, .offset = 896},	  /*ASCII: 0064 (d)*/
	{.width_px = 8, .offset = 928},	  /*ASCII: 0065 (e)*/
	{.width_px = 6, .offset = 944},	  /*ASCII: 0066 (f)*/
	{.width_px = 8, .offset = 960},	  /*ASCII: 0067 (g)*/
	{.width_px = 8, .offset = 976},	  /*ASCII: 0068 (h)*/
	{.width_px = 4, .offset = 992},	  /*ASCII: 0069 (i)*/
	{.width_px = 4, .offset = 1008},  /*ASCII: 006a (j)*/
	{.width_px = 8, .offset = 1024},  /*ASCII: 006b (k)*/
	{.width_px = 4, .offset = 1040},  /*ASCII: 006c (l)*/
	{.width_px = 12, .offset = 1056}, /*ASCII: 006d (m)*/
	{.width_px = 8, .offset = 1088},  /*ASCII: 006e (n)*/
	{.width_px = 8, .offset = 1104},  /*ASCII: 006f (o)*/
	{.width_px = 8, .offset = 1120},  /*ASCII: 0070 (p)*/
	{.width_px = 8, .offset = 1136},  /*ASCII: 0071 (q)*/
	{.width_px = 6, .offset = 1152},  /*ASCII: 0072 (r)*/
	{.width_px = 7, .offset = 1168},  /*ASCII: 0073 (s)*/
	{.width_px = 5, .offset = 1184},  /*ASCII: 0074 (t)*/
	{.width_px = 8, .offset = 1200},  /*ASCII: 0075 (u)*/
	{.width_px = 7, .offset = 1216},  /*ASCII: 0076 (v)*/
	{.width_px = 10, .offset = 1232}, /*ASCII: 0077 (w)*/
	{.width_px = 8, .offset = 1264},  /*ASCII: 0078 (x)*/
	{.width_px = 8, .offset = 1280},  /*ASCII: 0079 (y)*/
	{.width_px = 8, .offset = 1296},  /*ASCII: 007a (z)*/
};

/*! Array of Consolas regular type glyph descriptions */
const font_glyph_desc consolas_regular_glyph_dsc[] =
{
	{.width_px = 3, .offset = 0},	 /*ASCII: 0021 (!)*/
	{.width_px = 5, .offset = 16},	 /*ASCII: 002c (,)*/
	{.width_px = 3, .offset = 32},	 /*ASCII: 002e (.)*/
	{.width_px = 6, .offset = 48},	 /*ASCII: 003f (?)*/
	{.width_px = 9, .offset = 64},	 /*ASCII: 0041 (A)*/
	{.width_px = 7, .offset = 96},	 /*ASCII: 0042 (B)*/
	{.width_px = 8, .offset = 112},	 /*ASCII: 0043 (C)*/
	{.width_px = 9, .offset = 128},	 /*ASCII: 0044 (D)*/
	{.width_px = 7, .offset = 160},	 /*ASCII: 0045 (E)*/
	{.width_px = 7, .offset = 176},	 /*ASCII: 0046 (F)*/
	{.width_px = 8, .offset = 192},	 /*ASCII: 0047 (G)*/
	{.width_px = 8, .offset = 208},	 /*ASCII: 0048 (H)*/
	{.width_px = 7, .offset = 224},	 /*ASCII: 0049 (I)*/
	{.width_px = 6, .offset = 240},	 /*ASCII: 004a (J)*/
	{.width_px = 8, .offset = 256},	 /*ASCII: 004b (K)*/
	{.width_px = 7, .offset = 272},	 /*ASCII: 004c (L)*/
	{.width_px = 9, .offset = 288},	 /*ASCII: 004d (M)*/
	{.width_px = 8, .offset = 320},	 /*ASCII: 004e (N)*/
	{.width_px = 9, .offset = 336},	 /*ASCII: 004f (O)*/
	{.width_px = 7, .offset = 368},	 /*ASCII: 0050 (P)*/
	{.width_px = 9, .offset = 384},	 /*ASCII: 0051 (Q)*/
	{.width_px = 8, .offset = 416},	 /*ASCII: 0052 (R)*/
	{.width_px = 8, .offset = 432},	 /*ASCII: 0053 (S)*/
	{.width_px = 9, .offset = 448},	 /*ASCII: 0054 (T)*/
	{.width_px = 8, .offset = 480},	 /*ASCII: 0055 (U)*/
	{.width_px = 9, .offset = 496},	 /*ASCII: 0056 (V)*/
	{.width_px = 9, .offset = 528},	 /*ASCII: 0057 (W)*/
	{.width_px = 9, .offset = 560},	 /*ASCII: 0058 (X)*/
	{.width_px = 9, .offset = 592},	 /*ASCII: 0059 (Y)*/
	{.width_px = 8, .offset = 624},	 /*ASCII: 005a (Z)*/
	{.width_px = 7, .offset = 640},	 /*ASCII: 0061 (a)*/
	{.width_px = 7, .offset = 656},	 /*ASCII: 0062 (b)*/
	{.width_px = 7, .offset = 672},	 /*ASCII: 0063 (c)*/
	{.width_px = 8, .offset = 688},	 /*ASCII: 0064 (d)*/
	{.width_px = 8, .offset = 704},	 /*ASCII: 0065 (e)*/
	{.width_px = 9, .offset = 720},	 /*ASCII: 0066 (f)*/
	{.width_px = 9, .offset = 752},	 /*ASCII: 0067 (g)*/
	{.width_px = 7, .offset = 784},	 /*ASCII: 0068 (h)*/
	{.width_px = 7, .offset = 800},	 /*ASCII: 0069 (i)*/
	{.width_px = 6, .offset = 816},	 /*ASCII: 006a (j)*/
	{.width_px = 8, .offset = 832},	 /*ASCII: 006b (k)*/
	{.width_px = 7, .offset = 848},	 /*ASCII: 006c (l)*/
	{.width_px = 9, .offset = 864},	 /*ASCII: 006d (m)*/
	{.width_px = 7, .offset = 896},	 /*ASCII: 006e (n)*/
	{.width_px = 9, .offset = 912},	 /*ASCII: 006f (o)*/
	{.width_px = 7, .offset = 944},	 /*ASCII: 0070 (p)*/
	{.width_px = 8, .offset = 960},	 /*ASCII: 0071 (q)*/
	{.width_px = 7, .offset = 976},	 /*ASCII: 0072 (r)*/
	{.width_px = 7, .offset = 992},	 /*ASCII: 0073 (s)*/
	{.width_px = 8, .offset = 1008}, /*ASCII: 0074 (t)*/
	{.width_px = 7, .offset = 1024}, /*ASCII: 0075 (u)*/
	{.width_px = 9, .offset = 1040}, /*ASCII: 0076 (v)*/
	{.width_px = 9, .offset = 1072}, /*ASCII: 0077 (w)*/
	{.width_px = 9, .offset = 1104}, /*ASCII: 0078 (x)*/
	{.width_px = 9, .offset = 1136}, /*ASCII: 0079 (y)*/
	{.width_px = 7, .offset = 1168}, /*ASCII: 007a (z)*/
};

/*! Array of Consolas bold type glyph descriptions */
const font_glyph_desc consolas_bold_glyph_dsc[] =
{
	{.width_px = 3, .offset = 0},	/*ASCII: 0021 (!)*/
	{.width_px = 5, .offset = 16},	/*ASCII: 002c (,)*/
	{.width_px = 4, .offset = 32},	/*ASCII: 002e (.)*/
	{.width_px = 6, .offset = 48},	/*ASCII: 003f (?)*/
	{.width_px = 8, .offset = 64},	/*ASCII: 0041 (A)*/
	{.width_px = 8, .offset = 80},	/*ASCII: 0042 (B)*/
	{.width_px = 7, .offset = 96},	/*ASCII: 0043 (C)*/
	{.width_px = 8, .offset = 112}, /*ASCII: 0044 (D)*/
	{.width_px = 6, .offset = 128}, /*ASCII: 0045 (E)*/
	{.width_px = 6, .offset = 144}, /*ASCII: 0046 (F)*/
	{.width_px = 8, .offset = 160}, /*ASCII: 0047 (G)*/
	{.width_px = 8, .offset = 176}, /*ASCII: 0048 (H)*/
	{.width_px = 6, .offset = 192}, /*ASCII: 0049 (I)*/
	{.width_px = 6, .offset = 208}, /*ASCII: 004a (J)*/
	{.width_px = 8, .offset = 224}, /*ASCII: 004b (K)*/
	{.width_px = 6, .offset = 240}, /*ASCII: 004c (L)*/
	{.width_px = 8, .offset = 256}, /*ASCII: 004d (M)*/
	{.width_px = 8, .offset = 272}, /*ASCII: 004e (N)*/
	{.width_px = 8, .offset = 288}, /*ASCII: 004f (O)*/
	{.width_px = 8, .offset = 304}, /*ASCII: 0050 (P)*/
	{.width_px = 8, .offset = 320}, /*ASCII: 0051 (Q)*/
	{.width_px = 8, .offset = 336}, /*ASCII: 0052 (R)*/
	{.width_px = 7, .offset = 352}, /*ASCII: 0053 (S)*/
	{.width_px = 8, .offset = 368}, /*ASCII: 0054 (T)*/
	{.width_px = 8, .offset = 384}, /*ASCII: 0055 (U)*/
	{.width_px = 8, .offset = 400}, /*ASCII: 0056 (V)*/
	{.width_px = 8, .offset = 416}, /*ASCII: 0057 (W)*/
	{.width_px = 8, .offset = 432}, /*ASCII: 0058 (X)*/
	{.width_px = 8, .offset = 448}, /*ASCII: 0059 (Y)*/
	{.width_px = 7, .offset = 464}, /*ASCII: 005a (Z)*/
	{.width_px = 7, .offset = 480}, /*ASCII: 0061 (a)*/
	{.width_px = 8, .offset = 496}, /*ASCII: 0062 (b)*/
	{.width_px = 7, .offset = 512}, /*ASCII: 0063 (c)*/
	{.width_px = 7, .offset = 528}, /*ASCII: 0064 (d)*/
	{.width_px = 7, .offset = 544}, /*ASCII: 0065 (e)*/
	{.width_px = 8, .offset = 560}, /*ASCII: 0066 (f)*/
	{.width_px = 8, .offset = 576}, /*ASCII: 0067 (g)*/
	{.width_px = 7, .offset = 592}, /*ASCII: 0068 (h)*/
	{.width_px = 7, .offset = 608}, /*ASCII: 0069 (i)*/
	{.width_px = 7, .offset = 624}, /*ASCII: 006a (j)*/
	{.width_px = 7, .offset = 640}, /*ASCII: 006b (k)*/
	{.width_px = 7, .offset = 656}, /*ASCII: 006c (l)*/
	{.width_px = 8, .offset = 672}, /*ASCII: 006d (m)*/
	{.width_px = 7, .offset = 688}, /*ASCII: 006e (n)*/
	{.width_px = 8, .offset = 704}, /*ASCII: 006f (o)*/
	{.width_px = 8, .offset = 720}, /*ASCII: 0070 (p)*/
	{.width_px = 7, .offset = 736}, /*ASCII: 0071 (q)*/
	{.width_px = 7, .offset = 752}, /*ASCII: 0072 (r)*/
	{.width_px = 6, .offset = 768}, /*ASCII: 0073 (s)*/
	{.width_px = 7, .offset = 784}, /*ASCII: 0074 (t)*/
	{.width_px = 7, .offset = 800}, /*ASCII: 0075 (u)*/
	{.width_px = 8, .offset = 816}, /*ASCII: 0076 (v)*/
	{.width_px = 8, .offset = 832}, /*ASCII: 0077 (w)*/
	{.width_px = 8, .offset = 848}, /*ASCII: 0078 (x)*/
	{.width_px = 8, .offset = 864}, /*ASCII: 0079 (y)*/
	{.width_px = 6, .offset = 880}, /*ASCII: 007a (z)*/
};

/*! Array of Consolas cursive type glyph descriptions */
const font_glyph_desc consolas_cursive_glyph_dsc[] =
{
	{.width_px = 5, .offset = 0},	 /*ASCII: 0021 (!)*/
	{.width_px = 5, .offset = 16},	 /*ASCII: 002c (,)*/
	{.width_px = 3, .offset = 32},	 /*ASCII: 002e (.)*/
	{.width_px = 6, .offset = 48},	 /*ASCII: 003f (?)*/
	{.width_px = 8, .offset = 64},	 /*ASCII: 0041 (A)*/
	{.width_px = 9, .offset = 80},	 /*ASCII: 0042 (B)*/
	{.width_px = 9, .offset = 112},	 /*ASCII: 0043 (C)*/
	{.width_px = 9, .offset = 144},	 /*ASCII: 0044 (D)*/
	{.width_px = 9, .offset = 176},	 /*ASCII: 0045 (E)*/
	{.width_px = 9, .offset = 208},	 /*ASCII: 0046 (F)*/
	{.width_px = 9, .offset = 240},	 /*ASCII: 0047 (G)*/
	{.width_px = 10, .offset = 272}, /*ASCII: 0048 (H)*/
	{.width_px = 9, .offset = 304},	 /*ASCII: 0049 (I)*/
	{.width_px = 9, .offset = 336},	 /*ASCII: 004a (J)*/
	{.width_px = 10, .offset = 368}, /*ASCII: 004b (K)*/
	{.width_px = 7, .offset = 400},	 /*ASCII: 004c (L)*/
	{.width_px = 10, .offset = 416}, /*ASCII: 004d (M)*/
	{.width_px = 10, .offset = 448}, /*ASCII: 004e (N)*/
	{.width_px = 9, .offset = 480},	 /*ASCII: 004f (O)*/
	{.width_px = 9, .offset = 512},	 /*ASCII: 0050 (P)*/
	{.width_px = 9, .offset = 544},	 /*ASCII: 0051 (Q)*/
	{.width_px = 9, .offset = 576},	 /*ASCII: 0052 (R)*/
	{.width_px = 9, .offset = 608},	 /*ASCII: 0053 (S)*/
	{.width_px = 9, .offset = 640},	 /*ASCII: 0054 (T)*/
	{.width_px = 10, .offset = 672}, /*ASCII: 0055 (U)*/
	{.width_px = 9, .offset = 704},	 /*ASCII: 0056 (V)*/
	{.width_px = 10, .offset = 736}, /*ASCII: 0057 (W)*/
	{.width_px = 10, .offset = 768}, /*ASCII: 0058 (X)*/
	{.width_px = 9, .offset = 800},	 /*ASCII: 0059 (Y)*/
	{.width_px = 9, .offset = 832},	 /*ASCII: 005a (Z)*/
	{.width_px = 9, .offset = 864},	 /*ASCII: 0061 (a)*/
	{.width_px = 8, .offset = 896},	 /*ASCII: 0062 (b)*/
	{.width_px = 7, .offset = 912},	 /*ASCII: 0063 (c)*/
	{.width_px = 9, .offset = 928},	 /*ASCII: 0064 (d)*/
	{.width_px = 8, .offset = 960},	 /*ASCII: 0065 (e)*/
	{.width_px = 10, .offset = 976}, /*ASCII: 0066 (f)*/
	{.width_px = 9, .offset = 1008}, /*ASCII: 0067 (g)*/
	{.width_px = 8, .offset = 1040}, /*ASCII: 0068 (h)*/
	{.width_px = 7, .offset = 1056}, /*ASCII: 0069 (i)*/
	{.width_px = 8, .offset = 1072}, /*ASCII: 006a (j)*/
	{.width_px = 8, .offset = 1088}, /*ASCII: 006b (k)*/
	{.width_px = 7, .offset = 1104}, /*ASCII: 006c (l)*/
	{.width_px = 9, .offset = 1120}, /*ASCII: 006d (m)*/
	{.width_px = 8, .offset = 1152}, /*ASCII: 006e (n)*/
	{.width_px = 9, .offset = 1168}, /*ASCII: 006f (o)*/
	{.width_px = 9, .offset = 1200}, /*ASCII: 0070 (p)*/
	{.width_px = 9, .offset = 1232}, /*ASCII: 0071 (q)*/
	{.width_px = 9, .offset = 1264}, /*ASCII: 0072 (r)*/
	{.width_px = 8, .offset = 1296}, /*ASCII: 0073 (s)*/
	{.width_px = 8, .offset = 1312}, /*ASCII: 0074 (t)*/
	{.width_px = 9, .offset = 1328}, /*ASCII: 0075 (u)*/
	{.width_px = 8, .offset = 1360}, /*ASCII: 0076 (v)*/
	{.width_px = 9, .offset = 1376}, /*ASCII: 0077 (w)*/
	{.width_px = 9, .offset = 1408}, /*ASCII: 0078 (x)*/
	{.width_px = 9, .offset = 1440}, /*ASCII: 0079 (y)*/
	{.width_px = 9, .offset = 1472}, /*ASCII: 007a (z)*/
};
