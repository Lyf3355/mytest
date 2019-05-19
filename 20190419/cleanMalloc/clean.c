#include<func.h>

void clean(void *p)
{
	printf("i am cleanFunction\n");
	free(p);
}

void* pthFunc(void* p)
{
	char buf[128];
	p=malloc(20);
	fgets(buf,sizeof(buf),stdin);
	pthread_cleanup_push(clean,p);
	printf("i am child pthread\n");
	pthread_exit(NULL);
	pthread_cleanup_pop(0);
}

int main()
{
	pthread_t pth;
	pthread_create(&pth,NULL,pthFunc,NULL);
	pthread_cancel(pth);
	printf("i am main pthread\n");
	return 0;
}
