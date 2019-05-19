#include "factory.h"

void *downLoadFile(void *p)
{
    pFactory pf=(pFactory)p;
    pQue pq=&pf->que;
    pNode pCurr;
    int getSuccess;
    while(1)
    {
        pthread_mutex_lock(&pq->mutex);
        if(!pq->queSize)
        {
            pthread_cond_wait(&pf->cont,&pq->mutex);
        }
        getSuccess=queGet(pq,&pCurr);
        pthread_mutex_unlock(&pq->mutex);
        if(!getSuccess)
        {
            tranFile(pCurr->newFd);
            free(pCurr);
        }
    }
}


void facInit(pFactory pf,int threadNum,int capacity)
{
    memset(pf,0,sizeof(Factory));
    pf->pthid=(pthread_t*)calloc(threadNum,sizeof(pthread_t));
    pf->threadNumb=threadNum;
    pthread_cond_init(&pf->cont,NULL);
    queInit(&pf->que,capacity);
}

void facStart(pFactory pf)
{
    int i;
    if(0==pf->startflag)
    {
        for(i=0;i<pf->threadNumb;i++)
        {
            pthread_create(pf->pthid+i,NULL,downLoadFile,pf);
        }
        pf->startflag=1;
    }

}
