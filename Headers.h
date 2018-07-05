#include <stdio.h>
#include <stdlib.h>
#include "connectsock.c"
#include "Test.c"
#include "File.c"
#include "Total_Seg.c"
#include "Selecting_Rate.c"

int sock,N_rep;

//For Rate calculation
double current_buffer,total_error,error;
double bref = 5.0;
double mean = 0;
int totalrate = 0;

//Commands
char command[1500] = "CONNECT 6.0 http://kufstein2.lmt.ei.tum.de/short1/";
char GET[1500] = "GET 1 1";
int rep;

//Receive
char msg[1500];

//Comparisions
int total = 0;
int seg_nr = 0;

//Info
int mdp[10];
