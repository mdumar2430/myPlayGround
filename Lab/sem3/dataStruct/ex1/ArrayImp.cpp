#include"ArrayHead.h"

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

A_List::A_List()
{
    cap=5;
    size=0;
    arr=new College[cap];
    for(int i=0;i<cap;i++)
        arr[i]=College();
}

A_List::A_List(College *a,int s,int c)
{
    cap=c;
    size=s;
    arr=new College[cap];
    for(int i=0;i<size;i++)
        arr[i]=a[i];
    for(int i=size;i<cap;i++)
        arr[i]=College();
}

A_List::A_List(const A_List &ref)
{
    cap=ref.cap;
    size=ref.size;
    arr=new College[cap];
    for(int i=0;i<cap;i++)
            arr[i]=ref.arr[i];
}
College* A_List::getArr()
{
    return arr;
}

A_List::~A_List()
{
    delete []arr;
    arr=NULL;
}
int A_List::isFull()
{
    if(size==cap)
        return 1;
    else 
        return 0;
}
int A_List::isEmpty()
{
    if(size==0)
        return 1;
    else 
        return 0;
}
int A_List::insertAtFirst(College ins)
{
    if(!isFull())
    {
        if(isEmpty())
        {
            arr[size++]=ins;
        }
        else
        {
            int i;
            for(i=size;i>0;i--)
                arr[i]=arr[i-1];
            arr[i]=ins;
            size++;
        }
        return 1;
    }
    else 
        return 0;
}
College* A_List::displayList()
{
    College *temp=new College[10];
    if(!isEmpty())
        return arr;
    else
        return temp;
}
int A_List::insertAtLast(College ins)
{
    if(!isFull())
    {
	cout<<"\nChecking";
        arr[size++]=ins;
        return 1;
    }
    else
        return 0;
}
int A_List::insertByPos(College ins,int pos)
{
    if(!isFull())
    {
        if((isEmpty())&&(pos==1))
        {
            insertAtFirst(ins);
	    return 1;
        }
        else if(pos==size+1)
        {
            insertAtLast(ins);
	    return 1;
        }
        else
	{
	    if(pos>size+1)
		    return 0;
            for(int i=size;i>=pos;i--)
                    arr[i]=arr[i-1];
            arr[pos-1]=ins;
            size++;
            return 1;
        }
    }
    else
        return 0;

}
int A_List::deleteAtFirst()
{
    if(!isEmpty())
    {
        if(size==1)
        {
            arr[0]=College();
            size--;
            return 1;
        }
        else
        {
            int i;
            for(i=0;i<size-1;i++)
                arr[i]=arr[i+1];
            arr[i]=College();
            size--;
            return 1;
        }
    }
    else
        return 0;
}
int A_List::deleteAtLast()
{
    if(!isEmpty())
    {
        arr[size-1]=College();
        size--;
        return 1;
    }
    else
        return 0;
}
int A_List::deleteByPos(int pos)
{
    if(!isEmpty()&&(pos<size))
    {
        int i;
        for(i=pos-1;i<size-1;i++)
            arr[i]=arr[i+1];
        arr[i]=College();
        size--;
        return 1;
    }
    else if(!isEmpty()&&(pos==size))
    {
        arr[pos-1]=College();
        size--;
        return 1;
    }
    else
        return 0;
}
College A_List::searchByPos(int pos)
{
    if(!isEmpty()&&(pos<=size))
        return arr[pos-1];
    else
        return College();
}
int A_List::makeListEmpty()
{
    if(!isEmpty())
    {
        size=0;
        return 1;
    }
    else
        return 0;
}



