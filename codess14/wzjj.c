#include<stdio.h>
int main(){
    int N,T;
    scanf("%d%d",&N,&T);
    int Weight[N+5];
    int Value[N+5];
    double PerValue[N+5];
    for(int i=1;i<=N;i++){
        scanf("%d%d",&Weight[i],&Value[i]);
        PerValue[i]=1.0*Value[i]/Weight[i];
    }
    //排序
    double min=PerValue[1];
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            if(min>PerValue[j]){
                min=PerValue[j];

                double temp1=PerValue[i];
                PerValue[i]=PerValue[j];
                PerValue[j]=temp1;

                int temp2=Weight[i];
                Weight[i]=Weight[j];
                Weight[j]=temp2;
                
                int temp3=Value[i];
                Value[i]=Value[j];
                Value[j]=temp3;
            }
        }
        min=PerValue[i+1];
    }
    
    //现在是从小到大
    int sum=0;
    int index;
    for(int i=N;i>=1;i--){
        sum+=Weight[i];
        if(sum>=T){
            index=i;
            break;
        }
    }
    int rest1=sum-Weight[index];
    int rest2=T-rest1;
    
    double result=0.0;
    result+=1.0*rest2*PerValue[index];

    for(int i=index+1;i<=N;i++){
        result+=1.0*Weight[i]*PerValue[i];
    }
    printf("%.2lf",result);
    return 0;
}