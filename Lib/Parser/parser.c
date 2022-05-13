/**
  ******************************************************************************
  * @file      parser.c
  * @author    Max Besseling, Mike Oudshoorn
  * @brief     Front layer parser to analyze and store command syntax to be used
  *            by logic layer
  ******************************************************************************
  */

#include "parser.h"

/**
  * @brief  Checks where the character is if the character occurrences multiple times.
  * @param  s input string to be searched
  * @param  c searching character
  * @param  n number of time the character appears where you want to point to
  * @retval pointer to n counted character
  */
char* parser_nthStrchr(const char* s, int c, int n)
{
    int c_count;
    char* num_ptr;	//points to the last found character

    for (c_count=1,num_ptr=strchr(s,c);				//looks for the character and increases the pointer if it found the
    	 num_ptr != NULL && c_count < n && c!=0;	//character until the n is reached
         c_count++)
    {
    	 num_ptr = strchr(num_ptr+1, c);			//increases from the last found character
    }

    return num_ptr; //returns pointer pointing to final location
}

/**
  * @brief  Reads a str from a specific location and converts it into a value
  * @param 	cmd full command
  * @param  location the location where the data is that you want to extract
  * @retval value read
  */
uint16_t parser_readValue(char *cmd, uint8_t location)
{
	char *ptr; 				//pointer for pointing to the selected location
	char value_char[VALUE_STR]; 	//for storing temp string data
	memset(value_char,0,VALUE_STR); //sets it to zeros
	int i = 0;
	ptr = parser_nthStrchr(cmd, DIVIDER_CHAR,location);//gets location
	ptr = ptr + 2;	//increases to get to the beginning of the string
	while(*ptr != DIVIDER_CHAR && *ptr != END_OF_TEXT)	//extracts string and puts it into the temp string
	{											//goes until the end of text character or the beginning of the next location
		value_char[i] = *ptr;
		i++;
		ptr++;
		if(i>(VALUE_STR-1)) break;
	}
	return atoi(value_char); //converts string into int
}
/**
  * @brief  Reads a str from a specific location
  * @param 	cmd full command
  * @param  character data array to stored the extracted string
  * @param  location the location where the data is that you want to extract
  * @retval counted length
  */
uint8_t parser_readText(char *cmd,char *character,uint8_t location)
{
	char *ptr; //pointer for pointing to the selected location
	memset(character, 0, MAX_STR_LENGTH);
	int i = 0;
	ptr = parser_nthStrchr(cmd, DIVIDER_CHAR,location); //gets location
	ptr = ptr + 2;							   //increases to get to the beginning of the string
	while(*ptr != DIVIDER_CHAR && *ptr != END_OF_TEXT)  //extracts string and puts it into the data array
	{										   //goes until the end of text character or the beginning of the next location
		character[i] = *ptr;
		i++;
		ptr++;
		if(i>MAX_STR_LENGTH) break;
	}
	return i;  //returns length
}
uint8_t check_amount_args(char *cmd,uint8_t amount)
{
	char *ptr;
	ptr = parser_nthStrchr(cmd, DIVIDER_CHAR,amount);
	if(ptr != NULL){
		ptr = parser_nthStrchr(cmd, DIVIDER_CHAR,amount+1);
	} else {
		return ERROR_TOO_FEW_ARGS;
	}

	if(ptr != NULL){
		return ERROR_TOO_MANY_ARGS;
	}
	return 0;
};
/**
  * @brief  chooses and fills the right data structure from a string with right format
  * @param 	cmd full command
  * @param  type the type of command (example: line=0,rectangle=1,etc.)
  * @retval the filled in data struct
  */
COMMAND parser_fillStruct(char *cmd, uint8_t type, uint8_t err)
{
	COMMAND s_cmd; //create a struct to be filled
	int i;
	memset(&s_cmd, 0, sizeof(s_cmd)); //reset mem to all zeros
	char character[MAX_STR_LENGTH];
	uint8_t len = 0;
	switch(type) //check which type of command was found
	{
		case LINE_CMD_ID:
			err &= check_amount_args(cmd,6);
			if(err != 0) break;
			s_cmd.ID = LINE_CMD_ID;
			s_cmd.line.x1 = parser_readValue(cmd,1); //gets value from str at a location and puts it into the struct
			s_cmd.line.y1 = parser_readValue(cmd,2);
			s_cmd.line.x2 = parser_readValue(cmd,3);
			s_cmd.line.y2 = parser_readValue(cmd,4);
			s_cmd.line.weight = parser_readValue(cmd,6);

			len = parser_readText(cmd,character,5); //gets str and len at a location
			for(i=0;i<len;i++) s_cmd.line.color[i] = character[i]; //puts it into the struct
			break;

		case RECTANGLE_CMD_ID:
			err &= check_amount_args(cmd,6);
			if(err != 0) break;
			s_cmd.ID = RECTANGLE_CMD_ID;
			s_cmd.rectangle.x_lup = parser_readValue(cmd,1);
			s_cmd.rectangle.y_lup = parser_readValue(cmd,2);
			s_cmd.rectangle.width = parser_readValue(cmd,3);
			s_cmd.rectangle.height = parser_readValue(cmd,4);
			s_cmd.rectangle.edge = parser_readValue(cmd,6);

			len = parser_readText(cmd,character,5);
			for(i=0;i<len;i++) s_cmd.rectangle.color[i] = character[i];
			break;

		case TEXT_CMD_ID:
			err &= check_amount_args(cmd,7);
			if(err != 0) break;
			s_cmd.ID = TEXT_CMD_ID;
			s_cmd.text.x = parser_readValue(cmd,1);
			s_cmd.text.y = parser_readValue(cmd,2);
			s_cmd.text.fontsize = parser_readValue(cmd,6);

			len = parser_readText(cmd,character,3);
			for(i=0;i<len;i++) s_cmd.text.color[i] = character[i];
			len = parser_readText(cmd,character,4);
			for(i=0;i<len;i++) s_cmd.text.text[i] = character[i];
			len = parser_readText(cmd,character,5);
			for(i=0;i<len;i++) s_cmd.text.fontname[i] = character[i];
			len = parser_readText(cmd,character,7);
			for(i=0;i<len;i++) s_cmd.text.fontstyle[i] = character[i];
			break;

		case BITMAP_CMD_ID:
			err &= check_amount_args(cmd,3);
			if(err != 0) break;
			s_cmd.ID = BITMAP_CMD_ID;
			s_cmd.bitmap.nr = parser_readValue(cmd,1);
			s_cmd.bitmap.x_lup = parser_readValue(cmd,2);
			s_cmd.bitmap.y_lup = parser_readValue(cmd,3);

			len = parser_readText(cmd,character,4);
			for(i=0;i<len;i++) s_cmd.bitmap.color[i] = character[i];
			break;

		case CLEARSCREEN_CMD_ID:
			err &= check_amount_args(cmd,1);
			if(err != 0) break;
			s_cmd.ID = CLEARSCREEN_CMD_ID;
			len = parser_readText(cmd,character,1);
			for(i=0;i<len;i++) s_cmd.clearscreen.color[i] = character[i];
			break;
		case WAIT_CMD_ID:
			err &= check_amount_args(cmd,1);
			if(err != 0) break;
			s_cmd.ID = WAIT_CMD_ID;
			s_cmd.wait.msecs = parser_readValue(cmd,1);
			break;

		case REPEAT_CMD_ID:
			err &= check_amount_args(cmd,2);
			if(err != 0) break;
			s_cmd.ID = REPEAT_CMD_ID;
			s_cmd.repeat.amount = parser_readValue(cmd,1);
			s_cmd.repeat.times = parser_readValue(cmd,2);
			break;

		case CIRCLE_CMD_ID:
			err &= check_amount_args(cmd,4);
			if(err != 0) break;
			s_cmd.ID = CIRCLE_CMD_ID;
			s_cmd.circle.x = parser_readValue(cmd,1);
			s_cmd.circle.y = parser_readValue(cmd,2);
			s_cmd.circle.radius = parser_readValue(cmd,3);

			len = parser_readText(cmd,character,4);
			for(i=0;i<len;i++) s_cmd.circle.color[i] = character[i];
			break;

		case FIGURE_CMD_ID:
			err &= check_amount_args(cmd,11);
			if(err != 0) break;
			s_cmd.ID = FIGURE_CMD_ID;
			s_cmd.figure.x1 = parser_readValue(cmd,1);
			s_cmd.figure.y1 = parser_readValue(cmd,2);
			s_cmd.figure.x2 = parser_readValue(cmd,3);
			s_cmd.figure.y2 = parser_readValue(cmd,4);
			s_cmd.figure.x3 = parser_readValue(cmd,5);
			s_cmd.figure.y3 = parser_readValue(cmd,6);
			s_cmd.figure.x4 = parser_readValue(cmd,7);
			s_cmd.figure.y4 = parser_readValue(cmd,8);
			s_cmd.figure.x5 = parser_readValue(cmd,9);
			s_cmd.figure.y5 = parser_readValue(cmd,10);

			len = parser_readText(cmd,character,11);
			for(i=0;i<len;i++) s_cmd.figure.color[i] = character[i];
			break;

		case TOWER_CMD_ID:
			err &= check_amount_args(cmd,5);
			if(err != 0) break;
			s_cmd.ID = TOWER_CMD_ID;
			s_cmd.tower.x = parser_readValue(cmd,1);
			s_cmd.tower.y = parser_readValue(cmd,2);
			s_cmd.tower.size = parser_readValue(cmd,3);

			len = parser_readText(cmd,character,4);
			for(i=0;i<len;i++) s_cmd.tower.color1[i] = character[i];
			len = parser_readText(cmd,character,5);
			for(i=0;i<len;i++) s_cmd.tower.color2[i] = character[i];
			break;

		default:
			err &= ERROR_UNKOWN_COMMAND; //should never happen
			break;
	}
	return s_cmd;	//returns struct
}

/**
  * @brief  receives a buffer with all the incomming commands.
  * 		Then divides them into single commands and parse
  * 		them into the data structure
  * @param 	buff buffer with all the insend commands
  * @param  commands data structure type where parsed data is stored
  * @param 	amount of commands incomming
  * @retval error handling
  */
uint8_t parser_receiveData(char *buff, COMMAND *commands,uint8_t last_place,uint8_t amount)
{
	int i = 0;
	int j = 0;
	static int k = 0;
	uint8_t err = 0;
	char cmd[150];
	char *pbuf;	//to increase to the next command string.
	//array for easly testing types with strstr function
	char types[AMOUNTOFCMDS][20]= {{"lijn"},
								   {"rechthoek"},
								   {"tekst"},
								   {"bitmap"},
								   {"clearscherm"},
								   {"wacht"},
								   {"herhaal"},
								   {"cirkel"},
								   {"figuur"},
								   {"toren"}};

	memset(cmd, 0, 150);										//reset cmd buffer
	pbuf = &*buff;												//point to the start of the big data buffer
	if((k + amount) > AMOUNTOFCMDS)
	{
		k = 0;
	}
	last_place = k;
	while(*pbuf != END_OF_TEXT){								//extract the first command
		cmd[i] = *pbuf;
		pbuf++;
		i++;
	}
	cmd[i] = END_OF_TEXT;										//add "end of text" character for making the end recognizable
	i=0;
	while(TRUE)
	{
		if(strstr(cmd, types[i]) != NULL) 						//check which type with the types array
		{
			commands[k] = parser_fillStruct(cmd, i, err); 			//if type match select type struct and fill it
			if(err != 0) return err;
			k++;
			j++;
			if(k>MAX_CMDS)k=0;
			break;
		}
		i++;

		if(i>AMOUNTOFCMDS){ 									//should never happen only by human error (wrong syntax)
			err &= ERROR_SYNTAX_CMD;
			break;
		};
	}
	if(amount != 1) 											//if multiple commands are present check them otherwise skip
	{
		while(TRUE)
		{
			pbuf = parser_nthStrchr(buff, END_OF_TEXT, j); 		//look for the next command
			i = 0;
			pbuf++;												//remove "end of text" from the beginning of the string
			if(*pbuf == '\0') break;							//if '\0' terminate because end is reached
			while(*pbuf != END_OF_TEXT)							//extract command from the big buffer
			{
				cmd[i] = *pbuf;
				pbuf++;
				i++;
			}
			cmd[i] = END_OF_TEXT;								//add "end of text" character for making the end recognizable
			i = 0;
			while(TRUE)
			{
				if(strstr(cmd, types[i]) != NULL)				//check which type with the types array
				{
					commands[k] = parser_fillStruct(cmd, i, err);	//if type match select type struct and fill it
					if(err != 0) return err;
					k++;
					j++;
					if(k>MAX_CMDS)k=0;							//if max is reached reset to the beginning
					break;
				}
				if(i>AMOUNTOFCMDS){ 									//should never happen only by human error (wrong syntax)
					err &= ERROR_SYNTAX_CMD;
					return err;
				};
				i++;

				if(i>AMOUNTOFCMDS) break;
			}
		}

	} else if (amount == 0){									//if no amount given return an error
		err++;
	}
	commands[k].ID = -1;									//indicator for end of commands
	return err;
}





