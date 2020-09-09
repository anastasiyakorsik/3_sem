#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void GenerateString(int n, char* string) {

    int place_of_copy = pow(2, n-1);
    strncpy(string + place_of_copy, string + 0, pow(2,n-1) - 1);
    int place_of_letter = pow(2,n-1) - 1;
    string[place_of_letter] = 'a' + (n-1);
    for (int i = 0; i < pow(2,n) - 1; ++i) {
        printf("%c", string[i]);
    }
    printf("\n");
}

int main()
{
    char *ar_str;
    int n_str = 0, mem_str = 0;
    scanf("%d", &mem_str);
    scanf("%d", &n_str);
    ar_str = (char*) malloc(mem_str * sizeof(char));

    for (int i = 0; i < n_str; ++i)
    {
        ar_str[i] = 0;
    }

    for (int j = 1; j <= n_str; ++j)
    {
        GenerateString(j, ar_str);
    }


    return 0;
}