#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	
	char *s;
	char a[200]="1234567890";
	a[5]='\0';
	s=a;
	printf("%d",atoi(s));
	return 0;
}