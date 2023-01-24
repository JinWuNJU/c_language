#include<stdio.h>
int f(int n,int count){
    if(count>5){
        return 1;
    }else if(count<=5&&n%5!=1){
        return 0;

    }else if(count <= 5 && n % 5 == 1){
        return f(n*4/5,count+1);
    }
}
int main(){
    for(int i=1;;i++){
        if(f(i,1)==1){
            printf("%d",i);
            break;
        }
    }
    return 0;
}