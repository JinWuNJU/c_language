#include<stdio.h>
#include<stdlib.h>
int Compare(const void *a,const void *b){
    const int *p=a;
    const int *q=b;
    if((*p)>(*q)){
        return 1;
    }return -1;
}
int main(){
    int numbers[]={1,4,1,5,9,2,6,5,3,5};
    int numberss[]={1,4,1,5,9,2,6,5,3,5};


    qsort(numbers,sizeof(numbers)/sizeof(*numbers),sizeof(numbers[0]),Compare);
    for(int i=0;i<=9;i++){
        printf("%d ",numbers[i]);
    }
    
    printf("\n");


    int min=numberss[0];
    for(int i=0;i<10;i++){
        for(int j=i;j<10;j++){
            if(min>numberss[j]){
                min=numberss[j];
                int temp=numberss[i];
                numberss[i]=numberss[j];
                numberss[j]=temp;
            }
        }min=numberss[i+1];
    }
    
    for(int i=0;i<10;i++){
        printf("%d ",numberss[i]);
    }
    return 0;
}
//int Compare(const void *a,const void *b)