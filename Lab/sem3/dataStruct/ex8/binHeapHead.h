#include<iostream>
#include<stdlib.h>
using namespace std;
class College
{
public:
	College(); // Default constructor
	College(string,string,string,int,int,int); // Parameterized constructor	
	College(const College &);
	~College(); // Destructor
	void setNoOfStud(int);
	int getNoOfStud();
	void setNoOfFac(int);
	int getNoOfFac();
	void setCode(int);
	void setName(string);
	void setCity(string);
	void setAcc(string);
	string getAcc();
	string getName();
	string getCity();
	void dispDetails(); // To display the details of the employees
	int getCode();
	friend istream & operator >>(istream &, College &);
private:
	string name,city,acc;
	int noOfStud,noOfFac,code;
	friend class BinHeap;
};
class BinHeap
{
public:
	BinHeap(int);
	int isEmpty();
	int isFull();
	int enqueue(College);
	College dequeue();
	College findMin();
	void display();
private:
	College *C;
	int capacity,hsize;
};
