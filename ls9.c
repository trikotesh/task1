#include<stdio.h>
#include<dirent.h>
main()
{
	DIR *t;
	struct dirent *y;
	t=opendir(".");
	while((y=readdir(t))!=NULL)
		printf("%s   ",y->d_name);
	closedir(t);
	printf("\n");
}

