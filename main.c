#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"

/*
* File name: "main.c"
* Description: The starting point for the program.
* Author: Alex Egger
* Date: 09.10.12
* Version: 0.1
* License: Creative Commons Attribution-NonCommercial 3.0 Unported License.
*/

int DEBUG_MODE = 0;

int validate_operation(struct Command *cmd) {
	switch(cmd->func) {
		case FUNC_STATUS:
			printf("Status OK.\n");
			return 0;
		default:
			fprintf(stderr, "Error: No operation with the ID %d found.\n", cmd->func);
			return -1;
	};
}

void print_usage() {
	printf("Program usage: bim [flags] [operation] [...]\n");
	return;
}

int main(int argc, char *argv[]) {
	int i;
	struct Command *cmd = malloc(sizeof(struct Command));		

	// Evalute the commandline arguments
	for(i = 1; i < argc; i++) {

		// First check for special flags
		if(!strcmp(argv[i], "-d")) {
			DEBUG_MODE = 1;
		}

		// Now check for the sub routine to be executed
		if(!strcmp(argv[i], "status")) {
			cmd->func = FUNC_STATUS;
		}
	}

	if(cmd->func == 0)
		cmd->func = FUNC_UNKNOWN;

	if(DEBUG_MODE)
		printf("Validating operation...[#%d]\n", cmd->func);

	if(validate_operation(cmd))
		print_usage();
		

	return EXIT_SUCCESS;
}
