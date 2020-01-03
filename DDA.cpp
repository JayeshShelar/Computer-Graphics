#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
	int gd=DETECT,gm;
	int x,y,x1,y1,x2,y2,dx,dy;
	int i=0,len;
	
	cout<<"\nEnter x1,y1: ";
	cin>>x1>>y1;
	cout<<"\nEnter x2,y2: ";
	cin>>x2>>y2;
	
	initgraph(&gd,&gm,NULL);
	
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	
	if(dx>=dy)
	{
		len=dx;
	}
	else
	{
		len=dy;
	}
	
	dx=(x2-x1)/len;
	dy=(y2-y1)/len;
	
	if(dx>0)
	{
	x=x1+0.5;
	y=y1+0.5;
	}
	else
	{
	x=x1-0.5;
	y=y1-0.5;
	}	
	
	while(i<len)
	{
		putpixel(x,y,3);
		x=x+dx;
		y=y+dy;
		i++;
		delay(100);
	}
	
	delay(5000);
	closegraph();
	return 0;
}

