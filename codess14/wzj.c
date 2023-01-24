//
// Created by 20663 on 2023/1/4.
//
//qsort函数和bsearch函数都要有三种情况!!!
//也就是要有0的返回值!!!
#include<stdio.h>
#include<stdlib.h>
#define NUM 1000005
int a[NUM];
int m,n,q;
int Find(int m){
    int l=1,r=n;
    while(l<=r){
        int mid;
        mid=(l+r)/2;
        if(m>a[mid]){
            l=mid+1;
        }
        else if(m<a[mid]){
            r=mid-1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
int compare(const void *a,const void *b){
    int p=*(int *)a;
    int q=*(int *)b;
    if(p>q){
        return 1;
    }
    return -1;
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d",&q);
        int key=q;
        int *tem=bsearch(&key,a,n,sizeof(int),compare);
        if(tem==NULL){
            printf("%d ",-1);
        }
        else{
            printf("%d ",*tem);
        }
    }
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
 
// int compareints (const void * a, const void * b)
// {
//   return ( *(int*)a - *(int*)b );
// }
 
// int values[] = { 10, 20, 25, 40, 90, 100 };
 
// int main ()
// {
//   int * pItem;
//   int key = 40;
//   pItem = (int*) bsearch (&key, values, 6, sizeof (int), compareints);
//   if (pItem!=NULL)
//     printf ("%d is in the array.\n",*pItem);
//   else
//     printf ("%d is not in the array.\n",key);
//   return 0;
// } //40 is in the array
