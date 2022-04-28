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
uint8_t execute_command(struct commmand c){
	uint8_t err = 0;
	int i = 0;
	while(c[i].type != -1){
		switch(c[i].type)
		{
		case 1:
			//lijnfunctie
			break;
//		case :
//			//rechthoekfunctie
//			break;
//		case :
//			//tekst
//			break;
//		case :
//			//bitmap
//			break;
//		case :
//			//clearscherm
//			break;
//		case :
//			//wacht
//			break;
//		case :
//			//herhaal
//			break;
//		case :
//			//cirkel
//			break;
//		case :
//			//figuur
//			break;
		default:
			err++;
			break;
		}
		i++;
	}
	return err;
}
