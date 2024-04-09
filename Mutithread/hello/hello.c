#include <stdio.h>
#include <pthread.h>
#include "sum.h"

//tinh tong cac so tu 1 - 100000

//day la ham gay ra deadlock
void dead_lock()
{
    pthread_mutex_lock(&sum1_lock);
    sum1 = sum1++;
    pthread_mutex_unlock(&sum1_lock);
}

//day la ham main thread
void *sum_cal1(void *arg)
{
    int i = 0;

    for (i = 0; i < 50000; i++) {
        pthread_mutex_lock(&sum1_lock);
        //dead_lock();
        sum1 = sum1 + i;
        pthread_mutex_unlock(&sum1_lock);
    }

    return NULL;
}

void *sum_cal2(void *arg)
{
    int i = 0;

    for (i = 50000; i < 100000; i++) {
        pthread_mutex_lock(&sum1_lock);
        sum1 = sum1 + i;
        pthread_mutex_unlock(&sum1_lock);
    }

    return NULL;
}

int main()
{
    int sum = 0;
    int i = 0;

    pthread_t sum_thread1;
    pthread_t sum_thread2;
    pthread_t newbie_thread;

    pthread_mutex_init(&sum1_lock, NULL);

    pthread_create(&sum_thread1, NULL, sum_cal1, NULL);
    pthread_create(&sum_thread2, NULL, sum_cal2, NULL);
    pthread_create(&newbie_thread, NULL, new_bie, NULL);

    pthread_join(sum_thread1, NULL);
    pthread_join(sum_thread2, NULL);

    pthread_mutex_destroy(&sum1_lock);

    printf("sum: %d\n", sum1);

    for (i = 0; i < 100000; i++) {
        sum = sum + i;
    }
    printf("properly value is: %d\n", sum);

    return 0;
}