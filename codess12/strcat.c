#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char **p=malloc(10000);
          for(int i=0;i<10000;i++){
            p[i]=malloc(1000);
          }
    //char *p[100];
    p[1]="abc";
    p[2]="def";
    char q1[20]="qwert";
    char q2[20]="lkjhg";
    char s[200][200];
    strcpy(s[1],p[1]);
    strcat(s[1],q2);
    // puts(q1);
    // puts(q2);
   // strcpy(p[1],q1);
    //strcpy(p[1],q2);
    puts(s[1]);
    return 0;
}