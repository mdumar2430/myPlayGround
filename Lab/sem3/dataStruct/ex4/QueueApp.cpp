#include"Queue.h"
int main()
{
	int cap,size,ch,flag,i,pos;
	cout<<"\nEnter Capacity of the list:";
	cin>>cap;
	cout<<"\nEnter no. of Colleges to be added:";
	cin>>size;
	College *col=new College[cap];
	College *temp=new College[cap];
	if(size>0)
	{
		cout<<"\n\t*****************************Enter College Details*****************************";
		for(i=0;i<size;i++)
		{
			cin>>col[i];
			cout<<"\n--------------------------------------";
		}
	}
	Queue q(col,size,cap);
	do
	{
		cout<<"\n\n*|------------------>MENU<-----------------|*";
		cout<<"\n1.Insert Entry at Last\n2.Delete First Entry\n3.Display First Entry\n4.Check size\n5.Make Queue Empty\n6.Display Queue\n7.EXIT\n*|----------------------------------|*\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1://Enqueue
				{
					College C;
					cout<<"\n\t**************************Enter College Detail to be inserted At Last**************************";
					cin>>C;
					flag=q.enqueue(C);
					if(flag==1)
						cout<<"\nInsertion Successfull";
					else
						cout<<"\nInsertion Failed";
				}break;
			case 2://Dequeue
				{
					College del;
					cout<<"\nDeleting First element..................";
					del=q.dequeue();
					if(del.getNoOfStud()!=0)
					{
						cout<<"\n\n>>>>>>>>>Deletion successful";
						cout<<"\nDeleted Element is:\n\n";
						cout<<del;
					}
					else
						cout<<"\n\n>>>>>>>>>Deletion Failed";
				}break;
			case 3://Peek
				{
					College peek;
					peek=q.peek();
					if(peek.getNoOfStud()!=0)
					{
						cout<<"\n>>>>>>>>>>>>Dipslaying First Entry<<<<<<<<<<<<<";
						cout<<peek;
					}
					else
						cout<<"\nNo Element to Display!";
				}break;
			case 4://Size of the stack
				{
					int size;
					size=q.checkSize();
					cout<<"\nSize of the Queue is:"<<size;
				}break;
			case 5://Make Queue Empty
				flag=q.makeQueueEmpty();
				if(flag==1)
				{
					cout<<"\nEmptying the Queue..............\n";
					cout<<"\n>>>>>>>>Queue is Emptied now!<<<<<<<<<";
				}
				else
					cout<<"\nQueue is already Empty!";
				break;
			case 6://Display Queue
				temp=q.displayQueue();
				cout<<"\n\t------------------------DETAILS------------------------";
				cout<<"\nNAME\tCITY\tACCREDITATION\tNo. Of Students\t\tNo. Of Faculty\n";
				cout<<"----------------------------------------------------------------------|\n";
				if(temp[0].getNoOfStud()!=0)
				{
					for(i=0;temp[i].getNoOfStud()!=0;i++)
					{
						cout<<temp[i].getName()<<"\t"<<temp[i].getCity()<<"\t"<<temp[i].getAcc()<<"\t\t\t"<<temp[i].getNoOfStud()<<"\t\t\t\b\b"<<temp[i].getNoOfFac()<<"\n";
						cout<<"----------------------------------------------------------------------|\n";
					}
				}
				else
					cout<<"\nQueue is empty!";
				break;
			case 7:ch=8;break;
			default:cout<<"\n-----------------Invalid choice!-----------------";
		}
	}while(ch<=7);

}
