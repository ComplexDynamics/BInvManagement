#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "database.h"

/*
* File name: "database.c"
* Description:
* Author: Alex Egger
* Date: 11.10.12
* Version: 0.1
* License: Creative Commons Attribution-NonCommerical 3.0 Unported License.
*/

int database_create(char *name) {
	char *dir_name = malloc(strlen("database/") + strlen(name));

	strcpy(dir_name, "database/");
	strcat(dir_name, name);

	struct stat st;
	if(stat("database/", &st))
		mkdir("database/", S_IRWXU);

	if(stat(dir_name, &st)) {
		mkdir(dir_name, S_IRWXU);
		return 0;
	}

	free(dir_name);

	return 1;
}
