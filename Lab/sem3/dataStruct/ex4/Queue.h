#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

class College
{
	private:
		string name;
		string city;
		string acc;
		int noOfStud;
		int noOfFac;
	public:
		College();
		College(string,string,string,int,int);
		College(const College &);
		~College();
		void setName(string);
		string getName();
		void setCity(string);
		string getCity();
		void setAcc(string);
		string getAcc();
		void setNoOfStud(int);
		int getNoOfStud();
		void setNoOfFac(int);
		int getNoOfFac();
		friend istream & operator >>(istream& ,College&);
		friend ostream & operator <<(ostream& ,College&);
};

class Queue 
{
	private:
		int front;
		int rear;
		int capacity;
		College *arr;
	public:
		Queue();
		Queue(College *,int,int);
		Queue(const Queue &);
		~Queue();
		int getFront();
		int getRear();
		int isEmpty();
		int isFull();
		int enqueue(College);
		College dequeue();
		College peek();
		int checkSize();
		int makeQueueEmpty();
		College * displayQueue();
};
