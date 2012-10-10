#ifndef _COMMAND_H_
#define _COMMAND_H_

/*
* File name: "command.h"
* Description:
* Author: Alex Egger
* Date: 10.10.12
* Version: 0.1
* License Creative Commons Attribution-NonCommercial 3.0 Unported License.
*/

#define FUNC_UNKNOWN 0
#define FUNC_STATUS 1

struct Command {
	int func;
};

#endif
