#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.c"

void init_vec(string* arr, int arrlen){
  for (int i=0; i<arrlen; i++){
    arr[i] = string_create(NULL);
  }
}
void split()
int main(void)
{
    int token = 1024, tokenlen = 255;
    char *example_string = "This is an <example>";
    char ptrarr[token][tokenlen];
    string arr[10];
    init_vec(arr, 10);
    string_add(&arr[1], "Hello mateys\n");
    printf("%s", arr[1]);
    string_remove(arr[1], 0, string_length(arr[1]));
    strncat(arr[2], "HEWLO", 6);
    printf("%s", arr[2]);
    return 0;
}