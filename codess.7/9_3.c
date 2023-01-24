#include<stdio.h>
#include<math.h> 
#define eps 1e-6
double f(double x){
    return (1.0/4.0)*x*x-sin(x);
}
double root(double a,double b){
    if(fabs (f((a+b)/2.0))<=eps){
        return (a+b)/2.0;
    }else if(fabs (f((a+b)/2.0))>eps&&f(a)*f((a+b)/2.0)<0){
        return root(a,(a+b)/2.0);
    }else if(fabs (f((a+b)/2.0))>eps&&f(b)*f((a+b)/2.0)<0){
        return root((a+b)/2.0,b);
    }

}
int main(){
    double a=0,b=0;
    while(1){
        scanf("%lf%lf",&a,&b);
         if(f(a)*f(b)<0){
            break;
        }else if(f(a)*f(b)==0){
            if(f(a)==0){
                printf("%lf",a);
            }else{
                printf("%lf",b);
            }goto loop;
        }
    }printf("%lf",root(a,b));
  loop:  return 0;
}