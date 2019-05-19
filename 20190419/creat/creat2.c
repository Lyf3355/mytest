#include<func.h>
void print()
{
	printf("i am print\n");
	pthread_exit(NULL);
}

void *pthreadFun(void *p)
{
	strcpy((char*)p,"helloword");
	print();
	printf("i am son pthread\n");
	return NULL;
}

int main()
{
	pthread_t pth;
	char *p=(char*)malloc(20);
	pthread_create(&pth,NULL,pthreadFun,p);
	pthread_join(pth,NULL);
	printf("i am main pthread:%s\n",p);
	return 0;
}
