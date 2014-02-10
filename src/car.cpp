#include "car.h"
#define side 0.01
#define SWITCHTIME 0.002
#define Ethe 4e5
#define ACCIEDENT 0
void car::adapt(std::vector<car>& way,double time,int num)
{
	std::vector<car> left,front,right;
	double frontmin=1000;
	int fp=0;
#if ACCIEDENT==1
	if(rand()%100000<1||broken)
	{
		speed=0;
		broken=1;
		return;
	}
#endif
	//
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
	if(front.size()>0)
	{
		car &fron=front[0];
		dangercol=danger(fron);
		bra=1;
	}
	else
		bra=0;
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
		if(frontmin<1e-2)
		{
#ifdef RIGHTSYS
			if(lane<MAXLANE-1)
				lane++;
			else
				speed=0;
#else
			if(lane>0)
				lane--;
			else
				speed=0;
#endif
			return;
		}
		if(lane<MAXLANE-1&&left.size()==0&&fabs(lasw-time)>SWITCHTIME)
		{
			lane++;
			fp=1;
			lasw=time;
			speed+=5;
			if(speed>maxspeed)
				speed=maxspeed;
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
			if(speed>maxspeed)
				speed=maxspeed;
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
	if(front.size()==0&&(speed<maxspeed*0.7||mind>70000))
	{
		speed+=5;
		if(speed>maxspeed)
			speed=maxspeed;
		return;
	}
	if(mind<80001&&speed>0.7*maxspeed)
		speed-=10;
	if(speed>maxspeed)
		speed=maxspeed;
}
void car::runintdt(double dt)
{
	location+=speed*dt;
}
double car::distance()
{
	return 0.001*speed+0.001;
}


double min(double a,double b)
{
	if(a>b)
		return b;
	return a;
}
double car::danger(car&fron)
{
	double vf=fron.speed*3.6;
	double muf=fron.mu;
	double mur=mu;
	double G=(fron.location-location)*1000;
	double vr=speed*3.6;
	double t1;
	double g=Gravity;
	if(fabs(mur-muf)<1e-3)
	{
		t1=-sqrt(   (-vf+g*mur*tr+vr)*(-vf+g*mur*tr+vr)-g*(mur-muf)*(g*mu*tr+2*G))-vf+g*mur*tr+vr;
		t1/=(g*(mur-muf));
	}
	else
	{
		t1=G+0.5*mur*g*tr;
		t1/=(mur*g*tr+vr-vf);
	}
	double talpha=vf/(muf*g);
	double t2=(vf-sqrt(vf*vf-2*(vr*tr-G)*muf*g  )   )/(mur*g);
	double t3=mur*g*tr+vr-sqrt( (mur*g*tr+vr)*(mur*g*tr+vr) -mur*g*(vf*vf/(muf*g) +2*G+mur*g*tr)  );
	t3/=mur;
	double deltav;
	if( t1>talpha &&tr>talpha )
	{
		deltav=vr;
	}
	else if( t1>talpha && tr<talpha )
		deltav=vr-mur*g*t2;
	else if( t1<talpha && t1<tr )
		deltav=vr-vf+muf*g*t3;
	else if( t1<talpha && t1>tr )
		deltav=vr-mur*g*t1-vf+muf*g*t1;
	dangercol=min(1, (muf*mur)/(2*muf+2*mur)*deltav*deltav/Ethe   );
	
}
double car::mktr()
{
	/*
	 * <=10  0.48
	 20    0.65
	 30    0.76
	 40    0.89
	 50    1.01
	 60    1.14
	 70    1.30
	 80    1.49
	 90    1.78
	 100   2.40
	 */
	int ra;
	if( ( ra=rand()%101)<=10)
		tr=0.48;
	else if(ra<20)
		tr=0.65;
	else if(ra<30)
		tr=0.76;
	else if(ra<40)
		tr=0.89;
	else if(ra<50)
		tr=1.01;
	else if(ra<60)
		tr=1.14;
	else if(ra<70)
		tr=1.30;
	else if(ra<80)
		tr=1.49;
	else if(ra<90)
		tr=1.78;
	else 
		tr=2.4;
}
