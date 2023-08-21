#include"LStack.h"

College::College()
{
	name="";
	city="";
	acc="";
	noOfStud=0;
	noOfFac=0;
}

College::College(string name,string city,string acc,int noOfStud,int noOfFac)
{
	this->name=name;
	this->city=city;
	this->acc=acc;
	this->noOfStud=noOfStud;
	this->noOfFac=noOfFac;
}
College::College(const College &ref)
{
	name=ref.name;
	city=ref.city;
	acc=ref.acc;
	noOfFac=ref.noOfFac;
	noOfStud=ref.noOfStud;
}
College::~College()
{
}
void College::setName(string x)
{
	name=x;
}
void College::setCity(string x)
{
	city=x;
}
void College::setAcc(string x)
{
	acc=x;
}
void College::setNoOfStud(int x)
{
	noOfStud=x;
}
void College::setNoOfFac(int x)
{
	noOfFac=x;
}
string College::getName()
{
	return name;
}
string College::getCity()
{
	return city;
}
string College::getAcc()
{
	return acc;
}
int College::getNoOfStud()
{
	return noOfStud;
}
int College::getNoOfFac()
{
	return noOfFac;
}

istream & operator >>(istream& myin ,College& C)
{
	cout<<"\nEnter the name of the College:";
	myin>>C.name;
	C.setName(C.name);
	cout<<"\nEnter the city name:";
	myin>>C.city;
	C.setCity(C.city);
	cout<<"\nEnter Accreditations of the college:";
	myin>>C.acc;
	C.setAcc(C.acc);
	cout<<"\nEnter no. of students studying:";
	myin>>C.noOfStud;
	C.setNoOfStud(C.noOfStud);
	cout<<"\nEnter no. of faculty working:";
	myin>>C.noOfFac;
	C.setNoOfFac(C.noOfFac);
	return myin;
}
ostream & operator <<(ostream& myout ,College& C)
{
	myout<<"\n\nName:"<<C.getName();
	myout<<"\nCity:"<<C.getCity();
	myout<<"\nAccreditations:"<<C.getAcc();
	myout<<"\nNo. of Students:"<<C.getNoOfStud();
	myout<<"\nNo. of Faculty:"<<C.getNoOfFac();
	return myout;
}

Node::Node()
{
	data=College();
	next=NULL;
}
Node::Node(College data,Node *n)
{
	this->data=data;
	next=n;
}
Node::Node(const Node &ref)
{
	data=ref.data;
	next=ref.next;
}
Node::~Node()
{
	data=College();
	next=NULL;
}

L_Stack::L_Stack()
{
	top=NULL;
}
L_Stack::L_Stack(Node *f)
{
	top=f;
}
L_Stack::L_Stack(const L_Stack &f)
{
	top=f.top;
}
L_Stack::~L_Stack()
{
	top=NULL;
}
int L_Stack::isEmpty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
void L_Stack::push(Node *newNode)
{
	if(isEmpty())
		top=newNode;
	else
	{
		newNode->next=top;
		top=newNode;
	}
}

College L_Stack::pop()
{
	if(!isEmpty())
	{
		Node *temp=top;
		College del=temp->data;
		top=top->next;
		delete temp;
		temp=NULL;
		return del;
	}
	else
		return College();
}

College L_Stack::peek()
{
	if(!isEmpty())
		return top->data;
	else
		return College();
}

int L_Stack::checkSize()
{
	Node *temp=top;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

int L_Stack::makeStackEmpty()
{
	if(!isEmpty())
	{
		top=NULL;
		return 1;
	}
	else
		return 0;
}
void L_Stack::displayStack()
{
	if(!isEmpty())
	{
		Node *temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	else
		cout<<"\nStack is Empty,Nothing to display!";
}

