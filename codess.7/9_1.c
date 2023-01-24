#include<stdio.h>
#include<math.h>
long long int power(double x,int y){
    if(y==0){
        return 1;
    }if(y>0){
      return power(x,y-1)*x;  
      
    }if(y<0){
      return  power(x,y+1)/x;
        
    }

}
int main(){
    double n=0;
    scanf("%lf",&n);
    long long h=power(n,7);
    printf("%lld",h);

    return 0;
}