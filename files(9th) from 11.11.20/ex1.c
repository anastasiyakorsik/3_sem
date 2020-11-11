#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main()
{

	struct stat *buf;
	struct dirent *dp;
	DIR *dir = NULL;

    dir = opendir(".");

    if (dir == NULL)
        return (-1);

    while ((dp = readdir(dir)) != NULL) {

        printf("%s\n", dp->d_name);

        if (stat(dp->d_name, buf) == 0) {

	        if (S_ISDIR(buf->st_mode)) { 

	        	printf("directory %s/\n", dp->d_name);

	            } else if( S_ISREG(buf->st_mode) ) {

	            	printf("file %s size %lld bytes\n", dp->d_name, buf->st_size);
	            }

	    	} else return(-1);

    }
    
    (void)closedir(dir);

	return 0;
}