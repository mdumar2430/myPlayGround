#include"binHeapHead.h"
int main()
{
	string name,city,acc;
	int code,noOfFac,noOfStud,cap,size;
	cout<<"\nEnter capacity:";
	cin>>cap;
	BinHeap h(cap);
	int ch=0;
	while(ch<=6)
	{
		cout<<"\n1. Insert an College.";
		cout<<"\n2. Remove an College.";
		cout<<"\n3. Find the first College.";
		cout<<"\n4. Display all College details.";
		cout<<"\n5. Exit.";
		cout<<"\n\nEnter your option : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					College ins;
					cin>>ins;
					if(h.enqueue(ins)==1)
						cout<<"\n----------> College inserted <----------.";
					else
						cout<<"\n ---->List is full.";
					break;
				}
			case 2:
				{
					College del=h.dequeue();
					if(del.getCode()==0)
						cout<<"\n ---->List is empty.";
					else
					{
						cout<<"\nName\tCity\tAccreditation\tno.Of Students\tno.Of Faculty\tcode\n";
						del.dispDetails();
					}
					break;
				}
			case 3:
				{
					College temp=h.findMin();
					if(temp.getCode()==0)
						cout<<"\n ----->List is empty.";
					else
					{
						cout<<"\nName\tCity\tAccreditation\tno.Of Students\tno.Of Faculty\tcode\n";
						temp.dispDetails();
					}
					break;
				}
			case 4:
				{
					cout<<"\n Name \t City \t Accreditation \t no.Of Students \t no.Of Faculty \t code \n";
					h.display();
					break;
				}
			case 5:
				exit(0);
			default:
				cout<<"\n Invalid input.\n";
		}
	}
}
