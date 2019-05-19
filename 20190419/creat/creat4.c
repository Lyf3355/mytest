#include<func.h>

void* thdFunc(void* p)
{
	long ret=(long)p;
	sleep(2);
	printf("i am child theard,return:%ld\n",ret);
	pthread_exit((void*)2);
}
int main()
{
	long ret=0;
	pthread_t thd;
	pthread_create(&thd,NULL,thdFunc,(void*)1);
	pthread_join(thd,(void**)&ret);
	printf("i am main thread,return:%ld\n",ret);
	return 0;
}
