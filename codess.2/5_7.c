#include<stdio.h>
int main(){
    int P,E,A,R;
    int x,y,z;
    for(P=1;P<=9;P++){
        for(E=0;E<=9;E++){
            for(A=1;A<=9;A++){
                for(R=0;R<=9;R++){
                x=P*1000+E*100+A*10+R;
                y=A*100+R*10+A;
                z=P*100+E*10+A;
                if(z==x-y){
                    printf("P=%d,E=%d,A=%d,R=%d",P,E,A,R);
                }
                }
            }
        }
    }
    return 0;
    }




































































































































































































































































   