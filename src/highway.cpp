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
		xinway.push_back( car((rand()%2+1)*50+50,rand()%4,num) );
	}
	time+=dt;
	Iteration();
}

void highway::Iteration()
{
	for(car &c:xinway)
	{
		c.adapt(xinway,time);	
	}
	for(car& c:xinway)
	{
		c.runintdt(dt);
	}
}

