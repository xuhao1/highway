#include <GLUT/glut.h>
#include "time.h"
#include <sys/time.h>    
#include <iostream>
#include "stdio.h"
#include "stdlib.h"

// 太阳、地球和月亮
// 假设每个月都是 30 天 //一年12个月,共是360天
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
void myDisplay(void) 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glColor3f(1.0,0,0);
	count+=0.01;
	if(count>0.5)
		count=-0.5;
	glRectf(-0.5f+count, -0.5f, 0.5f+count, 0.5f);

	glBegin(GL_LINES);
		glVertex2i(180,15);
		glVertex2i(10,145);
	glEnd();

	glFlush();
}
long lasttime=0;
void myIdle(void) 
{
	long now=getCurrentTime();
	if(now-lasttime>1000)
		myDisplay();
}
int main(int argc, char *argv[]) 
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 100);
	glutInitWindowSize(400, 400);
	glutCreateWindow("HighWay");
	glutDisplayFunc(&myDisplay); 
	glutIdleFunc(&myIdle);
	glutMainLoop();
	return 0;
}
