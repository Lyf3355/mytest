#include<func.h>
typedef struct
{
	int tick;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}Ti;

void* saleFunc1(void *p)
{
	Ti *psale=(Ti*)p;
	int count=0;
	while(1)
	{
		pthread_mutex_lock(&psale->mutex);
		if(psale->tick>0)
		{
			printf("i am windows1, tickets:%d\n",psale->tick);
			psale->tick--;
			if(0==psale->tick)
			{
				pthread_cond_signal(&psale->cond);
			}
			count++;
			printf("sale finish whindows1 ,tickets:%d\n",psale->tick);
			pthread_mutex_unlock(&psale->mutex);
		}else{
			pthread_mutex_unlock(&psale->mutex);
			printf("i am whindows1,sale:%d",count);
			break;
		}
	}
return NULL;
}

void* saleFunc2(void *p)
{
	Ti *psale=(Ti*)p;
	int count=0;
	while(1)
	{
		pthread_mutex_lock(&psale->mutex);
		if(psale->tick>0)
		{
			printf("i am windows2, tickets:%d\n",psale->tick);
			psale->tick--;
			if(0==psale->tick)
			{
				pthread_cond_signal(&psale->cond);
			}
			count++;
			printf("sale finish whindows2 ,tickets:%d\n",psale->tick);
			pthread_mutex_unlock(&psale->mutex);
		}else{
			pthread_mutex_unlock(&psale->mutex);
			printf("i am whindows2,sale:%d",count);
			break;
		}
	}
return NULL;
}

void *set(void*p)
{
	Ti *psale=(Ti*)p;
	pthread_mutex_lock(&psale->mutex);
	if(psale->tick>0)
	{
		pthread_cond_wait(&psale->cond,&psale->mutex);
	}
	psale->tick=20;
	pthread_mutex_unlock(&psale->mutex);
	return NULL;
}
typedef void* (*threadfunc)(void*);
#define N 3

int main()
{
	pthread_t pth[N];
	Ti t;
	t.tick=20;
	threadfunc pthreadFunc[N]={saleFunc1,saleFunc2,set};
	pthread_mutex_init(&t.mutex,NULL);
	pthread_cond_init(&t.cond,NULL);
	for(int i=0;i<N;i++)
	{
	pthread_create(pth+i,NULL,pthreadFunc[i],&t);
	}
	for(int i=0;i<N;i++)
	{
		pthread_join(pth[i],NULL);
	}
	printf("over\n");
}

