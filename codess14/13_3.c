#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Message{
     long  id  ;     	//学号
       char name[10]; 		//姓名
       char sex[1] ;      	//性别（m 代表男，f 代表女）
}PS;
PS a[5]={{101, "tom","m"},{103,"mary","f"},{104,"mark","m"}, 
{105,"julia","f"},{106, "sara","f"}
};
PS b[5]={ {102, "mark","m"},{104,"mark","m"}};
int delete(PS *p1, int m, PS *p2,int n){
    int cut=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(p2[j].id==p1[i].id){
                cut++;
                for(int k=i;k<m;k++){
                    p1[k]=p1[k+1];
                }
                break;
            }
        }
    }
    return cut;
}
int merge(PS *p1,int m, PS *p2 ,int n){
    for(int i=0;i<n;i++){
        p1[i+m]=p2[i];
    }
    int min=p1[0].id;
    for(int i=0;i<m+n;i++){
        for(int j=i;j<m+n;j++){
            if(min>p1[j].id){
                min=p1[j].id;
                int tem=p1[j].id;
                p1[j].id=p1[i].id;
                p1[i].id=tem;
            }
        }
        min=p1[i+1].id;
    }
    return m+n;
}
void sort(PS *p,int n){
    for(int i=0;i<n-1;i++){
        if(p[i].sex[0]=='m'&&p[i+1].sex[0]=='f'){
            swap(p+i,p+i+1);
        }
    }
    for(int i=0;i<n-1;i++){
        if(strcmp(p[i].name,p[i+1].name)==1){
            swap(p+i,p+i+1);
        }
    }
}
void swap(PS *p1,PS *p2){
    PS tem=*p1;
    *p1=*p2;
    *p2=tem;
}
void display(PS *p,int n){
    printf("ID\tNAME\tSEX\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%s\n",p[i].id,p[i].name,p[i].sex);   
    }
}
void ppa(){
    printf("a:\n");
}
void ppb(){
    printf("b:\n");
}
int main(){
    ppa();
    display(a,5);
    ppb();
    display(b,2);
    ppa();
    int t=5-delete(a,5,b,2);
    display(a,t);
    merge(b,2,a,t);
    ppb();
    display(b,2+t);
    sort(a,t);
    ppa();
    display(a,t);
    return 0;
}