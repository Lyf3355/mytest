#include<func.h>
#define N 20000000

typedef struct {
	int num;
	pthread_mutex_t mutex;
}date;

void *pthFunc(void* p)
{
	int i;
	date *pt=(date*)p;
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&pt->mutex);
		pt->num+=1;
		pthread_mutex_unlock(&pt->mutex);
	}
	return NULL;
}

int main()
{
	pthread_t pth;
	date pt;
	pt.num=0;
	pthread_mutex_init(&pt.mutex,NULL);
	pthread_create(&pth,NULL,pthFunc,&pt);
	int i;
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&pt.mutex);
		pt.num+=1;
		pthread_mutex_unlock(&pt.mutex);
	}
	pthread_join(pth,NULL);
	printf("i am main pthread,num=%d\n",pt.num);
	return 0;
}

