#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

int main()
{
	int gd=DETECT,gm;
	int x,y,x1,y1,x2,y2,dx,dy;
	int i=0,len,Pk;
	float m;
	
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
	
	dx=x2-x1;
	dy=y2-y1;
	
	m=dy/dx;
	
	x=x1;
	y=y1;
			
	Pk=(2*dy-dx);
	
	if(m<1)
	{
		while(i<len)
		{
			if(Pk>=0)
			{
				putpixel(x,y,3);
				delay(100);
				x=x+1;
				y=y+1;
				Pk=(Pk+(2*dy)-(2*dx));
				
			}
			else
			{
				putpixel(x,y,3);
				delay(100);
				x=x+1;
				Pk=Pk+(2*dy);
				
			}
			
			i++;
		}
	}
	else if(m>1)
	{
		while(i<len)
		{
			if(Pk>=0)
			{
				putpixel(x,y,3);
				delay(100);
				x=x+1;
				y=y+1;
				Pk=(Pk+(2*dx)-(2*dy));
			}
			else
			{
				putpixel(x,y,3);
				delay(100);
				y=y+1;
				Pk=Pk+(2*dx);	
			}			
			i++;
		}
	}
	else
	{
		while(i<len)
		{
			putpixel(x,y,3);
			delay(100);
			x++;
			y++;
			i++;
		}
	}	
	
	delay(5000);
	closegraph();
	return 0;
}

