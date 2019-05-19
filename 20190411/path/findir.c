#include<func.h>

int find(char* dirName,char* fileName)
{
	DIR *dir;
	dir=opendir(dirName);
	ERROR_CHECK(dir ,NULL,"opendir");
	struct dirent *p;
	char path[512]={0};
	while((p=readdir(dir)))
	{
		sprintf(path,"%s%s%s",dirName,"/",p->d_name );
		if(strcmp(p->d_name,fileName )==0)
			printf("%s\n",path);
	}
	closedir(dir);
	return 0;
}
int main(int argc,char* argv[])
{
	ARGS_CHECK(argc,3);
	find(argv[1],argv[2]);
	return 0;
}

