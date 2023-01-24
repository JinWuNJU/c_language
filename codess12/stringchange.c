#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //char *a[100];
    char **a=malloc(100);
    for(int i=0;i<100;i++){
        *(a+i)=malloc(10);
    }
    
//    char *p=a[1];
//    p=a[2];
//    a[2]=a[1];
    // char *p=a[1];
    // a[1]=a[2];
    // a[2]=p;
    // printf("%s\n%s",a[1],a[2]);
    char **b=malloc(10);
    for(int i=0;i<10;i++){
        *(b+i)=malloc(10);
    }
    //b[1]="111";
   // strcpy(*(b+1),*(a+1));
    *(a+1)="asdfghj";
    strcpy(*(b+1),*(a+1));
    printf("%s",*(b+1));
    return 0;
}