#ifndef __CAR_H__
#define __CAR_H__
#include <iostream>
#include <vector>
#include "math.h"

#define MAXLANE 4
#define BIGCAR 0
#define MEDCAR 1
#define SMALLCAR 2
#define Gravity 9.8

class car
{

	float maxspeed;
	float mass;//kg
	float mu;//friction
	int mind;
	double lasw=0;
	double danger(car &fr);
	double tr;
	double mktr();
public:
	float location;
	float speed;
	int lane;
	int id;
	void runintdt(double dt);
	void adapt(std::vector<car>&,double time,int num);
	double distance();
	double dangercol;
	car(int carclass,int _lane,int _id,int _mind):
		lane(_lane),id(_id),location(0),speed(0),lasw(0),mind(_mind)
	{
		dangercol=0;
		switch(carclass)
		{
			case BIGCAR:
				maxspeed=80;
				mass=10000;
				mu=0.6;
				break;

			case MEDCAR:
				maxspeed=120;
				mass=4000;
				mu=0.7;
				break;

			case SMALLCAR:
				mass=2000;
				maxspeed=150;
				mu=0.85;
				break;
		}
		mktr();
	
	}
};	
#endif
