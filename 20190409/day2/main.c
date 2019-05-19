#include <stdio.h>

void print()
{	
	printf("I am print\n");
}
int main(int argc,char* argv[])
{
	printf("I am happy\n");//标准输出
	print();
	FILE *fp;
	int i=10;
	i=i^3;
	fp=fopen(argv[1],"rb+");
	if(NULL==fp)
	{
		perror("fopen");//标准错误
		return -1;
	}
}
