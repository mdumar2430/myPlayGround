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
		friend class L_Stack;
};

class L_Stack
{
	private:
		Node *top;
	public:
		L_Stack();
		L_Stack(Node *);
		L_Stack(const L_Stack &);
		~L_Stack();
		int isEmpty();
		void push(Node *);
		College pop();
		College peek();
		int checkSize();
		int makeStackEmpty();
		void displayStack();
};

