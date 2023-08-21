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

class Stack
{
    private:
        int top;
        int capacity;
        College *arr;
    public:
        Stack();
        Stack(int,int,College *);
        Stack(const Stack &);
        ~Stack();
        int isEmpty();
        int isFull();
        int push(College);
        College pop();
        College peek();
        int checkSize();
        int makeStackEmpty();
        College * displayStack();
};
