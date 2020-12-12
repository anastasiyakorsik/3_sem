#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

const int lng = 256; //max path lenght 
int check = 0; //flag checking existance of the file

int Is_Points(char* name) { //checking '.' in file's name

	if (name[0] == '.' && ((name[1] == '.' && name[2] == '\0') || name[1] == '\0')) //for that the file doesn't link to itself
		return 1;

	return 0;
}

int Descent(char* path, int rec, char* end) { //input arguments: path, deep, file's name

	DIR* cur = opendir(path); //open needed directory

	if (!cur) return errno; //checking if the directory exist

	struct dirent* content;
	struct stat info; //information to check if we are in dir or in file

	while ((content = readdir(cur))) { //readdir returns NULL if no directory

		if (rec == 0) continue; //depth of directory (0 - max depth, go to the next operation)
		
		if (Is_Points(content->d_name)) continue;//if file is okay

		char path_full_name[lng]; //array for full path name
		strcpy(path_full_name, path);
		strcat(path_full_name, "/");
		strcat(path_full_name, content->d_name); //add the next file to full path

		char end_maybe[lng]; //to check if file's names are the same
		strcpy(end_maybe, path);
		strcat(end_maybe, "/");
		strcat(end_maybe, end);

		stat(path_full_name, &info); //put in info the name of our directory to check if its dir or file

		if (S_ISDIR(info.st_mode)) { //if dir
			Descent(path_full_name, rec - 1, end); //continue to go down (rec - 1 -> decreasing depth), end -> file's name
		}
		else if (strncmp(path_full_name, end_maybe, lng) == 0) { //compare, if the same -> print file
			printf("File's location: \n%s\n", path_full_name);
			check++; //flag
		}
	}
}

int main(int argc, char* argv[]) {
	
	char path[lng];
	char end[lng];

	strcpy(path, argv[1]);
	int rec = atoi(argv[2]);
	strcpy(end, argv[3]);

	strcat(path, "/");

	Descent(path, rec, end);

	if (check == 0) printf("Нет такого файла\n");

	return 0;
}