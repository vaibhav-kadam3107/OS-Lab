#include<stdio.h>
#include<pthread.h>

pthread_mutex_t mutex , number_mutex;
int cnt = 1, numreader = 0;

void * writer(void * wno){
    pthread_mutex_lock(&mutex);

    //write
    cnt *= 2;
    printf("writer %d , is writing the val %d\n", (*((int *)wno)) , cnt);

    pthread_mutex_unlock(&mutex);
}

void* reader(void * rno){
    pthread_mutex_lock(&number_mutex);
    numreader++;
    if(numreader == 1)
        pthread_mutex_lock(&mutex);
    pthread_mutex_unlock(&number_mutex);

    //read
    printf("Reader %d , is reading the val %d\n" , *((int *)rno) , cnt);

    pthread_mutex_lock(&number_mutex);
    numreader--;
    if(numreader == 0)
        pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&number_mutex); 
}

int main(){
    pthread_t read[10] , write[5];
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&number_mutex, NULL);

    int a[10] = {1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10};

    //create
    for (int i = 0; i < 10; i++)
        pthread_create(&read[i] , NULL , (void *)reader , (void *)&a[i]);
    
    for(int i = 0; i < 5; i++)
        pthread_create(&write[i] , NULL , (void *)writer , (void *)&a[i]);

    //join

    for(int i = 0; i < 10; i++)
        pthread_join(read[i] , NULL);

    for(int i = 0; i < 5; i++)
        pthread_join(write[i] , NULL);

    //destroy
    pthread_mutex_destroy(&mutex);
    pthread_mutex_destroy(&number_mutex);

    return 0;
}