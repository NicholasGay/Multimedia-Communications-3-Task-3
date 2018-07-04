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

double MESinfo(char msg[], double *buffer, double *mean){
      int i;
      int tempi;
      char temp1[10];
      char temp2[10];
     
      i =4;
      tempi = 0;
      
      //Getting Mean
      while(msg[i] != ' '){
        temp1[tempi] = msg[i];
        i++;
        tempi++;
      }
      *mean += atof(temp1);
      i++;
      tempi = 0;
     
      while(msg[i] != ' '){
        temp2[tempi] = msg[i];
        i++;
        tempi++;
      }
      *buffer = atof(temp2);


}