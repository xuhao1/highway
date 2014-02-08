#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <vector>
#include "math.h"
class car
{
public:
	float location;
	float speed;
	float maxspeed;
	int lane;
	int id;
	car(float _ms,int _lane,int _id):
		lane(_lane),maxspeed(_ms),id(_id),location(0),speed(0)
	{
		
	}
	void runintdt(double dt);
	void adapt(std::vector<car>&);
};

#endif
