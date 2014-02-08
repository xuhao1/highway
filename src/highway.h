#ifndef __USTC_HIGHWAY_H__
#define __USTC_HIGHWAY_H__


#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "string.h"
#include <fstream>
#include <vector>
#include "car.h"
namespace highway
{
	void evoluation();
	std::vector<double>  getLocation();
	std::vector<int> getChannel();
}


#endif
