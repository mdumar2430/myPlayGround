#include"head.h"
int main()
{
	string name,city,acc;
	int noOfStud,noOfFac,code,cap,mod;
	cout<<"\nEnter capacity:";
	cin>>mod;
	HashTable h(mod);
	int ch=0;
	while(true)
	{
		cout<<"\n\n1.Insert a College.";
		cout<<"\n2.Remove a College.";
		cout<<"\n3.Search a College by code.";
		cout<<"\n4.Find an College.";
		cout<<"\n5.Display College details.";
		cout<<"\n6.Exit.";
		cout<<"\n Enter your option : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"\nEnter the name of the College: ";
					cin>>name;
					cout<<"\nEnter city: ";
					cin>>city;
					cout<<"\nEnter accreditation: ";
					cin>>acc;
					cout<<"\n Enter no.of Students:";
					cin>>noOfStud;
					cout<<"\nEnter no. of faculty:";
					cin>>noOfFac;
					cout<<"\nEnter counselling code:";
					cin>>code;
					College col(name,city,acc,noOfStud,noOfFac,code);
					int temp=h.insert(col,mod);
					if(temp==1)	
						cout<<"\n------>College inserted.";
					else if(temp== -1)
						cout<<"\n------>List is full.";
					else
						cout<<"\n----->Duplicate College cannot be inserted.";
					break;
				}
			case 2:
				{
					int key;
					cout<<"\nEnter the code of the College to be removed.";
					cin>>key;
					int temp=h.remove(key,mod);
					if(temp == -1)
						cout<<"\n---->List is empty.\n";
					else if(temp == -2)
						cout<<"\n---->College not found.";
					else
						cout<<"\n---->College deleted.";
					break;
				}
			case 3:
				{
					int key;
					cout<<"\nEnter the code of the College to be searched:";
					cin>>key;
					int temp=h.search(key,mod);
					if(temp==-1)
						cout<<"\n---->List is empty.";
					else if(temp==-2)
						cout<<"\n---->College not found.";
					else
						cout<<"\n---->College found in the bucket:"<<temp;
					break;
				}
			case 4:
				{
					int key;
					cout<<"\nEnter the code of the College to be searched:";
					cin>>key;
					College srch=h.findElement(key,mod);
					if(srch.getCode() == 0)
						cout<<"\n---->College not found.";
					else
					{
						cout<<"\n Name \t city \t accreditation \t no.of students \t no.of faculty \t code \n";
						srch.dispDetails();
					}
					break;
				}
			case 5:
				{
						cout<<"\n Name \t city \t accreditation \t no.of students \t no.of faculty \t code \n";
						h.display();
						break;
				}
			case 6:
				exit(0);
			default:
				cout<<"\n--->Invalid input.\n";
		}
	}
}

