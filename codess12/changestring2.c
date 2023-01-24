#include<stdio.h>
#include<string.h>
void swap(char **a,char **b){
    char *p=*a;
    *a=*b;
    *b=p;
}
int main(){
    char a[12][200];
    char *s[120];
    s[1]="brazss";
    s[2]="Aentinaaaaaa";
    strcpy(a[1],s[1]);
    strcpy(a[2],s[2]);
    puts(a[2]);
    //swap(&s[1],&s[2]);
    // char *pp=s[1];
    // s[1]=s[2];
    // s[2]=pp;
    int len1=strlen(a[1]);
    int len2=strlen(a[2]);
    a[1][len1]='\0';
    a[2][len2]='\0';
    swap(&a[1],&a[2]);
    puts(a[1]);
    puts(a[2]);
    return 0;
}