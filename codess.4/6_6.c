#include<stdio.h>
#include<math.h>
double f(double x){
    double y=exp(3*x)+pow(x,7);
    return y;
}
int main(){
    printf("1.梯形法\t2.矩形法\t3.退出\n");
    int m=0;
    double a=1,b=3;
    scanf("%d",&m);
    if(m==3){
        return 0;
    }else if(m==1){
        int n=0;
        scanf("%d",&n);
        double p=(b-a)/n*1.0;
        double q=(f(a)+f(b))/2.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=f((double)(p*i+a));
        }double result=p*(q+sum);
        printf("%lf",result);
        return 0;


    }else{
        int n=0;
        scanf("%d",&n);
        double p=(b-a)/n*1.0;
        double sum=0;
        for(int i=1;i<=n-1;i++){
            sum+=f(p*i+a);
        }double result=p*sum;
        printf("%lf",result);
        return 0;

    }
    return 0;
}
/*#include<stdio.h>
int main(){
    printf("                ********
               ************
               ####....#.
             #..###.....##....
             ###.......######              ###            ###
                ...........               #...#          #...#
               ##*#######                 #.#.#          #.#.#
            ####*******######             #.#.#          #.#.#
           ...#***.****.*###....          #...#          #...#
           ....**********##.....           ###            ###
           ....****    *****....
             ####        ####
           ######        ######
##############################################################
#...#......#.##...#......#.##...#......#.##------------------#
###########################################------------------#
#..#....#....##..#....#....##..#....#....#####################
##########################################    #----------#
#.....#......##.....#......##.....#......#    #----------#
##########################################    #----------#
#.#..#....#..##.#..#....#..##.#..#....#..#    #----------#
##########################################    ############");
    return 0;
}*/