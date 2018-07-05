#include <math.h>
int select_rep(double mean,double buffer,int total,int mdp[],double bref,int N_rep){
    int rep;
    double supposed_rep;
    double firstdifference,seconddifference;
    supposed_rep = (mean/((double)total))*(buffer +2-bref);
    printf("mean is %d\n",total);
    if(supposed_rep<=0){
        rep = 1;
    }
    else{
        rep = 1;
        for(int i =1;i< N_rep;i++){
            firstdifference = supposed_rep - mdp[i];
            seconddifference = supposed_rep - mdp[i+1];
            if(firstdifference >=0 && firstdifference < seconddifference){
                rep++;
                break;
            }
            else{
                rep++;
            }
            
        }
    }
    return rep;
}