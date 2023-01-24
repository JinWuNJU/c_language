#include<stdio.h>
#include<stdlib.h>
int main(){
    char *s[200];
    for(int i=0;i<5;i++){
        char *str=malloc(200);
        scanf("%s",str);
        s[i]=str;
        free(str);
    }
    return 0;
}