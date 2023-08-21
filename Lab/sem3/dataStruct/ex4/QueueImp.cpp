#include"Queue.h"

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

Queue::Queue()
{
	front=-1;
	rear=-1;
	capacity=5;
	arr=new College[capacity];
	for(int i=0;i<capacity;i++)
		arr[i]=College();
}

Queue::Queue(College *det,int size,int cap)
{
	front=0;
	rear=size-1;
	capacity=cap;
	arr=new College[cap];
	for(int i=front;i<=rear;i++)
		arr[i]=det[i];
	for(int i=rear+1;i<cap;i++)
		arr[i]=College();
}

Queue::Queue(const Queue &ref)
{
	front=ref.front;
	rear=ref.rear;
	capacity=ref.capacity;
	arr=new College[capacity];
	for(int i=front;i<=rear;i++)
		arr[i]=ref.arr[i];
	for(int i=rear+1;i<capacity;i++)
		arr[i]=College();
}
Queue::~Queue()
{
	delete [] arr;
	arr=NULL;
}
/*int Queue::getFront()
{
	return front;
}
int Queue::getRear()
{
	return rear;
}*/
int Queue::isFull()
{
	if(capacity==rear+1)
		return 1;
	else
		return 0;
}
int Queue::isEmpty()
{
	if((front==-1 && rear==-1) || (front>rear))
		return 1;
	else
		return 0;
}

int Queue::enqueue(College ins)
{
	if(!isFull())
	{
		if(front==-1 && rear==-1)
		{
			front =0;
			rear=0;
			arr[rear]=ins;
		}
		else
		{
			arr[++rear]=ins;
		}
		return 1;
	}
	else
		return 0;
}

College Queue::dequeue()
{
	if(!isEmpty())
	{
		College deletedEntry;
		deletedEntry=arr[front];
		if(front==0 && rear==0)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front++;
		}
		return deletedEntry;
	}
	else
		return College();
}

College Queue::peek()
{
	if(!isEmpty())
		return arr[front];
	else
		return College();
}
int Queue::checkSize()
{
	return (rear-front)+1;
}
int Queue::makeQueueEmpty()
{
	if(!isEmpty())
	{
		front=-1;
		rear=-1;
		return 1;
	}
	else
		return 0;
}

College* Queue::displayQueue()
{
	College *temp=new College[10];
	College *queue=new College[10];
	if(!isEmpty())
	{
		for(int i=0;i<=(rear-front);i++)
			queue[i]=arr[i+front];
		return queue;
	}
	else
		return temp;
}
