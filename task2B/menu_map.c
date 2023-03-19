#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char my_get(char c);
char cprt(char c);
char encrypt(char c);
char decrypt(char c);
char xprt(char c);

char *map(char *array, int array_length, char (*f)(char))
{
  char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
  /* TODO: Complete during task 2.a */
  for (int i = 0; i < array_length; i++)
  {
    mapped_array[i] = f(array[i]);
  }

  return mapped_array;
}

int main(int argc, char **argv)
{
  int base_len = 5;
  char arr1[base_len];
  char *arr2 = map(arr1, base_len, my_get);
  char *arr3 = map(arr2, base_len, cprt);
  char *arr4 = map(arr3, base_len, xprt);
  char *arr5 = map(arr4, base_len, encrypt);
  char *arr6 = map(arr5, base_len, decrypt);
  free(arr2);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
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