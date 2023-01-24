#include<stdio.h> 
void f(int *a){
        *a=7;
    }
int main(){
    
    int b=0;
    f(&b);
    printf("%d",b);
    return 0;
}