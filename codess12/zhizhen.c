#include<stdio.h>
#include<stdlib.h>
int main(){
    int a=5,b=8;
    int *p=&a;
    int *q=&b;
    printf("%d %d",*p,*q);
    return 0;
}