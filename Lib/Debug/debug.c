/**
  ******************************************************************************
  * @file    debug.c
  * @author  Mike
  * @brief	 Provides debugging with levels.
  ******************************************************************************
  */

#include "debug.h"

#ifdef ENABLE_DEBUG
/**
  * @brief  Sets the prefix for the type of debug output requested.
  * @param  level The level of debug info
  * @param  tmp_debug buffer to place level prefix in
  */
void debug_selprefix(int level, char *tmp_debug){
	if(level == 1){
		strcat(tmp_debug, "DEBUG");
	}
	if(level == 2){
		strcat(tmp_debug, "INFO");
	}
	if(level == 3){
		strcat(tmp_debug, "WARN");
	}
	if(level == 4){
		strcat(tmp_debug, "ERROR");
	}
	if(level == 5){
		strcat(tmp_debug, "FATAL");
	}
}

/**
  * @brief  Prints the level and the text
  * @note	DBL_DEBUG 1 for debug output like values and str
  * 		DBL_INFO  2 for informational text
  * 		DBL_WARN  3 for warning that occour but can be auto resolved
  * 		DBL_ERR	  4 for errors that can be compiled but will break the functionality of the function
  * 		DBL_FATAL 5 for fatal program wont work
  * @param  level The level of debug info
  * @param  text The text that is to be printed to the console
  */
void debug_print(int level, const char *text){
	if(level <= DBL){
		char tmp_debug[1000]="";
		debug_selprefix(level, tmp_debug);
		strcat(tmp_debug,":\t");
		strcat(tmp_debug,text);
		strcat(tmp_debug,"\r\n");
		HAL_UART_Transmit_IT(&huart2, (uint8_t*) tmp_debug, strlen(tmp_debug));
		HAL_Delay(100);
	}
}

/**
  * @brief  Prints the level and the text with arguments
  * @note	DBL_DEBUG 1 for debug output like values and str
  * 		DBL_INFO  2 for informational text
  * 		DBL_WARN  3 for warning that occour but can be auto resolved
  * 		DBL_ERR	  4 for errors that can be compiled but will break the functionality of the function
  * 		DBL_FATAL 5 for fatal program wont work
  * @param  level The level of debug info
  * @param  text The text that is to be printed to the console
  * @param 	... list of arguments
  */
void debug_printf(int level, const char *text, ...){
	if(level <= DBL){
		char tmp_debug[1000]="";
		debug_selprefix(level, tmp_debug);
		strcat(tmp_debug,":\t");
		size_t len = strlen(tmp_debug);
		va_list arglist;
		va_start(arglist, text);
		vsnprintf(tmp_debug + len, 1000 - len, text, arglist);
		va_end(arglist);
		strcat(tmp_debug,"\r\n");
		HAL_UART_Transmit_IT(&huart2, (uint8_t*) tmp_debug, strlen(tmp_debug));
		HAL_Delay(100);
	}
}


#endif
