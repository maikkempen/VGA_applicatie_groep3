/**
  ******************************************************************************
  * @file      parser.h
  * @author    Max Besseling, Maik Kempen
  * @brief     header file for parser.c
  ******************************************************************************
  */

#ifndef PARSER_H_
#define PARSER_H_
 
 /* INCLUDES ******************************/
#include "main.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* DEFINES ******************************/
#define LINE_CMD_ID 0  			/*!< line command ID */
#define RECTANGLE_CMD_ID 1  	/*!< rectangle command ID */
#define TEXT_CMD_ID 2  			/*!< text command ID */
#define BITMAP_CMD_ID 3  		/*!< bitmap command ID */
#define CLEARSCREEN_CMD_ID 4  	/*!< clearscreen command ID */
#define WAIT_CMD_ID 5  			/*!< wait command ID */
#define REPEAT_CMD_ID 6  		/*!< repeat command ID */
#define CIRCLE_CMD_ID 7  		/*!< circle command ID */
#define FIGURE_CMD_ID 8  		/*!< figure command ID */
#define TOWER_CMD_ID 9  		/*!< tower command ID */
#define UNKOWN_CMD_ID 10  		/*!< tower command ID */

#define MAX_STR_LENGTH	 100
/* ENUMS ******************************/

/* STRUCTS ******************************/

/*! struct for storing command data front layer to use in logic layer */
typedef struct
{
  int8_t ID;  /*!< ID for command type */
  /*! struct for storing line-command arguments */
  struct line_data
  {
    uint16_t x1;        				/*!< first x coordinate */
    uint16_t y1;        				/*!< first y coordinate */
    uint16_t x2;        				/*!< second x coordinate */
    uint16_t y2;        				/*!< second y coordinate */
    char color[MAX_STR_LENGTH];      	/*!< line color (8-bit color value) */
    uint8_t weight;     				/*!< weight (thickness) of line in px */
  } line;
} COMMAND;

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/
uint8_t parser_recdata(char *buff);
 
 #endif // PARSER_H_
 
