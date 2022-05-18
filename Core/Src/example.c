/**
  ******************************************************************************
  * @file    example.c
  * @author  Mike Oudshoorn
  * @author  Maik Kempen
  * @brief	 Example file for user to use library
  ******************************************************************************
  */

#include "example.h"

/**
  * @brief  Function to implement library (VGA_CLI), can be used by end-user
  */
void example(void)
{

	COMMAND commands[MAX_CMDS];
	uint8_t last_place = 0;
	uint16_t err;

	while (1)
	{

		if (input.command_execute_flag == TRUE)
		{
			err = parser_receiveData(input.line_rx_buffer, commands, &last_place, input.cmd_amount);
			if (err)
			{
				// return error code to user
				errorhandler_returnError(err);
			}
			else
			{
				err = LL_executeCommand(commands, last_place);
				errorhandler_returnError(err);
			}
			input.cmd_amount = 0;
			input.command_execute_flag = FALSE;
		}
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
}
