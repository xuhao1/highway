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
	int num;
	std::vector<car> xinway;
	void Iteration();
	highway():
		num(0),xinway()
	{
	}
};


#endif
