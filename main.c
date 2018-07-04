#include "Headers.h"

void main(){

  sock = connectsock("127.0.0.1", "3001", "tcp");
  
  //Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);
  send(sock,GET,1500,0);
  printf("Get\n");
  while(1)
  {
    //Receving
    recv(sock, msg,sizeof(msg),0); 

    if(seg_nr == total && total !=0){
      printf("Exiting...");
      break;
    }
    //Check for MPD
    if(msg[2]=='D'){
      printf("%s\n",msg);
      total = GetNum(msg);
      printf("%d\n",total); 
    }

    //Check for DWN
    if(msg[2]=='N'){
      printf("%s\n",msg);
      seg_nr = GetNum(msg);
      seg_nr = seg_nr+1;
      sprintf(GET, "GET 6 %d",seg_nr);
      printf("Getting Seg %d\n",seg_nr);
      send(sock,GET,1500,0);
    }
  
  }
    
}


