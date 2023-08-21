#include<iostream>
#include<stdlib.h>
#include<string>
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

class Node
{
	private:
		College data;
		Node *next;
	public:
		Node();
		Node(College,Node*);
		Node(const Node &);
		~Node();
		friend class L_Queue;
};

class L_Queue
{
	private:
		Node *first;
	public:
		L_Queue();
		L_Queue(Node *);
		L_Queue(const L_Queue &);
		~L_Queue();
		int isEmpty();
		void enqueue(Node *);
		College dequeue();
		College peek();
		int checkSize();
		int makeQueueEmpty();
		void displayQueue();
};

