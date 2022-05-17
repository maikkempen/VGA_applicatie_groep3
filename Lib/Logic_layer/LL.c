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
  * @brief  converts text into color.
  * @param  text color with text see colortext array for reference.
  * @retval returns a 8-bit color code.
  */
uint8_t LL_textToColor(char *text)
{
	uint8_t color;
	int i = 0;
	char colortext[AMOUNTOFCOLORS][20] = {{"zwart"}, {"blauw"},{"lichtblauw"},
										 {"groen"}, {"lichtgroen"}, {"cyaan"},
										 {"lichtcyaan"}, {"rood"}, {"lichtrood"},
										 {"magenta"}, {"lichtmagenta"}, {"bruin"},
										 {"geel"}, {"grijs"}, {"wit"}, {"roze"}};
	for(i=0;i<AMOUNTOFCOLORS;i++){
		if(strstr(text, colortext[i]) != NULL) //check which color it is
		{
			switch(i){ //index of array. assigns a color to the index
			case 0:
				color = VGA_COL_BLACK; break;
			case 1:
				color = VGA_COL_BLUE; break;
			case 2:
				color = VGA_COL_LIGHT_BLUE; break;
			case 3:
				color = VGA_COL_GREEN; break;
			case 4:
				color = VGA_COL_LIGHT_GREEN; break;
			case 5:
				color = VGA_COL_CYAN; break;
			case 6:
				color = VGA_COL_LIGHT_CYAN; break;
			case 7:
				color = VGA_COL_RED; break;
			case 8:
				color = VGA_COL_LIGHT_RED; break;
			case 9:
				color = VGA_COL_MAGENTA; break;
			case 10:
				color = VGA_COL_LIGHT_MAGENTA; break;
			case 11:
				color = VGA_COL_BROWN; break;
			case 12:
				color = VGA_COL_YELLOW; break;
			case 13:
				color = VGA_COL_GRAY; break;
			case 14:
				color = VGA_COL_WHITE; break;
			case 15:
				color = VGA_COL_PINK; break;
			default:
				return 1;
			}
		}
	}
	if(i == 16) return 1;
	return color;
}

/**
  * @brief  Reads command from struct and select which function to run. stops when type = -1
  * @param  struct command c struct with info of commmand see @ref "file with struct".
  * @param  last_place from where in the command struct to execute. return value from parser_receiveData
  * @retval err error with error code @ref LL.h.
  */
uint8_t LL_executeCommand(COMMAND *c, uint8_t last_place)
{
	uint8_t err = 0;
	int i = last_place;
	uint8_t repeat_amount = 0;
	uint8_t repeat_start = 0;
	while(c[i].ID != -1 && i<MAX_CMDS){		//set in parser so we know when we're at the last message
		switch(c[i].ID)
		{
		case LINE_CMD_ID:
			//lne function
			err |= IO_drawLine(c[i].line.x1, c[i].line.y1, c[i].line.x2, c[i].line.y2,
							  LL_textToColor(c[i].line.color), c[i].line.weight);
			break;

		case RECTANGLE_CMD_ID:
			//rectangle function
			err = IO_drawRectangle(c[i].rectangle.x_lup, c[i].rectangle.y_lup, c[i].rectangle.width,
							 	   c[i].rectangle.height, LL_textToColor(c[i].rectangle.color), c[i].rectangle.edge);
			break;

		case TEXT_CMD_ID:
			//text function
			IO_drawText(c[i].text.x, c[i].text.y, LL_textToColor(c[i].text.color), c[i].text.text, c[i].text.fontname, c[i].text.fontsize, c[i].text.fontstyle);
			break;

		case BITMAP_CMD_ID:
			//bitmap function
			err = IO_drawBitmap(c[i].bitmap.nr, c[i].bitmap.x_lup, c[i].bitmap.y_lup,
						 	 	LL_textToColor(c[i].bitmap.color));
			break;

		case CLEARSCREEN_CMD_ID:
			//clearscreen function
			err = IO_clearScreen(LL_textToColor(c[i].clearscreen.color));
			break;

		case WAIT_CMD_ID:
			//wacht function
			HAL_Delay(c[i].wait.msecs);
			break;

		case REPEAT_CMD_ID:
			//repeat function
			if(repeat_start == FALSE){ 		//checks if it has been initiated
				repeat_amount = 0;
				i = i-(c[i].repeat.amount+1); 	//sets the index back to the wanted repeating functions
				repeat_start = TRUE; 		//sets flag high because its initiated
				repeat_amount++;
			} else if(repeat_start == TRUE){
				if(repeat_amount >= c[i].repeat.times){ //if repeat times has been reached continue
					repeat_start = FALSE;				  //with the other commands
				} else {								  //else repeat
					i = i-(c[i].repeat.amount+1);
					repeat_start = TRUE;
					repeat_amount++;
				}
			}
			break;

		case CIRCLE_CMD_ID:
			//circle function
			err = IO_drawCircle(c[i].circle.x, c[i].circle.y,
						 		c[i].circle.radius, LL_textToColor(c[i].circle.color));
			break;

		case FIGURE_CMD_ID:
			//figuur
			break;
		default:
			err = ERROR_UNKOWN_COMMAND;
			break;
		}
		i++;
	}
	return err;
}
