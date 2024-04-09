#ifndef _SUM_H_
#define _SUM_H_

#include <stdio.h>
#include <pthread.h>

//Day la nhung tai nguyen co the race condition,
//vui long su dung mutex lock sum1_lock truoc khi truy cap

void add_sum(int i);
void init_sum_lib();
void free_sum_lib();
void *new_bie(void *arg);

#endif /* _SUM_H_ */