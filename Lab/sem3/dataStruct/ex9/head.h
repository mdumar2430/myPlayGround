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
	void dispDetails(); 
	int getCode();
private:
	string name,city,acc;
	int code,noOfStud,noOfFac;
	friend class HashTable;
};
class HashTable //hashtable (linear probing)
{
public:
	HashTable(int);
	int hash(int,int); //hash function
	int insert(College,int); //insert an element
	int remove(int,int); //remove an element
	int search(int,int); //search for an element
	College findElement(int,int); //find an element
	void display(); //display all elements
private:
	int capacity; //bucket size
	int size; //size
	College *C; 
};
