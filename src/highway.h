#ifndef __USTC_HIGHWAY_H__
#define __USTC_HIGHWAY_H__

#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "string.h"
#include <fstream>
#include <vector>
#include "car.h"
class highway
{
public:
	void evoluation();
	double time;
	double dt=0.00001;
	int num;
	int randColl;
	std::vector<car> xinway;
	void Iteration();
	double flow;
	double avsped;
	highway(double _flow):
		num(0),xinway(),time(0),flow(_flow)
	{
		xinway.push_back( car((rand()%2+1)*50+50,1,num,100000) );
		randColl =1/(double)(dt*_flow);
		printf("randcoll:%d\n",randColl);
	}
};


#endif
