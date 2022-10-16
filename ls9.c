#include<stdio.h>
#include<dirent.h>
main()
{
	DIR *t;
	struct dirent *y;
	d=opendir(".");
	while((y=readdir(t))!=NULL)
		printf("%s   ",y->t_name);
	closedir(t);
	printf("\n");
}

