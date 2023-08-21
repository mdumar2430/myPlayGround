#include"LStack.h"
int main()
{
	int ch,i,flag,pos;
	College col,res;
	L_Stack s;
	do
	{
		cout<<"\n\n|>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<|";
		cout<<"\n1.Insert at First\n2.Delete at First\n3.Display First Entry\n4.Check size\n5.Make Stack Empty\n6.Display Stack\n7.Exit\n|----------------------------------------|\n>>Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1://Push
				{
					cout<<"\n\t*************Enter College details to insert at first*************\n";
					cin>>col;
					Node *ins=new Node(col,NULL);
					s.push(ins);
					cout<<"\n---------->INSERTION SUCCESSFUL<----------";
				}
				break;
			case 2://Pop
				cout<<"\n****************Deleting First Entry****************\n";
				res=s.pop();
				if(res.getNoOfStud()!=0)
				{
					cout<<"\n---------->DELETION SUCCESSFUL<----------";
					cout<<"\nDeleted Entry:-\n";
					cout<<res;
				}
				else
					cout<<"\n---------->DELETION FAILED!<----------";
				break;
			case 3://Peek
				cout<<"\n****************Displaying First Entry****************\n";
				res=s.peek();
				if(res.getNoOfStud()!=0)
					cout<<res;
				else
					cout<<"\n---------->No ELEMENT FOUND!<----------";
				break;
			case 4://Check Size
				flag=s.checkSize();
				cout<<"\nSize of the Stack is:"<<flag;
				break;
			case 5://Make Stack Empty
				 flag=s.makeStackEmpty();
				 if(flag==1)
					 cout<<"\n------------->Stack is Emptied now!<-------------";
				 else 
					 cout<<"\n------------->Stack is already Empty<-------------";
				 break;
			case 6://Display stack
				 s.displayStack();
				 break;
			case 7:ch=8;break;
			default:cout<<"\nInvalid Choice!";break;
		}
	}while(ch<=7);

}
