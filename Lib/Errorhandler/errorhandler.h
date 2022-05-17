/**
  ******************************************************************************
  * @file      errorhandler.h
  * @author    Maik Kempen
  * @brief     header file for errorhandler.c
  ******************************************************************************
  */

#ifndef ERRORHANDLER_H_
#define ERRORHANDLER_H_

/* INCLUDES ******************************/
#include "main.h"

/* DEFINES ******************************/

/* ENUMS ******************************/

/*! Enum for types of syntax error from command line */
typedef enum 
{
  ERROR_SYNTAX_CMD 		= 1 << 0,   /*!< unknown command */
  ERROR_TOO_FEW_ARGS 	= 1 << 1,       /*!< wrong number of arguments for specified command */
  ERROR_TOO_MANY_ARGS 	= 1 << 2,     /*!< numeric value out of range (> 16 bits) */
  ERROR_UNKOWN_COMMAND 	= 1 << 3,
  ERROR_OUT_OF_BOUNDS 	= 1 << 4,
  ERROR_COLOR_SYNTAX	= 1 << 5,
  ERROR_INVALID_VALUE	= 1 << 6,
} ERR_SYNTAX;

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
void errorhandler_returnError(uint8_t err);

#endif /* ERRORHANDLER_H_ */
