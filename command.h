#ifndef _COMMAND_H_
#define _COMMAND_H_

/*
* File name: "command.h"
* Description:
* Author: Alex Egger
* Date: 10.10.12
* Version: 0.1
* License: Creative Commons Attribution-NonCommercial 3.0 Unported License.
*/

#define FUNC_STATUS 1
#define FUNC_CREATE_DB 2
#define FUNC_CREATE_CAT 3
#define FUNC_CREATE_ITEM 4


struct Command {
	int func;
	char *args[8];
};

#endif
