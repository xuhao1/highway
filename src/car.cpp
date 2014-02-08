#include "car.h"

void car::adapt(std::vector<car>& way)
{
	for(car c:way)
	{
		if(c.id!=this->id)
			continue;
	}
}
void car::runintdt(double dt)
{
	location+=speed*dt;
}
