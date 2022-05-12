/**
  ******************************************************************************
  * @file    LL.c
  * @author  Mike
  * @brief   Controls incomming commands and goes trough all the commands that
  * are send.
  ******************************************************************************
  */
#include "LL.h"

/**
  * @brief  Reads command from struct and select which function to run. stops when type = -1
  * @param  struct command c struct with info of commmand see @ref "file with struct".
  * @retval err error with error code @ref LL.h.
  */
uint8_t LL_executeCommand(COMMAND c){
	uint8_t err = 0;
	int i = 0;
	while(c[i].ID != -1){
		switch(c[i].type)
		{
		case LINE_CMD_ID:
			//lijnfunctie
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
			break;

		case REPEAT_CMD_ID:
			//herhaal
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
