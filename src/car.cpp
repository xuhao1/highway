#include "car.h"
#define side 0.01
#define MAXLANE 4
void car::adapt(std::vector<car>& way,double time)
{
	std::vector<car> left,front,right;
	double frontmin=1000;
	int fp=0;
	for(car c:way)
	{
		if(c.id==this->id)
			continue;
		if(fabs(c.location-this->location)<side)
		{
			if(c.lane==this->lane)
			{
				if(c.location>this->location)
				{
					front.push_back(c);
					if(c.speed<frontmin)
						frontmin=c.speed;
				}
				else
				{

				}

			}
			if(c.lane==this->lane+1&&(c.location-this->location)<side)
				left.push_back(c);
			if(c.lane==this->lane-1&&(c.location-this->location)<side)
				right.push_back(c);
		}
	}

	if (front.size()>0&& (frontmin<=maxspeed) )
	{
		if(lane<MAXLANE-1&&left.size()==0&&fabs(lasw-time)>0.001)
		{
			lane++;
			fp=1;
			lasw=time;
			printf("I vc\n");
		}
		else
		{
			speed-=10;
			if (speed<0)
				speed=0;
		}
	}
	if(lane>0&&right.size()==0&&fp!=1&&fabs(lasw-time)>0.001)
	{
		lasw=time;
		lane--;
	}
	if(front.size()==0&&speed<maxspeed)
		speed+=10;
}
void car::runintdt(double dt)
{
	location+=speed*dt;
}
