#include <GLUT/glut.h>
#include "time.h"
#include <sys/time.h>    
#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "car.h"
#include "highway.h"
// 太阳、地球和月亮
// 假设每个月都是 30 天 //一年12个月,共是360天
highway hw;
long getCurrentTime()  
{  
	struct timeval tv;  
	gettimeofday(&tv,NULL);  
	return tv.tv_sec * 1000000 + tv.tv_usec;  	
}
// 太阳、地球和月亮
// 假设每个月都是 12 天 //一年12个月,共是360天
static int day = 200; // day 的变化:从 0 到 359
double count=-0.5;
void drawCar(car&c)
{
	glRectf(-1.0,1,-0.1,0.97);
	switch(c.lane)
	{
		case 0:
			glColor3f(0,1,1);
			break;
		case 1:
			glColor3f(0,1.0,0);
			break;
		case 2:
			glColor3f(0,0,1);
			break;
		case 3:
			glColor3f(1,0,0);
	}
	int channel=c.location/2;
	double leftloc=c.location-(int)(c.location/2)*2;
	glRectf(leftloc-1.0f,-1.0f+c.lane*0.03+channel*0.15+0.02,leftloc-0.995f,-0.98f+c.lane*0.03+channel*0.15+0.02);
	//glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
}
void roadlines(void)
{
	glColor3f(0,0,0);
	for(int i=0;i<15;i++)
		glRectf(-1,-1+i*0.15-0.005,1,0.005+i*0.15-1);
}
void myDisplay(void) 
{
	hw.evoluation();
	printf("time:%f\n",hw.time);
	glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
	glClearColor(1,1,1,0);
	glColor3f(1.0,1.0,1.0);
	roadlines();
	for(car c:hw.xinway)
	{
		drawCar(c);
	}

	glFlush();
}
long lasttime=0;
void myIdle(void) 
{
	myDisplay();
}
int gl_main(int argc, char *argv[]) 
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(2800, 400);
	glutCreateWindow("HighWay");
	glutDisplayFunc(&myDisplay); 
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return 0;
}
int debug_main()
{
	for(int i=0;i<10000;i++)
		hw.evoluation();
}

int main(int argc, char *argv[]) 
{
	srand(time(NULL));
	gl_main(argc,argv);
}
