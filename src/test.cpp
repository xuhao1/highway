#include"stdio.h"
#include <omp.h>

int main()
{
	int sum=0;
#pragma omp parallel num_threads(8)
	{
		int tid = omp_get_thread_num();
		sum+=tid;
		printf("I'm id:%d\n",tid);
	}
	printf("tsum%d\n",sum);
}
