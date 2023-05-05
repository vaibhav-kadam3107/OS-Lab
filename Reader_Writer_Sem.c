#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

sem_t wrt , mutex;
int cnt = 1, numreader = 0;

void *writer(void * wno){
    sem_wait(&wrt);

    cnt *= 2;
    printf("writer %d , is updating cnt value %d\n", (*((int *)wno)) , cnt);

    sem_post(&wrt);
}

void * reader(void* rno){
    sem_wait(&mutex);
    numreader++;
    if(numreader == 1)
        sem_wait(&wrt);
    sem_post(&mutex);

    //read
    printf("Reader %d , is reading cnt value %d\n", *((int *)rno) , cnt);

    sem_wait(&mutex);
    numreader--;
    if(numreader == 0)
        sem_post(&wrt);
    sem_post(&mutex);
}

int main(){
    pthread_t read[10] , write[5]; // 10 reader 5 writer
    sem_init(&wrt , 0 , 1);
    sem_init(&mutex , 0 , 1);

    int a[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    for(int i = 0; i < 10; i++)
        pthread_create(&read[i] , NULL , (void* )reader , (void*)&a[i]);

    for(int i = 0; i < 5; i++)
        pthread_create(&write[i] , NULL , (void*)writer , (void*)&a[i]);


    for(int i = 0; i <10; i++)
        pthread_join(read[i] , NULL);

    for(int i = 0; i < 5; i++)
        pthread_join(write[i] , NULL);

    sem_destroy(&wrt);
    sem_destroy(&mutex);

    return 0;
}