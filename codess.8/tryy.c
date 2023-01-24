#include<stdio.h>
#include<string.h>
int main(){
    char s[5];
   // scanf("%s",s);
   gets(s);
    int len=strlen(s);
    printf("%d",len);
    return 0;
}