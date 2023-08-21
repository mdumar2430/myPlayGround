#include"Stack.h"

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

Stack::Stack()
{
    top=-1;
    capacity=5;
    arr=new College[capacity];
    for(int i=0;i<capacity;i++)
        arr[i]=College();
}

Stack::Stack(int size,int cap,College *det)
{
    top=size-1;
    capacity=cap;
    arr=new College[cap];
    for(int i=0;i<=top;i++)
        arr[i]=det[i];
    for(int i=top+1;i<cap;i++)
        arr[i]=College();
}

Stack::Stack(const Stack &ref)
{
    top=ref.top;
    capacity=ref.capacity;
    arr=new College[capacity];
    for(int i=0;i<=top;i++)
        arr[i]=ref.arr[i];
    for(int i=top+1;i<capacity;i++)
        arr[i]=College();
}
Stack::~Stack()
{
    delete [] arr;
    arr=NULL;
}

int Stack::isFull()
{
    if(capacity==top+1)
        return 1;
    else
        return 0;
}
int Stack::isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

int Stack::push(College ins)
{
    if(!isFull())
    {
        arr[++top]=ins;
        return 1;
    }
    else
        return 0;
}

College Stack::pop()
{
    if(!isEmpty())
    {
        College deletedEntry;
        deletedEntry=arr[top];
        arr[top]=College();
        top--;
        return deletedEntry;
    }
    else
        return College();
}

College Stack::peek()
{
    if(!isEmpty())
        return arr[top];
    else
        return College();
}
int Stack::checkSize()
{
    return top+1;
}
int Stack::makeStackEmpty()
{
    if(!isEmpty())
    {
        top=-1;
        return 1;
    }
    else
        return 0;
}

College* Stack::displayStack()
{
    College *temp=new College[10];
    if(!isEmpty())
        return arr;
    else
        return temp;
}
