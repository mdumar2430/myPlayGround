#include"LQueue.h"
int main()
{
	int ch,i,flag,pos;
	College col,res;
	L_Queue q;
	do
	{
		cout<<"\n\n|>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<|";
		cout<<"\n1.Insert at Last\n2.Delete at First\n3.Display First Entry\n4.Check size\n5.Make Queue Empty\n6.Display Queue\n7.Exit\n|----------------------------------------|\n>>Enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1://Enqueue
				{
					cout<<"\n\t*************Enter College details to insert at Last*************\n";
					cin>>col;
					Node *ins=new Node(col,NULL);
					q.enqueue(ins);
					cout<<"\n---------->INSERTION SUCCESSFUL<----------";
				}
				break;
			case 2://Dequeue
				cout<<"\n****************Deleting First Entry****************\n";
				res=q.dequeue();
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
				res=q.peek();
				if(res.getNoOfStud()!=0)
					cout<<res;
				else
					cout<<"\n---------->No ELEMENT FOUND!<----------";
				break;
			case 4://Check Size
				flag=q.checkSize();
				cout<<"\nSize of the Queue is:"<<flag;
				break;
			case 5://Make Queue Empty
				 flag=q.makeQueueEmpty();
				 if(flag==1)
					 cout<<"\n------------->Queue is Emptied now!<-------------";
				 else 
					 cout<<"\n------------->Queue is already Empty<-------------";
				 break;
			case 6://Display stack
				 q.displayQueue();
				 break;
			case 7:ch=8;break;
			default:cout<<"\nInvalid Choice!";break;
		}
	}while(ch<=7);

}
