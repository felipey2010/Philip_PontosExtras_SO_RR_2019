/**
 * gcc -pthread produtor_consumidor.c -o prod_cons
 **/

#include <stdio.h>
#include <pthread.h>

int b; /* buffer size = 1; */
int turn=0;

int main() {
    pthread_t produtor_thread1;
    pthread_t produtor_thread2;
    pthread_t produtor_thread3;

    pthread_t consumidor_thread1;
    pthread_t consumidor_thread2;
    pthread_t consumidor_thread3;

    void *produtor();
    void *consumidor();

    pthread_create(&consumidor_thread1,NULL,consumidor,NULL);
    pthread_create(&consumidor_thread2,NULL,consumidor,NULL);
    pthread_create(&consumidor_thread3,NULL,consumidor,NULL);

    pthread_create(&produtor_thread1,NULL,produtor,NULL);
    pthread_create(&produtor_thread2,NULL,produtor,NULL);
    pthread_create(&produtor_thread3,NULL,produtor,NULL);


    pthread_join(consumidor_thread1,NULL);
    pthread_join(consumidor_thread2,NULL);
    pthread_join(consumidor_thread3,NULL);

    return 0;
}

void coloque(int i){
    b = i;
}

int pegue(){
    return b ;
}

void *produtor() {
    int i = 0;
    //
    while (1) {
        printf("Produtor\n");
        while (turn == 1) ;
        printf("turn P %d \n", turn);
        coloque(i);
        turn = 1;
        i = i + 1;
    }
    pthread_exit(NULL);
}

void *consumidor() {
    int i,v;
    //printf("Consumidor\n");
    for (i=0;i<2;i++) {
        printf("Consumidor \n");
        while (turn == 0) ;
        printf("turn C %d \n", turn);
        v = pegue();
        turn = 0;
        printf("Peguei %d \n",v);
    }
    pthread_exit(NULL);
}
