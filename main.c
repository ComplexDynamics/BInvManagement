#include <stdio.h>
#include <stdlib.h>

/*
* File name: "main.c"
* Description: The starting point for the program.
* Author: Alex Egger
* Date: 09.10.12
* Version: 0.1
* License: Creative Commons Attribution-NonCommercial 3.0 Unported License.
*/

int DEBUG_MODE = 0;

int main(int argc, char *argv[]) {
	int i;		

	for(i = 1; i < argc; i++) {
		if(!strcmp(argv[i], "-d")) {
			DEBUG_MODE = 1;
		}
	}

	return 0;
}


