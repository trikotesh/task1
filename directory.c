#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int opt,ret;
	char buf[10];
	while(1)
	{
	printf("enter the option\n0-to exit 1-for creating directroy or 2-for removing directory\n");
	scanf("%d",&opt);
	__fpurge(stdin);
	switch(opt)
	{
		case 0:
			return 0;
		case 1:
			scanf("%[^\n]s",buf);
			__fpurge(stdin);
			ret=mkdir(buf,0777);
			if(ret<0)
				printf("Directory already exists \n");
			else
			printf("Directory created succesfully\n");
			break;	
		case 2:

			scanf("%[^\n]s",buf);
			__fpurge(stdin);
			ret=rmdir(buf);
			if(ret<0)
				printf("Directory doesn't exist to remove\n");
			else
			printf("Directory removed successfully\n");
			break;
	}
	}
}
