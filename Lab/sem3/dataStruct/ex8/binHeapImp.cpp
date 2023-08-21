#include"binHeapHead.h"
College::College()
{
	name="";	
	city="";
	acc="";
	code=0;
	noOfFac=0;
	noOfStud=0;
}
College::College(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
	this->name=name;
	this->code=code;
	this->city=city;
	this->acc=acc;
}
College::College(const College & ref)
{
	name=ref.name;
	code=ref.code;
	city=ref.city;
	acc=ref.acc;
	noOfFac=ref.noOfFac;
	noOfStud=ref.noOfStud;
}
College:: ~College()
{
}
void College::setName(string n)
{
	name=n;
}
void College::setCity(string c)
{
	city=c;
}
void College::setAcc(string a)
{
	acc=a;
}
void College::setNoOfStud(int S)
{
	noOfStud=S;
}
void College::setNoOfFac(int f)
{
	noOfFac=f;
}
void College::setCode(int c)
{
	code=c;
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
void College::dispDetails()
{
	cout<<name<<" \t "<<city<<" \t "<<acc<<" \t\t "<<getNoOfStud()<<" \t\t "<<noOfFac<<"\t\t"<<code<<"\n";
}
int College::getCode()
{
	return code;
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
	cout<<"\nEnter College code:";
	myin>>C.code;
	C.setCode(C.code);
	return myin;
}
BinHeap::BinHeap(int cap)
{
	hsize=0;
	capacity=cap;
	C=new College[capacity+1];
}
int BinHeap::isEmpty()
{
	return(hsize==0);
}
int BinHeap::isFull()
{
	return(capacity==hsize);
}
int BinHeap::enqueue(College ins)
{
	if(isFull())
		return -1;
	else
	{
		int ctnode =++hsize;
		while(ctnode!=1 && C[ctnode/2].code>ins.code)
		{
			C[ctnode]=C[ctnode/2];
			ctnode/=2;
		}
		C[ctnode]=ins;
		return 1;
	}
}
College BinHeap::dequeue() //remove an element (delete min)
{
	if(isEmpty())
	{
		College col;
		return col;
	}
	else
	{
		College temp=C[1];
		College last=C[hsize--];
		int low_child=2;
		int ctnode=1;	
		while(low_child <= hsize)
		{
			if(low_child<hsize && C[low_child].code>C[low_child+1].code)
    				low_child++;
			if(last.code<=C[low_child].code) //last element replaced is the min element
    				break;
			C[ctnode]=C[low_child];
			ctnode=low_child;
			low_child=ctnode*2;
		}
		C[ctnode]=last;
		return temp;
	}
}
College BinHeap::findMin() //find minimum element
{
	if(!isEmpty())
		return C[1];	
	else
	{
		College temp;
		return temp;
	}
}
void BinHeap::display() //display the heap
{
	if(isEmpty())
		cout<<"List is Empty\n";
	else
	{
		int i;
		for(i=1;i<=hsize;i++)
			C[i].dispDetails();
	}
}
