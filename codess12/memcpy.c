#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//                        6
typedef struct person{
    char name[21];
}Person;
Person Team1,Team2[9],Team3[9];
void swap(Person *x,Person *y){
    Person z=*x;
    *x=*y;
    *y=z;
}
int main(){
    // char name1[21]="wj";
    // memcpy(Team1.name,name1,sizeof(name1));
    // char name2[21]="sjs";
    // memcpy(Team2[1].name,name2,sizeof(name2));
   
    // memcpy(&Team3[1],&Team1,sizeof(Team1));
    // swap(&Team1,&Team2[1]);
    // puts(Team1.name);
    // puts(Team2[1].name);
    // puts(Team3[1].name);
    char *s;
    s=malloc(1000);
    char m[100];
    sprintf(m,"zxcvb");
    memcpy(s,m,6);
    puts(s);
    return 0;
}