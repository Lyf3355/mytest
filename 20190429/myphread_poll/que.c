#include "que.h"
void queInit(pQue pq,int capacity)
{
    memset(pq,0,sizeof(Que));
    pq->queCapacity=capacity;
    pthread_mutex_init(&pq->mutex,NULL);
}

void queInsert(pQue pq,pNode pnew)
{
    if(NULL==pq->tail)
    {
        pq->head=pnew;
        pq->tail=pnew;
    }else{
        pq->tail->pNext=pnew;
        pq->tail=pnew;
    }
    pq->queSize++;
}

int queGet(pQue pq,pNode *ppcur)
{
    if(0==pq->queSize)
    {
        return -1;
    }else{
        *ppcur=pq->head;
        pq->head=pq->head->pNext;
        if(NULL==pq->head)
        {
            pq->tail=NULL;
        }
        pq->queSize--;
        return 0;
    }
}
