#include <stdio.h>
#include <pthread.h>
#include "sum.h"

//tinh tong cac so tu 1 - 100000

int sum1 = 0;
pthread_mutex_t sum1_lock;

void add_sum(int i)
{
    pthread_mutex_lock(&sum1_lock);
    sum1 = sum1 + i;
    pthread_mutex_unlock(&sum1_lock);
}

void init_sum_lib()
{
    pthread_mutex_init(&sum1_lock, NULL);
    sum1 = 0;
}

void free_sum_lib()
{
    pthread_mutex_destroy(&sum1_lock);
}