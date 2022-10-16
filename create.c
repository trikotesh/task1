#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	char buf[10];
	printf("enter the directory name\n");
	scanf("%[^\n]s",buf);
	open(buf,O_RDWR|O_CREAT,0777);
}
