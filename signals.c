#include<stdio.h>
#include<signal.h>
void myhandler()
{
	printf("happy bd to you\n");
}
int main()
{
	int num;
	scanf("%d",&num);
	signal(num,myhandler);
	while(1)
	{
		printf("hi\n");
	sleep(1);
	}
}
	
	
