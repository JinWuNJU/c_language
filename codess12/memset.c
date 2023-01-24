#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char **p=malloc(10000);
    for(int i=0;i<10000;i++){
        p[i]=malloc(1000);
    }
    char *q[100];
    char s[100];
    memset(p[1],98,sizeof(p));
    puts(p[1]);
    //putchar('\n');
    q[1]="asdffff";
    q[1]="asd";
  //   memset(q[1],98,sizeof(p));
    q[2]=q[1];
    puts(q[2]);
    //putchar('\n');
    memset(s,99,sizeof(s));
    puts(s);
    int num[200];
    memset(num,1,sizeof(num)/sizeof(num[0]));
    for(int i=0;i<200;i++){
    printf("%d",num[i]);
    }
    return 0;
}