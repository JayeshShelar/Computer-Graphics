#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class Line
{
	
	public:
	void dda(int x1, int y1, int x2, int y2)
	{
		int x,y,dx,dy;
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
			delay(10);
		}
		
	}	
	
	void dotted(int x1, int y1, int x2, int y2)
	{
		int gd=DETECT,gm;
		
		int x,y,dx,dy;
		int i=0,len;
		
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
			if(i%2 == 0)
			{
				putpixel(x,y,3);
			}
			
			x=x+dx;
			y=y+dy;
			i++;
			delay(100);
		}
	
		delay(5000);
		closegraph();
		
	}
	
	void dashed(int x1, int y1, int x2, int y2)
	{
		int gd=DETECT,gm;
		
		int x,y,dx,dy;
		int i=0,len,flag=0;
		
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
			if(flag<4)
			{
				putpixel(x,y,3);
				flag++;
			}
			else
			{
				flag++;
				if(flag==8)
				{
					flag=0;
				}
			}
			
			x=x+dx;
			y=y+dy;
			i++;
			delay(100);
		}
	
		delay(5000);
		closegraph();
		
	}
	
	void dotted_dashed(int x1,int y1,int x2,int y2)
	{
		int gd=DETECT,gm;
		
		int x,y,dx,dy;
		int i=0,len,flag=0;
		
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
			if(flag<4)
			{
				putpixel(x,y,3);
				flag++;
			}
			else
			{
				flag++;
				if(flag==7)
				{
					putpixel(x,y,3);
				}
				if(flag==10)
				{
					flag=0;
				}
			}
			
			x=x+dx;
			y=y+dy;
			i++;
			delay(100);
		}
	
		delay(5000);
		closegraph();
		
	}
	
	
};

int main()
{
	int gd=DETECT,gm;	
	Line l;
	
	int x1,y1,x2,y2,ch;
	
	cout<<"\n\n*******************LINE PATTERNS*******************\n\n";
	cout<<"1.Dotted\n2.Dashed\n3.Dotted Dashed\n4.Thick\n>>";
	cin>>ch;
	
	cout<<"\nEnter x1,y1: ";
	cin>>x1>>y1;
	cout<<"\nEnter x2,y2: ";
	cin>>x2>>y2;	
	
	
	
	switch(ch)
	{
		case 1:
		{
			l.dotted(x1,y1,x2,y2);
			break;
		}
		case 2:
		{
			l.dashed(x1,y1,x2,y2);
			break;	
		}
		case 3:
		{
			l.dotted_dashed(x1,y1,x2,y2);
			break;
		}
		case 4:
		{
			int w;	
			cout<<"\nEnter thickness: ";
			
			cin>>w;
			initgraph(&gd,&gm,NULL);
			float wx,wy,m;
			m=(y2-y2)/(x2-x1);
			
			if(m < 1)
			{
				//wy = ((w-1)/2) * sqrt( pow((x1-x1),2) + pow((y2-y1),2) )/ (abs(x2-x1));
				wy = ((w-1)) * sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
				wy=wy/2;
				wy=wy/(abs(x2-x1));
				
				for(int i=0;i<wy;i++)
				{
					l.dda(x1,y1+i,x2,y2+i);
					l.dda(x1,y1,x2,y2);
					l.dda(x1,y1-i,x2,y2-i);
				}
			}
			else
			{
				//wx = ((w-1)/2) * sqrt( pow((x1-x1),2) + pow((y2-y1),2) )/ (abs(y2-y1));
				wx = ((w-1)) * sqrt( pow((x2-x1),2) + pow((y2-y1),2) );
				wx=wx/2;
				wx=wx/(abs(y2-y1));
				
				
				for(int i=0;i<wx;i++)
				{
					l.dda(x1+i,y1,x2+i,y2);
					l.dda(x1,y1,x2,y2);
					l.dda(x1-i,y1,x2-i,y2);
				}
			}
			
			break;
		}
	}	
	closegraph();
	return 0;
}

