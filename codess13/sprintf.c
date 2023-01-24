#include<stdio.h>
#include<string.h>
int main(){
    // char s[50][50];
    // char *name="weerrrtt";
    // sprintf(s[1],name);
    // sprintf(s[2],"qwert");
    // strcat(s[2],s[1]);
    // char *a[100];
    // a[1]=s[1];
    // a[2]=s[2];
    // char *p=a[1];
    // a[1]=a[2];
    // a[2]=p;
    // puts(a[1]);
    // puts(a[2]);
    // puts(s[1]);
    // puts(s[2]);
    char s[50][50];
    int a=100;
    int b=200;
    sprintf(s[1],"%d",a);
    sprintf(s[2],"%d",b);
    char temp[100];
    sprintf(temp,s[1]);
    sprintf(s[1],s[2]);
    sprintf(s[2],temp);
    puts(s[1]);
    int c=-1;
    if(c){
        printf("here");
    }
    return 0;
}