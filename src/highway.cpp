#include "highway.h"
#include <omp.h>

#define dt 0.00001
//First simulate use Margolus neighbor
//Sand Rule

#define MAXN 10
void highway::evoluation()
{
	if( rand()%randColl <1)
	{
		num++;
		xinway.push_back( car((rand()%2+1)*50+50,rand()%MAXLANE,num,rand()%10*10000) );
	}
	time+=dt;
	Iteration();
}

void highway::Iteration()
{
	double sum[8]={0};
	int tid=0;
	std::vector<car*> queue[8];
	for(int i=0;i<xinway.size();i++)
	{
		queue[tid%8].push_back(&xinway[i]);
	}

#pragma omp parallel num_threads(8)
	{
		tid = omp_get_thread_num();
		for(car *c:queue[tid])
		{
			c->adapt(xinway,time);
			sum[tid]+=c->speed;
		}
	}

#pragma omp parallel num_threads(8)
	{
		tid = omp_get_thread_num();
		for(car* c:queue[tid])
		{
			c->runintdt(dt);
		}	
	}

	double avsum=0;
	for(int i=0;i<8;i++)
	{
		avsum+=sum[i];
	}
	avsped=avsum/xinway.size();
}


