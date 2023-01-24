#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NUM 50000
//atoi:字符串转数字
//itoa:数字转字符串
int CheckIsZero(int a[],int len){
    for(int i=0;i<len;i++){
        if(a[i]){
            return 1;
        }
    }return 0;
}
void PrintJudgeNumber(int b){
    if(b>0){
        printf("+%d",b);
        return;
    }printf("%d",b);
}
int main(){
    int N1,N2;
    scanf("%d%d",&N1,&N2);
    char s[100];
    scanf("%s",s);
    int a[NUM]={0};
    int b[NUM]={0};
    for(int i=N1;i>=0;i--){
        scanf("%d",&a[i]);
    }for(int i=N2;i>=0;i--){
        scanf("%d",&b[i]);
    }int plus[NUM]={0};
    int minus[NUM]={0};
    int multiply[NUM]={0};
    int N=N1+N2;
        for(int i=0;i<=N;i++){
            plus[i]=a[i]+b[i];
            minus[i]=a[i]-b[i];
            for(int j=0;j<=i;j++){
                int k=i-j;
                multiply[i]=multiply[i]+a[j]*b[k];
            }
        }if(!CheckIsZero(plus,NUM)){
            printf("0\n");
        }else{
            int high1;
            for(int i=N1+N2;i>=0;i--){
                if(plus[i]){
                    high1=i;
                    break;
                }
            }  if(high1>1){
                if(plus[high1]==1){
                    printf("%s^%d",s,high1);
                }else if(plus[high1]==-1){
                    printf("-%s^%d",s,high1);
                }
                else{
                printf("%d%s^%d",plus[high1],s,high1);
                }
            }else if(high1==1){
                if(plus[high1]==1){
                    printf("%s",s);
                }else if(plus[high1]==-1){
                    printf("-%s",s);
                }
                else{
                printf("%d%s",plus[high1],s);
                }
            }else{
                printf("%d",plus[high1]);
            }
            for(int i=high1-1;i>=0;i--){
                if(plus[i]==0){
                    continue;
                } if(plus[i]==1||plus[i]==-1){
                    if(i==0){
                       if(plus[i]>0){
                        printf("+1");
                       }else{
                        printf("-1");
                       }
                    }else if(i==1){
                        if(plus[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s",s);
                    }
                    else{
                         if(plus[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s^%d",s,i);
                    }
                }else{
                    if(i==0){
                       
                        PrintJudgeNumber(plus[i]);
                       
                    }else if(i==1){
                        PrintJudgeNumber(plus[i]);
                        printf("%s",s);
                    }
                    else{
                        PrintJudgeNumber(plus[i]);
                        printf("%s^%d",s,i);
                    }
                }
            }putchar('\n');
        }
        if(!CheckIsZero(minus,NUM)){
            printf("0\n");
        }else{
            int high1;
            for(int i=N1+N2;i>=0;i--){
                if(minus[i]){
                    high1=i;
                    break;
                }
            } if(high1>1){
                if(minus[high1]==1){
                    printf("%s^%d",s,high1);
                }else if(minus[high1]==-1){
                    printf("-%s^%d",s,high1);
                }
                else{
                printf("%d%s^%d",minus[high1],s,high1);
                }
            }else if(high1==1){
                if(minus[high1]==1){
                    printf("%s",s);
                }else if(minus[high1]==-1){
                    printf("-%s",s);
                }
                else{
                printf("%d%s",minus[high1],s);
                }
            }else{
                printf("%d",minus[high1]);
            }
            for(int i=high1-1;i>=0;i--){
                if(minus[i]==0){
                    continue;
                } if(minus[i]==1||minus[i]==-1){
                    if(i==0){
                       if(minus[i]>0){
                        printf("+1");
                       }else{
                        printf("-1");
                       }
                    }else if(i==1){
                        if(minus[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s",s);
                    }
                    else{
                         if(minus[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s^%d",s,i);
                    }
                }else{
                    if(i==0){
                      
                        PrintJudgeNumber(minus[i]);
                       
                    }else if(i==1){
                        PrintJudgeNumber(minus[i]);
                        printf("%s",s);
                    }
                    else{
                        PrintJudgeNumber(minus[i]);
                        printf("%s^%d",s,i);
                    }
                }
            }putchar('\n');
        }if(!CheckIsZero(multiply,NUM)){
            printf("0\n");
        }else{
            int high1;
            for(int i=N1+N2;i>=0;i--){
                if(multiply[i]){
                    high1=i;
                    break;
                }
            } if(high1>1){
                if(multiply[high1]==1){
                    printf("%s^%d",s,high1);
                }else if(multiply[high1]==-1){
                    printf("-%s^%d",s,high1);
                }
                else{
                printf("%d%s^%d",multiply[high1],s,high1);
                }
            }else if(high1==1){
                if(multiply[high1]==1){
                    printf("%s",s);
                }else if(multiply[high1]==-1){
                    printf("-%s",s);
                }
                else{
                printf("%d%s",multiply[high1],s);
                }
            }else{
                printf("%d",multiply[high1]);
            }
            for(int i=high1-1;i>=0;i--){
                if(multiply[i]==0){
                    continue;
                } if(multiply[i]==1||multiply[i]==-1){
                    if(i==0){
                       if(multiply[i]>0){
                        printf("+1");
                       }else{
                        printf("-1");
                       }
                    }else if(i==1){
                        if(multiply[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s",s);
                    }
                    else{
                        if(multiply[i]>0){
                            printf("+");
                        }else{
                            printf("-");
                        }
                        printf("%s^%d",s,i);
                    }
                }else{
                    if(i==0){
                       
                        PrintJudgeNumber(multiply[i]);
                       
                    }else if(i==1){
                        PrintJudgeNumber(multiply[i]);
                        printf("%s",s);
                    }
                    else{
                        PrintJudgeNumber(multiply[i]);
                        printf("%s^%d",s,i);
                    }
                }
            }putchar('\n');
        }
    
    return 0;
}
/*2 1
nn
3 0 1
1 -1

3nn^2+nn
3nn^2-nn+2
3nn^3-3nn^2+nn-1
*/
/*int n1,n2;
    char s[20];
    scanf("%d%d",&n1,&n2);  
    scanf("%s",s);
    char **p=malloc(20);
    for(int i=0;i<20;i++){
        p[i]=malloc(100);
    }
    char *p[5000];
    char *q[5000];
    char *r[5000];
    int a[2000]={0};
    int b[2000]={0};
    for(int i=n1;i>=0;i--){
        scanf("%d",&a[i]);
    }for(int i=n2;i>=0;i--){
        scanf("%d",&b[i]);
    }
    a[1]=1234;
    itoa(a[1],p[1],10);
   char *w=p[1]+strlen(p[1]);
    strcpy(w,s);
    printf("%s",p[1]);
    */