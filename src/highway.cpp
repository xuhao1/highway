#include "highway.h"

#define dt 0.00001
//First simulate use Margolus neighbor
//Sand Rule

#define MAXN 10
void highway::evoluation()
{
	if(rand()%50<1)
	{
		num++;
		xinway.push_back( car((rand()%2+1)*50+50,rand()%MAXLANE,num,rand()%10*10000) );
	}
	time+=dt;
	Iteration();
}

void highway::Iteration()
{
	double sum=0;
	for(car &c:xinway)
	{
		c.adapt(xinway,time);
		sum+=c.speed;
	}
	sum/=xinway.size();
	printf("AveageSpeed:%f\n",sum);
	for(car& c:xinway)
	{
		c.runintdt(dt);
	}
}

