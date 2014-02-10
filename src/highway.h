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
	double dangercol;
	int num;
	int randColl;
	std::vector<car> xinway;
	double flow;
	int np=0;
	double avsped;
	highway(double _flow):
		num(0),xinway(),time(0),flow(_flow)
	{
		xinway.push_back(car( 1,1,num,100000) );
		randColl =1/(double)(dt*_flow);
		printf("randcoll:%d\n",randColl);
	}
private:
	void Iteration();
	void qsort(std::vector<car>&,int l,int r);

};


#endif
