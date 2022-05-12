/**
  ******************************************************************************
  * @file    LL.c
  * @author  Mike
  * @brief   Controls incomming commands and goes trough all the commands that
  * are send.
  ******************************************************************************
  */
#include "LL.h"

uint8_t LL_textToColor(char *text)
{
	uint8_t color;
	char colortext[15][20] = 	{{"zwart"}, {"blauw"},{"lichtblauw"},
							 {"groen"}, {"lichtgroen"}, {"cyaan"},
							 {"lichtcyaan"}, {"rood"}, {"lichtrood"},
							 {"magenta"}, {"lichtmagenta"}, {"bruin"},
							 {"geel"}, {"grijs"}, {"wit"}, {"paars"},
							 {"roze"}};
	return color;
}

/**
  * @brief  Reads command from struct and select which function to run. stops when type = -1
  * @param  struct command c struct with info of commmand see @ref "file with struct".
  * @retval err error with error code @ref LL.h.
  */
uint8_t LL_executeCommand(COMMAND *c)
{
	uint8_t err = 0;
	int i = 0;
	uint8_t repeat_amount = 0;
	uint8_t repeat_start = 0;
	while(c[i].ID != -1){
		switch(c[i].ID)
		{
		case LINE_CMD_ID:
			//lijnfunctie
			//IO_drawLine(c[i].line.x1, c[i].line.y1, c[i].line.x2, c[i].line.y2, LL_textToColor(c[i].line.color), c[i].line.weight);
			break;

		case RECTANGLE_CMD_ID:
			//rechthoekfunctie
			break;

		case TEXT_CMD_ID:
			//tekst
			break;

		case BITMAP_CMD_ID:
			//bitmap
			break;

		case CLEARSCREEN_CMD_ID:
			//clearscherm
			break;

		case WAIT_CMD_ID:
			//wacht
			//HAL_Delay(COMMAND.wait.msecs);
			break;

		case REPEAT_CMD_ID:
			//herhaal
//			if(repeat_start == FALSE){
//				i-COMMAND.repeat.amount;
//				repeat_start == TRUE;
//				repeat_amount = 0;
//			} else if(repeat_start == TRUE){
//				if(repeat_amount == COMMAND.repeat.times){
//					repeat_start = FALSE;
//				} else {
//					i-COMMAND.repeat.amount;
//					repeat_start == TRUE;
//					repeat_amount++;
//				}
//			}
			break;

		case CIRCLE_CMD_ID:
			//cirkel
			break;

		case FIGURE_CMD_ID:
			//figuur
			break;

		case TOWER_CMD_ID:
			//figuur
			break;
		default:
			err++;
			break;
		}
		i++;
	}
	return err;
}
