#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Line
{
	public:
	
	void draw_line(int x1,int y1,int x2,int y2)
	{
		int x,y,dx,dy;
		int i=0,len,Pk;
		float m;
		
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
	}
	
	void draw_line(float x1,float y1,float x2,float y2)
	{
		float x,y,dx,dy;
		int i=0,len;
		
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
	}
};

int main()
{
	int gd=DETECT,gm;
	int x1,y1,x2,y2;
	int ch;
	Line l;
	
	
	
	cout<<"\n*******************LINE DRAWING ALGORITHMS****************\n";
	cout<<"\n1.DDA\n2.Bresenham's LA\n>>";
	cin>>ch;
	
	switch(ch)
	{
		case 1:
		{
			float x1,y1,x2,y2;
			
			cout<<"\nEnter x1,y1: ";
			cin>>x1>>y1;
			cout<<"\nEnter x2,y2: ";
			cin>>x2>>y2;
			
			initgraph(&gd,&gm,NULL);

			l.draw_line(x1,y1,x2,y2);
			
			break;
		}
		case 2:
		{
			int x1,y1,x2,y2;
			
			cout<<"\nEnter x1,y1: ";
			cin>>x1>>y1;
			cout<<"\nEnter x2,y2: ";
			cin>>x2>>y2;
			
			initgraph(&gd,&gm,NULL);			

			l.draw_line(x1,y1,x2,y2);
			
			break;
		}
	}
	
	delay(5000);
	closegraph();
	return 0;
}

