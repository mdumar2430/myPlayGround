#include"closestPair.h"

Point::Point()
{
	pointNum=0;
	x=0;
	y=0;
}
Point::Point(int p,int x,int y)
{
	pointNum=p;
	this->x=x;
	this->y=y;
}
Point::~Point()
{
}
void Point::setPointNum(int p)
{
	pointNum=p;
}
void Point::setX(int valX)
{
	x=valX;
}
void Point::setY(int valY)
{
	y=valY;
}
int Point::getPointNum()
{
	return pointNum;
}
int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
istream & operator >>(istream &myin ,Point& P)
{
	cout<<"\n Enter Point no.:";
	myin>>P.pointNum;
	P.setPointNum(P.pointNum);
	cout<<"\n Enter X-coordinate:";
	myin>>P.x;
	P.setX(P.x);
	cout<<"\n Enter Y-coordinate:";
        myin>>P.y;
	P.setY(P.y);
	return myin;
}

ostream & operator <<(ostream &out, Point& P)
{	
	out<<"\nP"<<P.getPointNum()<<"("<<P.getX()<<","<<P.getY()<<")\n";
	return out;
}
float computeDistance(Point p1,Point p2)
{
	return pow(pow(p1.getX()-p2.getX(),2)+pow(p1.getY()-p2.getY(),2),0.5);
}

float findClosestPair(Point *P,int size)
{
	float minDist=1000.0;
	float d;
	for(int i=1;i<=size-1;i++)
	{
		for(int j=i+1;j<=size;j++)
		{       
			d=computeDistance(P[i],P[j]);
			if(minDist>d)
				minDist=d;
		}
	}
	return minDist;
}
