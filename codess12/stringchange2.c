#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void changestring(char **m,char **n){
   char *p=*m;
   *m=*n;
   *n=p;
}
void changeint(int *a,int *b){
    int p=*a;
    *a=*b;
    *b=p;
}
void changestring2(char *m,char *n){
    int len1=strlen(m);
    int len2=strlen(n);
    if(len1>len2){
        for(int i=0;i<len2;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }for(int i=len2;i<len1;i++){
            n[i]=m[i];
        }n[len1]='\0';
        m[len2]='\0';
    }else if(len1<len2){
        for(int i=0;i<len1;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }for(int i=len1;i<len2;i++){
            m[i]=n[i];
        }n[len1]='\0';
        m[len2]='\0';
    }else{
        for(int i=0;i<len1;i++){
            char ch;
            ch=m[i];
            m[i]=n[i];
            n[i]=ch;
        }n[len1]='\0';
        m[len2]='\0';
    }
}
int main(){
    char **s=malloc(10);
    for(int i=0;i<10;i++){
        s[i]=malloc(100);
    }
    s[1]="ab";
    s[2]="def";
    changestring(&s[1],&s[2]);
    printf("%s\n%s\n",s[1],s[2]);
    int a=1;
    int b=2;
    changeint(&a,&b);
    printf("%d",a);

    return 0;
}