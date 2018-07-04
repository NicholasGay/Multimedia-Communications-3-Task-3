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

    //Check if all Segments downloaded
    if(seg_nr == total && total !=0){
      printf("Exiting...\n");
      break;
    }

    //Check for MES
    if(msg[2] == 'S'){
      printf("%s\n",msg);
      MESinfo(msg,&buffer,&mean);
      printf("%f\n",buffer);
      printf("%f\n",mean);
    }

    //Check for MPD
    if(msg[2]=='D'){
      printf("%s\n",msg);
      N_rep = M2int(msg,mdp) -1;
      total = mdp[0];
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


