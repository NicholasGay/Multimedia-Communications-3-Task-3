#include "Headers.h"

void main(){

  sock = connectsock("127.0.0.1", "3001", "tcp");
   
  //Test(sock);       //Testing program
  //int packet = 1;
  send(sock,command,1500,0);
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
      MESinfo(msg,&current_buffer,&mean);
      totalrate++;
    }

    //Check for MPD
    if(msg[2]=='D'){
      printf("%s\n",msg);
      N_rep = M2int(msg,mdp) -1;
      total = mdp[0];
      rep = select_rep(mean,current_buffer,totalrate,mdp,N_rep,total_error,error,bref);
      sprintf(GET, "GET %d 1",rep);
      printf("GET %d 1\n",rep);
      send(sock,GET,1500,0);
    }

    //Check for DWN and Get new
    if(msg[2]=='N'){
      printf("%s\n",msg);
      seg_nr = GetNum(msg);
      seg_nr = seg_nr+1;
    
      //Select Rep
      error = current_buffer -bref;
      total_error += error;
      rep = select_rep(mean,current_buffer,totalrate,mdp,N_rep,total_error,error,bref);
      sprintf(GET, "GET %d %d",rep,seg_nr);
      printf("GET %d %d\n",rep,seg_nr);
      send(sock,GET,1500,0);
      mean = 0;
      totalrate = 0;
  
    }
  
  }
    
}


