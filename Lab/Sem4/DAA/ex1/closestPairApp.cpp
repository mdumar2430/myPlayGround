#include"closestPair.h"

int main()
{
	int size;
	cout<<"\n----------------Closest Pair by  Brute Force----------------";
	cout<<"\nEnter number of Points:";
	cin>>size;
	Point *p=new Point[size];
	cout<<"\n -------------Enter the Points----------------";
	for(int i=0;i<size;i++)
	{
		cin>>p[i];
	}
	cout<<"\n Given Points are:\n";
	for(int i=0;i<size;i++)
		cout<<p[i];
	float ans;
	ans=findClosestPair(p,size);
	cout<<"\nDistance between them: "<<ans<<"\n";
}
