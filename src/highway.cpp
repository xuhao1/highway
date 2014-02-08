#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include "string.h"
#include <fstream>
//First simulate use Margolus neighbor
//Sand Rule
#define MAXN 100
int road[MAXN][4]={0};
int temproad[MAXN][4]={0};
int sandrole[16]={0};
void Iteration();
int Iteration4point(int);
void evoluation()
{
	road[0][1]=rand()%20<1;	
	road[0][2]=rand()%20<1;	
	road[0][3]=rand()%20<1;	
	road[0][0]=rand()%20<1;	
	
	Iteration();
}
void Iteration()
{
	int key,upkey;
	memset(temproad,0,sizeof(temproad) );	
	for(int i=0;i<MAXN-1;i++)
		for(int j=0;j<1;j++)
		{
			key=road[i][j]*8+road[i][j+1]*4+road[i+1][j]*2+road[i+1][j+1];
			upkey=Iteration4point(key);
			
			key=upkey;
			if(key/8>0)
				temproad[i][j]=1;
			key=key%8;
			
			if(key/4>0)
				temproad[i][j+1]=1;
			key=key%4;

			if(key/2>0)
				temproad[i+1][j]=1;
			key=key%2;

			temproad[i+1][j+1]=(key>0);
		}
	memcpy(road,temproad,sizeof(road) );
}
int Iteration4point(int i)
{
	sandrole[8]=2;
	sandrole[4]=1;
	
	sandrole[12]=3;
	sandrole[5]=3;
	sandrole[6]=3;
	sandrole[9]=3;
	sandrole[10]=3;

	sandrole[13]=7;
	sandrole[14]=11;

	return sandrole[i];
}

int main()
{
	for(int i=0;i<1000;i++)
	{
		evoluation();

		char *path=new char[100];
		sprintf(path,"data/data%d.txt",i);
		std::ofstream ofi(path);
		for(int i=0;i<MAXN;i++)
		{
			for(int j=0;j<4;j++)
				ofi<<road[i][j]<<" ";
			ofi<<"\n";
		}
	}
	return 0;
}
