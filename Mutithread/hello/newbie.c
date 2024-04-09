#include <stdio.h>
#include <pthread.h>
#include "sum.h"

void *new_bie(void *arg)
{
    int i = 0;

    for (i = 0; i < 100000; i++) {
        sum1 = sum1 + i;
    }
}