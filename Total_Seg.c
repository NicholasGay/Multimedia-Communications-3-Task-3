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

int M2int(char msg[],int m[]){
    int i =4;
    int index = 0;
    char temp[10];
    int tempi;
    while(msg[i] != '\0'){
      
      tempi = 0;
      while(msg[i] != ' ' && msg[i] != '\0'){
        
        temp[tempi] = msg[i];
        tempi++;
        i++;
      }
      i++;
      m[index] = atoi(temp);
      index++;
    }
    m[index] = 0;
    return index;
  
}

