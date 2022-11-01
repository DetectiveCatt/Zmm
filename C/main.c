#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "str.c"

void lex(string uwu, int len, string *tokens){
  char ch;

  string tokarr[2048];
  int tokarrptr = 0;
  
  string tmp = string_create(NULL);
  
  for (int i =0; i<string_length(uwu); i++){
    ch = uwu[i];
    string_add_char(&tmp, ch);
    if (ch == '<'){
      string_remove(tmp, string_length(tmp)-1, string_length(tmp)); // pop a character off tmp
      tokarr[tokarrptr] = tmp; // append tmp
      tokarrptr++; // add onto the current token pointer
      string_remove(tmp, 0, string_length(tmp)); // clear tmp
      printf("%s", tmp);
    }
    if (ch == '>'){
      string_remove(tmp, string_length(tmp)-1, string_length(tmp)); // pop a character off tmp
      tokarr[tokarrptr] = tmp; // append tmp
      tokarrptr++; // add onto the current token pointer
      string_remove(tmp, 0, string_length(tmp)); // clear tmp
      printf("%s", tmp);
    }
    if (ch == ' '){
      string_remove(tmp, string_length(tmp)-1, string_length(tmp)); // pop a character off tmp
      tokarr[tokarrptr] = tmp; // append tmp
      tokarrptr++; // add onto the current token pointer
      string_remove(tmp, 0, string_length(tmp)); // clear tmp
      printf("%s", tmp);
    }
    if (ch == ';'){
      string_remove(tmp, string_length(tmp)-1, string_length(tmp)); // pop a character off tmp
      tokarr[tokarrptr] = tmp; // append tmp
      tokarrptr++; // add onto the current token pointer
      string_remove(tmp, 0, string_length(tmp)); // clear tmp
      printf("%s", tmp);
    }
  }
  
  len = tokarrptr;
  tokens = tokarr;
  return;

}
int main()
{
    FILE *file = fopen("code.zmm", "r");
    string abc = string_create(NULL);
    char c;
    while (1){
        c = fgetc(file);
        if (c==EOF){
          break;
        }
        string_add_char(&abc, c);
        
    }
    fclose(file);
    int tokenslen;
    string tokens[2048];
    lex(abc, tokenslen, tokens);
    for (int i = 0; i<tokenslen; i++){
      printf("%s", tokens[i]);
    }
    return 0;
}