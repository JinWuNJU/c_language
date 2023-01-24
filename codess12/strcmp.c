#include<stdio.h>
#include<string.h>
int main(){
    char *a[100];
    strcpy(a[1],"ddddd");
    //scanf("%s",a[1]);
    puts(a[1]);
    // if(strcmp(a[1],"asdfghjkl")){
    //     printf("No");
    // }else{
    //     printf("Yes");
    // }
    char cat[100]="6789";
    char s[100]="12345";
   // a[1]=s;
    strcat(s,cat);
    a[1]=s;
    char *pp=a[1]+3;
    puts(pp);
    puts(a[1]);
    return 0;
}