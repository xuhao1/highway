#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <vector>
#include "math.h"
#define MAXLANE 4
class car
{
public:
	float location;
	float speed;
	float maxspeed;
	int lane;
	int id;
	int broken=0;
	int mind;
	double lasw=0;
	car(float _ms,int _lane,int _id,int _mind):
		lane(_lane),maxspeed(_ms),id(_id),location(0),speed(0),lasw(0),mind(_mind)
	{
		
	}
	void runintdt(double dt);
	void adapt(std::vector<car>&,double time);
};

#endif
