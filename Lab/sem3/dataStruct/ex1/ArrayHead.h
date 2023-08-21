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

class A_List
{
    private:
        College *arr;
        int size;
        int cap;
    public:
        A_List();
        A_List(College *,int,int);
        A_List(const A_List &);
        ~A_List();
        College* getArr();
        int isEmpty();
        int isFull();
        College* displayList();
        int insertAtFirst(College );
        int insertAtLast(College );
        int insertByPos(College ,int);
        int deleteAtFirst();
        int deleteAtLast();
        int deleteByPos(int);
        College searchByPos(int);
        int makeListEmpty();
};





            

