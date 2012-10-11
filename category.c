#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "category.h"

int category_create(char *db_name, char *name) {
	FILE* file;
	char *dir_name = malloc(strlen("database/") + strlen(db_name));
	char *file_name = malloc(strlen(dir_name) + strlen(name) + strlen(".cat"));
	struct stat st;

	strcpy(dir_name, "database/");
	strcat(dir_name, db_name);

	if(stat(dir_name, &st))
		return 1;

	strcpy(file_name, dir_name);
	strcat(file_name, name);
	strcat(file_name, ".cat");

	file = fopen(file_name, "a");

	/*free(dir_name);
	free(file_name); */
	if(file != NULL) {
		fclose(file);
		return 0;
	}

	return 1;
}
