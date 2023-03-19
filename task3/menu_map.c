#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fun_desc
{
    char *name;
    char (*fun)(char);
};

char my_get(char c);
char cprt(char c);
char encrypt(char c);
char decrypt(char c);
char xprt(char c);
char *map(char *array, int array_length, char (*f)(char));

int main(int argc, char **argv)
{
    struct fun_desc menu[] = {{"Get String", my_get}, {"Print String", cprt}, {"Encrypt", encrypt}, {"Decrypt", decrypt}, {"Print Hex", xprt}, {NULL, NULL}};

    // Formmated menu
    printf("Please choose a function (ctrl^D for exit):\n");
    for (int i = 0; i < 5; i++)
        printf("%d)  %s\n", i, menu[i].name);
    printf("Option : ");

    char buffer[256];
    char *line;
    char *carray = (char *)malloc(5);

    while ((line = fgets(buffer, 256, stdin)) != NULL)
    {
        printf("\n");
        int prompt = line[0] - 48;
        if (0 <= prompt && prompt <= 4 && line[2] == '\0')
        {
            printf("Within bounds\n");
            carray = map(carray, 5, menu[prompt].fun);
            printf("Done.\n\n");
        }
        else
        {
            printf("Not within bounds\n");
            exit(0);
        }

        // Formmated menu
        printf("Please choose a function (ctrl^D for exit):\n");
        for (int i = 0; i < 5; i++)
            printf("%d)  %s\n", i, menu[i].name);
        printf("Option: ");
    }

    return 0;
}

char *map(char *array, int array_length, char (*f)(char))
{
    char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
    for (int i = 0; i < array_length; i++)
        mapped_array[i] = f(array[i]);

    return mapped_array;
}

char my_get(char c)
{
    return fgetc(stdin);
}

char cprt(char c)
{
    printf("%c\n", 0x20 <= c && c <= 0x7e ? c : '.');
    return c;
}

char encrypt(char c)
{
    return 0x20 <= c && c <= 0x7e ? c + 1 : c;
}

char decrypt(char c)
{
    return 0x20 <= c && c <= 0x7e ? c - 1 : c;
}

char xprt(char c)
{

    printf(0x20 <= c && c <= 0x7e ? "%x\n" : ".\n", c);
    return c;
}