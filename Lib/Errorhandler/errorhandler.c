/**
  ******************************************************************************
  * @file      errorhandler.c
  * @author    Maik Kempen
  * @author	   Mike Oudshoorn
  * @brief     Error handler for detection of syntax, logic
  *            and hardware errors and notification specified to users
  *            (programmer, end-user)
  ******************************************************************************
  */

#include "errorhandler.h"
#include "Debug/debug.h"
/**
  * @brief	prints out error
  * @param	err error value
  */
void errorhandler_returnError(uint16_t err)
{
	if(err & ERROR_SYNTAX_CMD)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x WRONG SYNTAX\n", ERROR_SYNTAX_CMD);
	}
	if(err & ERROR_TOO_FEW_ARGS)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x TOO FEW ARGS\n", ERROR_TOO_FEW_ARGS);
	}
	if(err & ERROR_TOO_MANY_ARGS)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x TOO MANY ARGS\n", ERROR_TOO_MANY_ARGS);
	}
	if(err & ERROR_OUT_OF_BOUNDS)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x OUT OF BOUNDS\n", ERROR_OUT_OF_BOUNDS);
	}
	if(err & ERROR_COLOR_SYNTAX)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x COLOR SYNTAX\n", ERROR_COLOR_SYNTAX);
	}
	if(err & ERROR_INVALID_VALUE)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x INVALID VALUE\n", ERROR_INVALID_VALUE);
	}
	if(err & ERROR_TEXT_UNKNOWN_FONT)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x UNKNOWN TEXT FONT\n", ERROR_TEXT_UNKNOWN_FONT);
	}
	if(err & ERROR_TEXT_UNKNOWN_SYMBOL)
	{
		debug_printf(DBL_ERROR, "CODE: 0x%02x UNKNOWN TEXT SYMBOL ENTERED\n", ERROR_TEXT_UNKNOWN_SYMBOL);
	}
	if(err & WARNING_TEXT_OUT_OF_BOUNDS)
	{
		debug_printf(DBL_WARN, "CODE: 0x%02x TEXT SYMBOLS OUT OF BOUNDS\n", WARNING_TEXT_OUT_OF_BOUNDS);
	}
	if(err == 0){
		debug_printf(DBL_INFO, "OK\n");
	}
}
 
