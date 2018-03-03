
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mystr.h"
#define WORDL 20
#define LINEL 80

int main() {
  char line[LINEL+1], word[WORDL+1];
  fgets(line, LINEL+1, stdin);
  line[strlen(line)-1] = '\0';

  char *linePtr = line;
  char *wordPtr = word;
  remove_dup_blanks(linePtr);
  printf("Line: %s\n", linePtr);

  while(*linePtr != '\0'|| linePtr != NULL) {
    linePtr = next_word(linePtr, wordPtr);
    printf("%s\n", wordPtr);
  }
  return EXIT_SUCCESS;
}//end of main

char *next_word(char *str, char *word){
  while(*str != ' ' && *str != '\0'){
    *word = *str;
    str++;
    word++;
  }
  *word = '\0';
  str++;
  return str;
}

void remove_dup_blanks(char *str){
  char *temp = str;
  while(*temp != '\0') {
    if(*temp != ' '){
      *str = *temp;
    }else{
      while(*(temp+1) == ' '){
        temp++;
      }
      *str = *temp;
    }
    temp++;
    str++;
  }
  *str = '\0';
}
