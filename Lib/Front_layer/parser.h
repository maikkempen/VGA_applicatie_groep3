/**
 ******************************************************************************
 * @file      parser.h
 * @author    Max Besseling, Maik Kempen, Mike Oudshoorn
 * @brief     header file for parser.c
 ******************************************************************************
 */

#ifndef PARSER_H_
#define PARSER_H_

/* INCLUDES ******************************/
#include "main.h"
#include "Errorhandler/errorhandler.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* DEFINES ******************************/
#define LINE_CMD_ID 0		 /*!< line command ID */
#define RECTANGLE_CMD_ID 1	 /*!< rectangle command ID */
#define TEXT_CMD_ID 2		 /*!< text command ID */
#define BITMAP_CMD_ID 3		 /*!< bitmap command ID */
#define CLEARSCREEN_CMD_ID 4 /*!< clearscreen command ID */
#define WAIT_CMD_ID 5		 /*!< wait command ID */
#define REPEAT_CMD_ID 6		 /*!< repeat command ID */
#define CIRCLE_CMD_ID 7		 /*!< circle command ID */
#define FIGURE_CMD_ID 8		 /*!< figure command ID */
#define TOWER_CMD_ID 9		 /*!< tower command ID */

#define MAX_STR_LENGTH 100 /*!< Max character lenght for parser */
#define MAX_CMDS 35		   /*!< Max amount of CMD keeping stored */
#define AMOUNT_CMDS 9	   /*!< amount of different CMDS */
#define VALUE_STR 4		   /*!< Max string length to convert to int */
#define DIVIDER_CHAR ','   /*!< divider character in commands */

/* ENUMS ******************************/

/* STRUCTS ******************************/

/*! struct for storing command data front layer to use in logic layer */
struct command
{
	int8_t ID; /*!< ID for command type */
	/*! struct for storing line-command arguments */
	struct line_data
	{
		uint16_t x1;				/*!< first x coordinate */
		uint16_t y1;				/*!< first y coordinate */
		uint16_t x2;				/*!< second x coordinate */
		uint16_t y2;				/*!< second y coordinate */
		char color[MAX_STR_LENGTH]; /*!< line color (8-bit color value) */
		uint8_t weight;				/*!< weight (thickness) of line in px */
	} line;

	/*! struct for storing rectangle-command arguments */
	struct rectangle_data
	{
		uint16_t x_lup;				/*!< x coordinate */
		uint16_t y_lup;				/*!< y coordinate */
		uint16_t width;				/*!< width of line in px */
		uint16_t height;			/*!< Height of line in px */
		char color[MAX_STR_LENGTH]; /*!< rectangle color (8-bit color value) */
		uint8_t edge;				/*!< edge around rectangle in px */
	} rectangle;

	/*! struct for storing text-command arguments */
	struct text_data
	{
		uint16_t x;						/*!< x coordinate */
		uint16_t y;						/*!< y coordinate */
		char color[MAX_STR_LENGTH];		/*!< text color (8-bit color value) */
		char text[MAX_STR_LENGTH];		/*!< text */
		char fontname[MAX_STR_LENGTH];	/*!< font type of text */
		uint8_t fontsize;				/*!< fontsize of text standard 1 or 2 */
		char fontstyle[MAX_STR_LENGTH]; /*!< fontstyle of text */
	} text;

	/*! struct for storing bitmap-command arguments */
	struct bitmap_data
	{
		uint16_t nr;				/*!< number of bitmap stored memory in px */
		uint16_t x_lup;				/*!< x coordinate */
		uint16_t y_lup;				/*!< y coordinate */
		char color[MAX_STR_LENGTH]; /*!< text color (8-bit color value) */
	} bitmap;

	/*! struct for storing clearscreen-command arguments */
	struct clearscreen_data
	{
		char color[MAX_STR_LENGTH]; /*!< text color (8-bit color value) */
	} clearscreen;

	/*! struct for storing wait-command arguments */
	struct wait_data
	{
		uint16_t msecs; /*!< msecs for delay */
	} wait;

	/*! struct for storing repeat-command arguments */
	struct repeat_data
	{
		uint16_t amount; /*!< amount of commandos to repeat */
		uint16_t times;	 /*!< amount of times to repeat */
	} repeat;

	/*! struct for storing circle-command arguments */
	struct circle_data
	{
		uint16_t x;					/*!< x coordinate */
		uint16_t y;					/*!< y coordinate */
		uint16_t radius;			/*!< radius of circle in px */
		char color[MAX_STR_LENGTH]; /*!< circle color (8-bit color value) */
	} circle;

	/*! struct for storing figure-command arguments */
	struct figure_data
	{
		uint16_t x1;				/*!< first x coordinate */
		uint16_t y1;				/*!< first y coordinate */
		uint16_t x2;				/*!< second x coordinate */
		uint16_t y2;				/*!< second y coordinate */
		uint16_t x3;				/*!< third x coordinate */
		uint16_t y3;				/*!< third y coordinate */
		uint16_t x4;				/*!< fourth x coordinate */
		uint16_t y4;				/*!< fourth y coordinate */
		uint16_t x5;				/*!< fifth x coordinate */
		uint16_t y5;				/*!< fifth y coordinate */
		char color[MAX_STR_LENGTH]; /*!< figure color (8-bit color value) */
	} figure;
};

typedef struct command COMMAND;

/* EXTERN VARIABLES ******************************/
/* PROTOTYPES ******************************/
char *parser_nthStrchr(const char *s, int c, int n);
uint16_t parser_readValue(char *cmd, uint8_t location);
uint8_t parser_readText(char *cmd, char *character, uint8_t location);
COMMAND parser_fillStruct(char *cmd, uint8_t type, uint16_t *err);
uint16_t parser_receiveData(char *buff, COMMAND *commands, uint8_t *last_place, uint8_t amount);

#endif // PARSER_H_
