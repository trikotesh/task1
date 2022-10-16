#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
main(int argc,char *argv[])
{
	int p,q;
	printf("%s",argv[1]);
	p=atoi(argv[1]);
	printf("%s",argv[2]);
	q=atoi(argv[2]);
	if(argc==2)
	{
	kill(p,q);
	}
	else
	{
		printf("enter valid arguments\n");
	}
}
