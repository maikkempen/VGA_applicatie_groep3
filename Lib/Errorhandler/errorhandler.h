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
  ERROR_SYNTAX_CMD 		= 1 << 0,   /*!< Syntax error in type command */
  ERROR_TOO_FEW_ARGS 	= 1 << 1,   /*!< Too few arguments for command */
  ERROR_TOO_MANY_ARGS 	= 1 << 2,   /*!< Too many arguments for command  */
  ERROR_UNKOWN_COMMAND 	= 1 << 3,	/*!< unkown command */
  ERROR_OUT_OF_BOUNDS 	= 1 << 4,	/*!< x or y is out of bounds */
  ERROR_COLOR_SYNTAX	= 1 << 5,	/*!< Syntax error in the color */
  ERROR_INVALID_VALUE	= 1 << 6,	/*!< invalid value */
} ERR_SYNTAX;

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
void errorhandler_returnError(uint8_t err);

#endif /* ERRORHANDLER_H_ */
