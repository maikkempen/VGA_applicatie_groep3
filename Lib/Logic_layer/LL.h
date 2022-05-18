/**
  ******************************************************************************
  * @file    LL.h
  * @author  Mike
  * @brief   Header file for LL.c
  ******************************************************************************
  */

/* INCLUDES ******************************/
#include <stdio.h>
#include "main.h"
#include "IO_layer/IO_func.h"
#include "Front_layer/parser.h"
/* DEFINES ******************************/
#define AMOUNTOFCOLORS	 17		/*!< amount of colors that are recognized */
#define SYNTAX_ERROR_COLOR 0x01 // internal error code
typedef struct command COMMAND;
/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
uint16_t LL_textToColor(char *text);
uint16_t LL_executeCommand(COMMAND *c, uint8_t last_place);
