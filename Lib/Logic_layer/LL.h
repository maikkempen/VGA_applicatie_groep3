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
#include "IO_layer_Lib/IO_func.h"
#include "Parser/parser.h"
/* DEFINES ******************************/
#define AMOUNTOFCOLORS	 17		/*!< amount of colors that are recognized */

typedef struct command COMMAND;
/* ENUMS ******************************/

/* STRUCTS ******************************/

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
uint8_t LL_textToColor(char *text);
uint8_t LL_executeCommand(COMMAND *c, uint8_t last_place);
