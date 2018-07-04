#include <stdlib.h>

int GetNum(char msg[]){
  char temp[10];
  int num;
  int i=4;
  while(msg[i] != ' '){
    temp[i-4] = msg[i];
    i++;
  }
  num = atoi(temp);

  return num;
}
