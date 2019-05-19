#include "factory.h"

int main(int argc,char* argv[])
{
    ARGS_CHECK(argc,5);
    Factory f;
    int threadNum=atoi(argv[3]);
    int capacity=atoi(argv[4]);
    facInit(&f,threadNum,capacity);
    facStart(&f);
    int socketfd;
    tcpInit(&socketfd,argv[1],argv[2]);
    int newfd;
    pQue pq=&f.que;
    while(1)
    {
        newfd=accept(socketfd,NULL,NULL);
        pNode pnew=(pNode)calloc(1,sizeof(Node));
        pnew->newFd=newfd;
        pthread_mutex_lock(&pq->mutex);
        queInsert(pq,pnew);
        pthread_mutex_unlock(&pq->mutex);
        pthread_cond_signal(&f.cont);
    }
}
