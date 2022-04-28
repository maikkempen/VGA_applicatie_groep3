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
  ERR_SYNTAX_COMMAND = 0,   /*!< unknown command */
  ERR_SYNTAX_NUMARGS,       /*!< wrong number of arguments for specified command */
  ERR_SYNTAX_VALUE_OOR     /*!< numeric value out of range (> 16 bits) */
} ERR_SYNTAX;

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/


#endif /* ERRORHANDLER_H_ */
