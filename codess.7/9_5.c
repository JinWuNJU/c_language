#include<stdio.h>
int main(){
    char ch[100]={'\0'};
    gets(ch);
    int i;
    for(i=0;;i++){
        if(ch[i]=='\0'){
            break;
        }
    }int count = 0;
    for(int j=0;j<=i-1;j++){
        if(ch[j]>=65&&ch[j]<=90){
            ch[j]+=32;
        }
    }for(int j=0;j<i;j++){
        if(ch[j]==97||ch[j]==101||ch[j]==105||ch[j]==111||ch[j]==117){
            count++;
        }
    }for(int j=0;j<i;j++){
        printf("%c",ch[j]);
    }
    printf("\t%d",count);
   
    return 0;
}