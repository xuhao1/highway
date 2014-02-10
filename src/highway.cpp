#include "highway.h"

//First simulate use Margolus neighbor
//Sand Rule

#define MAXN 10
void highway::evoluation()
{
	if( rand()%randColl <1)
	{
		num++;
		xinway.push_back(car(rand()%3,rand()%MAXLANE,num,10000)) ;
	}
	time+=dt;
	Iteration();
}

void highway::Iteration()
{
	double sum=0;
	double dsum=0;
	qsort(xinway,0,xinway.size()-1);
	np=0;
	for(int i=0;i<xinway.size();i++)
	{
		car &c=xinway[i];
		c.adapt(xinway,time,i);
		sum+=c.speed;
		dsum+=c.dangercol;
		np+=c.bra;
	}
	char c;

	for(car &c:xinway)
	{
		c.runintdt(dt);
	}
	avsped=sum/xinway.size();
	dangercol=dsum/xinway.size();
}

void highway::qsort(std::vector<car>&a,int l,int r)
{
	if(l==r)
		return;
	int i,j;
	i=l;j=r;
	car k=a[i];
	while(i<j)
	{
		while(i<j&&a[j].location>k.location)
			j--;
		a[i]=a[j];
		while(i<j&&a[i].location<=k.location)
			i++;
		a[j]=a[i];
	}
	a[i]=k;
	if(i-l>1)
		qsort(a,l,i-1);
	if(r-i>1)
		qsort(a,i+1,r);
}
