/**
  ******************************************************************************
  * @file      parser.c
  * @author    Max Besseling
  * @brief     Front layer parser to analyze and store command syntax to be used
  *            by logic layer
  ******************************************************************************
  */

#include "parser.h"

COMMAND commands[20];

char* parser_nthStrchr(const char* s, int c, int n)
{
    int c_count;
    char* nth_ptr;

    for (c_count=1,nth_ptr=strchr(s,c);
         nth_ptr != NULL && c_count < n && c!=0;
         c_count++)
    {
         nth_ptr = strchr(nth_ptr+1, c);
    }

    return nth_ptr;
}

uint16_t parser_readValue(char *cmd, uint8_t location){
	char *ptr;
	char value_char[3];
	int i = 0;
	ptr = parser_nthStrchr(cmd, ',',location);
	ptr = ptr + 2;
	while(*ptr != ','){
		value_char[i] = *ptr;
		i++;
		ptr++;
		if(i>2) break;
	}
	return atoi(value_char);
}

uint8_t parser_readText(char *cmd,char *character,uint8_t location){
	char *ptr;
	memset(character, 0, MAX_STR_LENGTH);
	int i = 0;
	ptr = parser_nthStrchr(cmd, ',',location);
	ptr = ptr + 2;
	while(*ptr != ','){
		character[i] = *ptr;
		i++;
		ptr++;
		if(i>MAX_STR_LENGTH) break;
	}
	return i;
}

COMMAND parser_fillStruct(char *cmd, uint8_t type){
	COMMAND s_cmd;
	int i;
	memset(&s_cmd, 0, sizeof(s_cmd));
	char character[MAX_STR_LENGTH];
	uint8_t len = 0;
	switch(type)
	{
		case LINE_CMD_ID:
			s_cmd.ID = LINE_CMD_ID;
			s_cmd.line.x1 = parser_readValue(cmd,1);
			s_cmd.line.y1 = parser_readValue(cmd,2);
			s_cmd.line.x2 = parser_readValue(cmd,3);
			s_cmd.line.y2 = parser_readValue(cmd,4);

			len = parser_readText(cmd,character,5);
			for(i=0;i<len;i++) s_cmd.line.color[i] = character[i];

			s_cmd.line.weight = parser_readValue(cmd,6);
			break;
		case RECTANGLE_CMD_ID:
			s_cmd.ID = RECTANGLE_CMD_ID;
			break;
		case TEXT_CMD_ID:
			s_cmd.ID = TEXT_CMD_ID;
			break;
		case BITMAP_CMD_ID:
			s_cmd.ID = BITMAP_CMD_ID;
			break;
		case CLEARSCREEN_CMD_ID:
			s_cmd.ID = CLEARSCREEN_CMD_ID;
			break;
		case WAIT_CMD_ID:
			s_cmd.ID = WAIT_CMD_ID;
			break;
		case REPEAT_CMD_ID:
			s_cmd.ID = REPEAT_CMD_ID;
			break;
		case CIRCLE_CMD_ID:
			s_cmd.ID = CIRCLE_CMD_ID;
			break;
		case FIGURE_CMD_ID:
			s_cmd.ID = FIGURE_CMD_ID;
			break;
		case TOWER_CMD_ID:
			s_cmd.ID = BITMAP_CMD_ID;
			break;
		default:
			s_cmd.ID = UNKOWN_CMD_ID;
			break;
	}
	return s_cmd;
}

uint8_t parser_recData(char *buff){
	int i = 0;
	char cmd[100];
	char *pbuf;
	char *ptbuf;
	char types[AMOUNTOFCMDS][20]= {{"lijn"},
								   {"rechthoek"},
								   {"tekst"},
								   {"bitmap"},
								   {"clearscherm"},
								   {"wacht"},
								   {"herhaal"},
								   {"cirkel"},
								   {"figuur"}};
	memset(cmd, 0, 100);
	ptbuf = &*buff;
	pbuf = strchr(&*ptbuf, 3);

	while(*ptbuf != *pbuf){
		cmd[i] = *ptbuf;
		ptbuf++;
		i++;
	}
	cmd[i] = 3;
	i++;

	i = 0;
	while(TRUE)
	{
		if(strstr(cmd, types[i]) != NULL)
		{
			commands[0] = parser_fill_struct(cmd, i);
		}
		i++;

		if(i<AMOUNTOFCMDS) break;
	}
	return 1;
}





