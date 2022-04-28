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

/* DEFINES ******************************/
#define LINE_CMD_ID 1   /*!< line command ID */
/* ENUMS ******************************/

/* STRUCTS ******************************/

/*! struct for storing command data front layer to use in logic layer */
typedef struct
{
  int8_t ID;  /*!< ID for command type */
  /*! struct for storing line-command arguments */
  struct line
  {
    uint16_t x1;        /*!< first x coordinate */
    uint16_t y1;        /*!< first y coordinate */
    uint16_t x2;        /*!< second x coordinate */
    uint16_t y2;        /*!< second y coordinate */
    uint8_t color;      /*!< line color (8-bit color value) */
    uint8_t weight;     /*!< weight (thickness) of line in px */
  };
} COMMAND;

/* EXTERN VARIABLES ******************************/

/* PROTOTYPES ******************************/

 
 #endif // PARSER_H_
 