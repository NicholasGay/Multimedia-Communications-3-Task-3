#include <math.h>
#define kp 0.1
#define ki 0.01
int select_rep(double mean,double current_buffer,int total,int mdp[],int N_rep,double error_total,double error,double bref){

    int rep;
    double est_rate,target_rate,output,diff1,diff2;
    
    error = current_buffer - bref;
    est_rate = (mean/((double)total))*1000;
    output = (kp*error+ki*error_total)/bref; 
    target_rate = (output+1)*est_rate;
    rep = 1;
    for(int i = 1; i<N_rep;i++){
        diff1 = target_rate-mdp[i];
        diff2 = target_rate-mdp[i+1];
        if(diff2<diff1 && diff2 >= 0){
            rep++;
        }
        else{
            break;
        }
    }
   
    return rep;
}