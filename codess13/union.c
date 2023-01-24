#include<stdio.h>
//try to use less fuction od union!!!
typedef struct val {
    enum {I, F, E} type;
    struct {
        int ival;
        double fval;
    } val;
} Val;
typedef struct mucisian{
    int a;
    char s[20];
    int numbers[50];
}Musician;

typedef union mucisian1{
    int a;
    char s[20];
    int numbers[50];
}Musician1;
int main(){
    Musician1 m;
    m.a=20;
    sprintf(m.s,"qwerhuhu");
    //m.numbers[1]=88;
    printf("%s",m.s);
    Val a;
    a.type=F;
    printf("%d",a.type);
    return 0;
}