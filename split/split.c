#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileSize(FILE *file) {
    int result = 0;

    fseek(file, 0,  SEEK_END);// Set file's pointer to the end
    result = ftell(file);// Put the amount of read bytes into the 'result' (sizeof(char) = 1 byte)
    rewind(file);// Set file's pointer at the beginning

    return result;
}

int Split(char* string, char* delimiters, char** tokens)
{
	char* arSplit = strtok(string, delimiters);
	int i = 0;
    for (i = 0; arSplit != NULL; ++i)
    {
        tokens[i] = arSplit;
        arSplit = strtok(NULL, delimiters);
    }
    return i;

}

int main()
{
    FILE *f1, *f2;

	char *arStr = NULL, *arDel = NULL;

    char **tokens = NULL;

    if ((f1 = fopen("../split_arStr.txt", "r")) == NULL) { // Open the file with the input string
        printf("Can't open file f1!\n");
        return -1;
    }

    int f1_size = fileSize(f1);
    arStr = (char*) calloc(f1_size, sizeof(char));
    fread(arStr, sizeof(char), f1_size, f1);
    //fwrite(arStr, sizeof(char), f1_size, stdout);
	fclose(f1);

    if ((f2 = fopen("../split_arDel.txt", "r")) == NULL) {
        printf("Can't open file f1!\n");
        return -1;
    }

    int f2_size = fileSize(f2);
    arDel = (char*) calloc(f2_size, sizeof(char));
    fread(arDel, sizeof(char), f2_size, f2);
    //fwrite(arDel, sizeof(char), f2_size, stdout);
    fclose(f2);

    tokens = (char**) calloc(f1_size, sizeof(char*));
	int CountTokens = Split(arStr, arDel, tokens);

    printf("Кол-во слов: %d\n", CountTokens);
    for (int i = 0; i < CountTokens; ++i) {
        printf("%s\n", tokens[i]);
    }

    free(tokens);
    free(arStr);
    free(arDel);

	return 0;
}


