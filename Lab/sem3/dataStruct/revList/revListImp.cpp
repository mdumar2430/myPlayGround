#include"revList.h"

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
	prev=NULL;
}
Node::Node(College data,Node *n,Node *p)
{
	this->data=data;
	next=n;
	prev=p;
}
Node::Node(const Node &ref)
{
	data=ref.data;
	next=ref.next;
	prev=ref.prev;
}
Node::~Node()
{
	data=College();
	next=NULL;
	prev=NULL;
}

L_List::L_List()
{
	first=NULL;
}
L_List::L_List(Node *f)
{
	first=f;
}
L_List::L_List(const L_List &f)
{
	first=f.first;
}
L_List::~L_List()
{
	first=NULL;
}
int L_List::isEmpty()
{
	if(first==NULL)
		return 1;
	else
		return 0;
}
void L_List::insertAtFirst(Node *newNode)
{
	if(isEmpty())
		first=newNode;
	else
	{
		newNode->next=first;
		first->prev=newNode;
		first=newNode;
	}
}

void L_List::insertAtLast(Node *newNode)
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
		newNode->prev=temp;
		temp->next=newNode;
	}
}

int L_List::deleteAtFirst()
{
	if(!isEmpty())
	{
		Node *temp=first;
		first=first->next;
		delete temp;
		temp=NULL;
		return 1;
	}
	else
		return 0;
}

int L_List::deleteAtLast()
{
	if(!isEmpty())
	{
		Node *temp=first;
		if(temp->next==NULL)
		{
			first=NULL;
			return 1;
		}
		Node *prev=first;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		prev->next=NULL;
		temp=NULL;
		delete temp;
		return 1;
	}
	else
		return 0;
}

int L_List::insertByPos(Node *newNode,int pos)
{
	if(!isEmpty())
	{
		int i=1;
		Node *temp=first;
		if(pos==1)
		{
			insertAtFirst(newNode);
			return 1;
		}
		while(temp->next!=NULL && i!=pos-1)
		{
			temp=temp->next;
			i++;
		}
		if(i==pos-1)
		{
			newNode->next=temp->next;
			temp->next=newNode;
			return 1;
		}
		return 0;
	}
	else
	{
		if(pos==1)
		{
			insertAtFirst(newNode);
			return 1;
		}
		return 0;
	}
}

int L_List::deleteByPos(int pos)
{
	if(!isEmpty())
	{
		if(pos==1)
		{
			Node *temp=first;
			first=first->next;
			delete temp;
			temp=NULL;
			return 1;
		}
		else
		{
			Node *temp=first;
			Node *prev=first;
			int i=1;
			while(temp->next!=NULL && i!=pos)
			{
				prev=temp;
				temp=temp->next;
				i++;
			}
			if(i==pos)
			{
				prev->next=temp->next;
				delete temp;
				temp=NULL;
				return 1;
			}
			return 0;
		}
	}
	else
		return 0;
}

int L_List::replaceElementByPos(Node *newNode,int pos)
{
	if(!isEmpty())
	{
		if(pos==1)
		{
			Node *temp=first;
			newNode->next=temp->next;
			first=newNode;
			delete temp;
			temp=NULL;
			return 1;
		}
		else
		{
			Node *temp=first;
			Node *prev=first;
			int i=1;
			while(temp->next!=NULL && i!=pos)
			{
				prev=temp;
				temp=temp->next;
				i++;
			}
			if(i==pos)
			{
				newNode->next=temp->next;
				prev->next=newNode;
				delete temp;
				temp=NULL;
				return 1;
			}
			return 0;
		}		
	}
	else
		return 0;
}

College L_List::searchByPos(int pos)
{
	if(!isEmpty())
	{
		Node *temp=first;
		int i=1;
		while(temp->next!=NULL && i!=pos)
		{
			temp=temp->next;
			i++;
		}
		if(i==pos)
			return temp->data;
		else
			return College();
	}
	else
		return College();
}
 
int L_List::makeListEmpty()
{
	if(!isEmpty())
	{
		first=NULL;
		return 1;
	}
	else
		return 0;
}
void L_List::displayList()
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
		cout<<"\nList is Empty,Nothing to display!";
}

void L_List::reverseList(){
	Node *temp = first; 
	if(!isEmpty()){
		while(temp->next!=NULL){
			temp= temp->next;
		}
		temp= temp->next;
		first= temp;
		while(temp!=NULL){
			Node *t;
			t= temp->prev;
			temp->prev = temp->next;
			temp->next = temp->prev;
			cout<<temp->data;
			temp=temp->next;
		}
	}
}
