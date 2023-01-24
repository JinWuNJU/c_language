#include<stdio.h>
void swap(char **s1,char **s2){
    char *z=*s1;
    *s1=*s2;
    *s2=z;
}
int main(){
    char *s[100];
    s[1]="qwertwqdfewwef";
    s[2]="zxcvbcfvvvvvvvvvv";
    char m[100][100];
    sprintf(m[1],s[1]);
    sprintf(m[2],s[2]);
    swap(s+1,s+2);
    // swap(m+1,m+2);
    puts(s[1]);
    puts(m[1]);
    return 0;
}