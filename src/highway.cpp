#include "highway.h"

#define dt 0.01
//First simulate use Margolus neighbor
//Sand Rule

#define MAXN 100
void highway::evoluation()
{
	for(int i=0;i<10000;i++)
	{
		if(rand()%10<1)
		{
			num++;
			xinway.push_back( car(rand()%2,100,num) );
		}
		if(i% 100==0)
		{
			printf("time to %f\n",(double)dt*i);
			Iteration();
		}
	}
}

void highway::Iteration()
{
	for(car c:xinway)
	{
		c.adapt(xinway);	
	}
	for(car c:xinway)
	{
		c.runintdt(dt);
	}
}

