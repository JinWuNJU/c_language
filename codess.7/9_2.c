#include<stdio.h>
char output[100];
int cut=1;
void  itoah(int x){
  if(x%16<=9){
      output[cut]=x%16+48;
      cut++;
    }else{
      output[cut]=x%16+55;
      cut++;
    }
  
  if(x/16!=0){
    itoah(x/16);
  }
}
int main(){
    int n=0;
    scanf("%d",&n);
    itoah(n);
    for(int i=cut;i>=1;i--){
      printf("%c",output[i]);
    }
    return 0;
}