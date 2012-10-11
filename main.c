#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "command.h"
#include "flags.h"
#include "database.h"
#include "category.h"

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
		case FUNC_CREATE_DB:
			return database_create(cmd->args[0]);
		case FUNC_CREATE_CAT:
			return category_create(cmd->args[0], cmd->args[1]);
		default:
			fprintf(stderr, "Error: No operation with the ID %d found.\n", cmd->func);
			return -1;
	};
}

void set_command_arg(struct Command *cmd, int index, char *value) {
	cmd->args[index] = value;
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
		if(!strcmp(argv[i], FLAG_DEBUG)) {
			DEBUG_MODE = 1;
		}

		// Now check for the sub routine to be executed
		if(!strcmp(argv[i], "status")) {
			cmd->func = FUNC_STATUS;
		}

		if(!strcmp(argv[i], "create")) {
			if(argv[i + 1] != NULL) {
				set_command_arg(cmd, 0, argv[i + 1]);
				if(argv[i + 2] != NULL) {
					set_command_arg(cmd, 1, argv[i + 2]);
					if(argv[i + 3] != NULL) {
						set_command_arg(cmd, 2, argv[i + 2]);
					} else {
						cmd->func = FUNC_CREATE_CAT;
					}
				} else {
					cmd->func = FUNC_CREATE_DB;
				}
			} else {
				fprintf(stderr, "Program usage: \
						bim create [db] [¢at] \
						[item] \n");
			}
		}
	}

	if(DEBUG_MODE)
		printf("Validating operation...[#%d]\n", cmd->func);

	if(validate_operation(cmd))
		print_usage();
		

	return EXIT_SUCCESS;
}
