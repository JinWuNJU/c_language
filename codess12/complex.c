#include<stdio.h>
#include<string.h>
int main(){
    char *s[1000];
    s[1]="abcde";
    s[2]="lgjirkf";
    char p[1000][100];
    strcpy(p[1],s[1]);
    puts(p[1]);
    scanf("%s",p[2]);
    puts(p[2]);
}