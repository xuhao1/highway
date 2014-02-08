#include "car.h"
#define side 0.05
#define MAXLANE 2
void car::adapt(std::vector<car>& way)
{
	std::vector<car> left,front,right;
	double frontmin=1000;
	for(car c:way)
	{
		if(c.id!=this->id)
			continue;
		if(abs(c.location-this->location)<side)
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
			if(c.lane>this->lane)
				left.push_back(c);
			if(c.lane<this->lane)
				right.push_back(c);
		}
	}

	if (front.size()>0&&frontmin<speed)
	{
		if(lane<MAXLANE-1&&left.size()==0)
			lane++;
		else
		{
			speed-=10;
			if (speed<0)
				speed=0;
		}
	}
	else
	if(lane>0&&right.size()==0)
		lane--;
}
void car::runintdt(double dt)
{
	location+=speed*dt;
}
