#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	private:	
		int pointNum;
		int x;
		int y;
	public:
		Point();
		Point(int,int,int);
		~Point();
		void setPointNum(int);
		void setX(int);
		void setY(int);
		int getX();
		int getY();
		int getPointNum();
		friend istream & operator >>(istream& ,Point&);
		friend ostream & operator <<(ostream& ,Point&);
};
float computeDistance(Point,Point);   
float findClosestPair(Point* ,int ); 
