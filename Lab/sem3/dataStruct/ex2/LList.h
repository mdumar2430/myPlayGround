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
		friend class L_List;
};
class L_List
{
	private:
		Node *first;
	public:
		L_List();
		L_List(Node *);
		L_List(const L_List &);
		~L_List();
		int isEmpty();
		void insertAtFirst(Node *);
		void insertAtLast(Node  *);
		int insertByPos(Node *,int);
		int deleteAtFirst();
		int deleteAtLast();
		int deleteByPos(int);
		int replaceElementByPos(Node *,int);
		College searchByPos(int );
		int makeListEmpty();
		void displayList();
		void reverseList();
};

