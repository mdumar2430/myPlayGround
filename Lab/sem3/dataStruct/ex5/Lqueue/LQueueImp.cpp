#include"LQueue.h"

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

L_Queue::L_Queue()
{
	first=NULL;
}
L_Queue::L_Queue(Node *f)
{
	first=f;
}
L_Queue::L_Queue(const L_Queue &f)
{
	first=f.first;
}
L_Queue::~L_Queue()
{
	first=NULL;
}
int L_Queue::isEmpty()
{
	if(first==NULL)
		return 1;
	else
		return 0;
}
void L_Queue::enqueue(Node *newNode)
{
	if(isEmpty())
		first=newNode;
	else
	{
		Node *temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode;
	}
}

College L_Queue::dequeue()
{
	College del;
	if(!isEmpty())
	{
		Node *temp=first;
		del=temp->data;
		first=first->next;
		delete temp;
		temp=NULL;
		return del;
	}
	else
		return College();
}

College L_Queue::peek()
{
	if(!isEmpty())
		return first->data;
	else
		return College();
}

int L_Queue::checkSize()
{
	Node *temp=first;
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}

int L_Queue::makeQueueEmpty()
{
	if(!isEmpty())
	{
		first=NULL;
		return 1;
	}
	else
		return 0;
}
void L_Queue::displayQueue()
{
	if(!isEmpty())
	{
		Node *temp=first;
		while(temp!=NULL)
		{
			cout<<temp->data;
			temp=temp->next;
		}
	}
	else
		cout<<"\nQueue is Empty,Nothing to display!";
}

