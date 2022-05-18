/**
  ******************************************************************************
  * @file	 debug.h
  * @author	 Mike
  * @brief	 Header file for debug.c
  ******************************************************************************
  */

#ifndef DEBUG_H_
#define DEBUG_H_

/* INCLUDES ******************************/
#include <main.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "usart.h"

/* DEFINES ******************************/
#define ENABLE_DEBUG 1	/*!< first x coordinate */

#define DBL_DEBUG	1	/*!< Debug level DEBUG */
#define DBL_INFO	2	/*!< Debug level INFO */
#define DBL_WARN	3	/*!< Debug level WARN */
#define DBL_ERROR	4	/*!< Debug level ERROR */
#define DBL_FATAL	5	/*!< Debug level FATAL */

#define DBL			5	/*!< Set Debug Level */

/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
#ifdef ENABLE_DEBUG

	// Define normal function prototypes

	void debug_print(int level, const char *text);
	void debug_printf(int level, const char *text, ...);
	void debug_selprefix(int level, char *tmp_debug);

#else

	// Define empty inline functions

	inline void debug_print(int level, const char *text)
	{
		return;
	}

	inline void debug_printf(int level, const char *text, ...)
	{
		return;
	}

#endif

#endif /* DEBUG_H_ */

