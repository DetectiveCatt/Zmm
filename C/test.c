#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void lex(char* uwu){
  char ch;

  char tokarr[2048][255];
  int tokarrptr = 0;

  
  char tmp[255] = {0};
  
  for (int i =0; i<strlen(uwu); i++){
    ch = uwu[i];
    strncat(tmp, &ch, 1); // append character 
    if (ch == '<'){
      tmp[strlen(tmp)-1] = '\0';
      strncpy(tokarr[tokarrptr], tmp, strlen(tmp));
      printf("%s", tokarr[tokarrptr]);
      tokarrptr++; // add onto the current token pointer
      memset(tmp,0,strlen(tmp)); // clear the tmp buffer 
    }
    if (ch == '>'){
      tmp[strlen(tmp)-1] = '\0';
      strncpy(tokarr[tokarrptr], tmp, strlen(tmp));
      printf("%s", tokarr[tokarrptr]);
      tokarrptr++; // add onto the current token pointer
      memset(tmp,0,strlen(tmp)); // clear the tmp buffer 
    }
    if (ch == ' '){
      tmp[strlen(tmp)-1] = '\0';
      strncpy(tokarr[tokarrptr], tmp, strlen(tmp));
      printf("%s", tokarr[tokarrptr]);
      tokarrptr++; // add onto the current token pointer
      memset(tmp,0,strlen(tmp)); // clear the tmp buffer 
    }
    if (ch == ';'){
      tmp[strlen(tmp)-1] = '\0';
      strncpy(tokarr[tokarrptr], tmp, strlen(tmp));
      printf("%s", tokarr[tokarrptr]);
      tokarrptr++; // add onto the current token pointer
      memset(tmp,0,strlen(tmp)); // clear the tmp buffer 
      
    }
  }
  return;

}
int main()
{
    FILE *file = fopen("code.zmm", "r");
    char* abc = {0};
    char c;
    while (1){
        c = fgetc(file);
        if (c==EOF){
          break;
        }
        c+='\0';
        strncat(abc, &c, 2);
    }
    fclose(file);
    lex(abc);
    // for (int i = 0; i<tokarrptr; i++){
    //   printf("%s", tokarr[i]);
    // }
    return 0;
}