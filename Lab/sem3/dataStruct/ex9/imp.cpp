#include"head.h"
College::College()
{
	name="";
	city="";
	acc="";
	code=0;
	noOfStud=0;
	noOfFac=0;
}
College::College(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
	this->name=name;
	this->city=city;
	this->acc=acc;
	this->code=code;
	this->noOfStud=noOfStud;
	this->noOfFac=noOfFac;
}
College::College(const College & col)
{
	name=col.name;
	city=col.city;
	acc=col.acc;
	code=col.code;
	noOfStud=col.noOfStud;
	noOfFac=col.noOfFac;
}
College:: ~College()
{
	name="";
	city="";
	acc="";
	noOfStud=0;
	noOfFac=0;
	code=0;
}

void College::dispDetails()
{
	cout<<name<<"\t"<<city<<"\t"<<acc<<"\t\t"<<noOfStud<<"\t\t\t"<<noOfFac<<"\t\t"<<code<<"\n";
}
int College::getCode()
{
	return code;
}
HashTable :: HashTable(int mod)
{
	capacity =mod;
	C= new College[capacity];
	size =0;
}
int HashTable :: hash(int code,int mod)
{
	return code%mod;
}
int HashTable::insert(College ins,int mod)
{
	if(size==capacity)
		return -1;
	int hashval=hash(ins.getCode(),mod);
	while(C[hashval].getCode()!=0 && C[hashval].getCode()!=ins.getCode())
	{
		hashval=hash(hashval+1,mod);
	}
	if(C[hashval].getCode()==ins.getCode())
		return -2;
	C[hashval]=ins;
	size++;
	return 1;
}
int HashTable::remove(int code,int mod)
{
	if(size==0)
		return -1;
	int hashval=hash(code,mod);
	int flag=0;
	while(flag <= hashval)	
	{
		if(C[hashval].getCode()!=code)
		{
			hashval=hash(hashval+1,mod);
			flag++;
		}
		else
		{
			C[hashval].~College();
			size--;
			return 1;
		}
	}
	return -2;
}
int HashTable::search(int code,int mod)
{
	if(size==0)
		return -1;
	int hashval=hash(code,mod);
	int flag=0;
	while(flag <= hashval)
	{
		if(C[hashval].getCode()!=code)
		{
			hashval=hash(hashval+1,mod);
			flag++;
		}
		else
			return hashval;
	}
	return -2;
}
College HashTable::findElement(int code,int mod)
{
	College col;
	if(size==0)
		return col; //hash table is empty
	int hashval=hash(code,mod);
	int flag=0;
	while(flag <= hashval)
	{
		if(C[hashval].getCode()!=code)
		{
			hashval=hash(hashval+1,mod);
			flag++;
		}
		else
			return C[hashval]; //element is found
	}
	return col; //element not found
}
void HashTable::display() //display all elements
{
	if(size==0)
		cout<<"No Employees in the list\n";
	else
	{
	int i;
	for(i=0;i<capacity;i++)
		C[i].dispDetails();
	}
}