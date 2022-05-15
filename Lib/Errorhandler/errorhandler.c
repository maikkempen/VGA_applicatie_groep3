/**
  ******************************************************************************
  * @file      errorhandler.c
  * @author    Maik Kempen
  * @brief     Error handler for detection of syntax, logic
  *            and hardware errors and notification specified to users
  *            (programmer, end-user)
  ******************************************************************************
  */

#include "errorhandler.h"
#include "Debug/debug.h"

void errorhandler_returnError(uint8_t err){
	if(err & ERROR_SYNTAX_CMD){
		debug_printf(DBL_ERROR, "CODE: 0x%02x WRONG SYNTAX\n",ERROR_SYNTAX_CMD);
	}
	if(err & ERROR_TOO_FEW_ARGS){
		debug_printf(DBL_ERROR, "CODE: 0x%02x TOO FEW ARGS\n",ERROR_TOO_FEW_ARGS);
	}
	if(err & ERROR_TOO_MANY_ARGS){
		debug_printf(DBL_ERROR, "CODE: 0x%02x TOO MANY ARGS\n",ERROR_TOO_MANY_ARGS);
	}
	if(err & ERROR_OUT_OF_BOUNDS){
		debug_printf(DBL_ERROR, "CODE: 0x%02x OUT OF BOUNDS \n",ERROR_OUT_OF_BOUNDS);
	}
	if(err & ERROR_COLOR_SYNTAX){
		debug_printf(DBL_ERROR, "CODE: 0x%02x COLOR SYNTAX\n",ERROR_COLOR_SYNTAX);
	}
}
 
