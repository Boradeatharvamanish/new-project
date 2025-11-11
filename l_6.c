#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
    sem_t mutex,wrt;
    int sharedvar=99;
    int readercount=0;
    pthread_t writers[5],readers[5];

void reader(){
    sem_wait(&mutex);
    readercount++;
        if(readercount==1)
    {
        sem_wait(&wrt);
    }
    sem_post(&mutex);
    printf("\n reader is reading the data %d",sharedvar);
    
    printf("\n reader is done");
    sem_wait(&mutex);
    readercount--;

    if(readercount==0)
    {
    sem_post(&wrt);
    }
    
    sem_post(&mutex);
 }
 
 void writer(){
 
    printf("\n writer is trying to write ");
    sem_wait(&wrt);
    printf("\n writer is in critical section");
    sharedvar++;
    printf("\n writer changed the value to %d",sharedvar);
    
    sem_post(&wrt);
        printf("\n writer is out of cs");


 
}

int main(){
    int n,i;
    printf("enter the no of readers and writer ");
    scanf("%d",&n);
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);

    for(int i=0;i<n;i++)
    {
        pthread_create(&writers[i],NULL,(void*)writer,NULL);
        pthread_create(&readers[i],NULL,(void*)reader,NULL);
    }

    for(int i=0;i<n;i++)
    {
        pthread_join(writers[i],NULL);
        pthread_join(readers[i],NULL);
    }

return 0;

}
