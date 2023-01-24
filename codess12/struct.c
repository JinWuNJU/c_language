#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//结构体可以嵌套
//结构体可以赋值
typedef enum gender{
    MALE,
    FEMALE,
}Gender;
typedef struct score{
    int java_score;
    int c_score;
    int python_score;
}Score;
typedef struct musician{
    char name[20];
    Gender gender;
    char album[50];
    Score score;
}Musician;
void printmusician(Musician *m){
    printf("\n%s\t%d\t%s\t%d\t%d\t%d\n",
                    m->name,
                    m->gender,
                    m->album,
                    m->score.c_score,
                    m->score.java_score,
                    m->score.python_score);
}
int Compare(const void* m1,const void* m2){
    Musician *left=  m1;
    Musician *right= m2;
    return strcmp(left->album,right->album);

}
void swap(Musician *m1,Musician *m2){
    Musician Z= *m1;
    *m1=*m2;
    *m2=Z;
}
int main(){
    struct musician luo = {
    .gender= MALE,
    .name= "Luo",
    .album = "Zhihuzheye",
    .score={10,20,30,},
    //    .score.c_score =  20,
    //    .score.python_score = 10,
    //    .score.java_score = 30,
    //two methods are both OK
    };
    Musician zhang = luo;
    //zhang.album="Xhang Kangliang";
    //zhang.album="abcdefg";
    //strcpy(zhang.album,"qwert");//不能这么用!!!
    sprintf(zhang.album,"Qwert");
    printmusician(&luo);
    printmusician(&zhang);
    Musician ss[2]={luo,zhang};
    qsort(ss,sizeof(ss)/sizeof(ss[0]),sizeof(ss[0]),Compare);
    printmusician(ss);
    printmusician(ss+1);
    swap(&luo,&zhang);
    printmusician(&luo);
    printmusician(&zhang);
    return 0;
}