#include "car.h"
#define side 0.01
#define SWITCHTIME 0.002
void car::adapt(std::vector<car>& way,double time,int num)
{
	std::vector<car> left,front,right;
	double frontmin=1000;
	int fp=0;

	/*
	if(rand()%1000000<1||broken)
	{
		speed=0;
		broken=1;
		return;
	}
	*/
	//We assume the car has been sort before

	for(int i=num+1;i<way.size() && way[i].location-location<distance();i++)
	{
		car c=way[i];

		if(c.lane==this->lane)
		{
			front.push_back(c);
			if(c.speed<frontmin)
				frontmin=c.speed;
		}

		if(c.lane==this->lane+1&&(c.location-this->location)<distance() )
			left.push_back(c);
		if(c.lane==this->lane-1&&(c.location-this->location)<distance() )
			right.push_back(c);
	}

	/*
	for(int i=num-1;i>=0 && fabs(way[i].location-location)<side;i--)
	{
		car c=way[i];

		if(c.lane==this->lane+1&&(c.location-this->location)<side)
			left.push_back(c);
		if(c.lane==this->lane-1&&(c.location-this->location)<side)
			right.push_back(c);
	}
	*/
	if (front.size()>0&& (frontmin<=maxspeed) )
	{
		if(lane<MAXLANE-1&&left.size()==0&&fabs(lasw-time)>SWITCHTIME)
		{
			lane++;
			fp=1;
			lasw=time;
			speed+=5;
			return;
		}
		speed=frontmin;
		return;
	}
	if(front.size()>1)
	{
		if(lane<MAXLANE-1&&left.size()==0)
		{
			lane++;
			lasw=time;
			speed+=5;
			return;
		}
		else if(lane>0&&right.size()==0)
		{
			lane--;
			lasw=time;
			return;
		}
		else
		{
			speed-=10;
			if(speed<0)
				speed=0;
			return;
		}

	}

	if((lane>1||(lane>0 &&rand()%500<1) )&&right.size()==0&&fp!=1&&fabs(lasw-time)>SWITCHTIME)
	{
		lasw=time;
		lane--;
		return;
	}
	if(lane>0&&right.size()!=0&&speed<maxspeed)
	{
		speed+=5;
		return;
	}
	if(front.size()==0&&speed<maxspeed*0.7)
	{
		speed+=5;
		return;
	}
	if(speed>0.7*maxspeed)
		speed-=10;
}
void car::runintdt(double dt)
{
	location+=speed*dt;
}
double car::distance()
{
	return 0.0003*speed+0.001;
}
