#include <stdio.h>
int InterSection(int a[][5], int res[5])
{	
int i,k,m,count=0,flag=0;

	    for(i=0;i<5;i++){
	     	for(k=1;k<5;k++)
			   for(m=0;m<5;m++){
			   	if(*(*a+i) == *(*(a+k)+m)) {
					flag++; 
break;
}
			  	}
		  if(flag>=4)
		    res[count++]=*(*a+i);
            flag=0;
	   	}
	  	return count;
}
int main(void)
{	
int sec[][5]={{12,35,3,9,0},{2,35,9,12,1},{35,12,0,1,9},{4,90,35,9,12},{11,9,0,12,35}};
	    int intsec[5],number,i;

	    number=InterSection(sec,intsec);
	   	for(i=0;i<number;i++)
printf("%5d",intsec[i]);
    	printf("\n");
return 0;
}
