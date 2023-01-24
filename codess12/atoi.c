#include<stdio.h>
#include<stdlib.h>
//char *p[]只读不可写
int main(){
    int number1 = 123456;
    int number2 = -123456;
    char string[222]="1111111";
    itoa(number1,string,10);
    //printf("%s",string);
    puts(string);
    //putchar('^');
    return 0;
}
/*总结: 1. char *p[] 只可读
           不能用strcpy( p[i] , ......)  
           但是可以直接赋值
           p[1]="aaaaa";
        or char s[]="......";
           p[1]=s;
        or p[1][9]='k';
        or scanf("%s",p[1]);
        2. char p[][];
            不能直接赋值，
            要用strcpy.
            但是可以作为左值
            !!!!!!!!!!
            而且可以用scanf输入！！！！！！
            可以用sprintf(p,"......")来完成赋值！！！！！！
        3. 用malloc
             既能解决赋值，又能strcpy
             但内存占用大，拖慢运行时间
           char **p=malloc(10000);
           for(int i=0;i<10000;i++){
            p[i]=malloc(1000);
           }
           plus:
           不能先 p[1]="abc";
           又     strcpy(p[1],"...");
           是错误的
        4.
           以后操作：
        char *s[1000];
        s[1]=".......";
        .
        .
        .
        char p[1000][100];
        scanf("%s",p[i]);
        or strcpy(p[i],s[i]);
*/            

        