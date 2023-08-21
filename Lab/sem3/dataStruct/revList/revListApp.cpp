#include"revList.h"
int main()
{
    int ch,i,flag,pos;
    College col;
    L_List list;
    do
    {
        cout<<"\n\n|>>>>>>>>>>>>>>>>MENU<<<<<<<<<<<<<<<<<<<<|";
        cout<<"\n1.Insert at First\n2.Insert at Last\n3.Insert by Position\n4.Delete at First\n5.Delete at Last\n6.Delete by Position\n7.Replace\n8.Search by Position\n9.Make List Empty\n10.Display list\n11.Reverse the List\n12.EXIT\n|----------------------------------------|\n>>Enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://Insert first
                {
                    cout<<"\n\t*************Enter College details to insert at first*************\n";
                    cin>>col;
                    Node *ins=new Node(col,NULL,NULL);
                    list.insertAtFirst(ins);
                    cout<<"\n---------->INSERTION SUCCESSFUL<----------";
                }
                break;
            case 2://Insert Last
                {
                    cout<<"\n\t*************Enter College details to insert at Last*************\n";
                    cin>>col;
                    Node *ins=new Node(col,NULL,NULL);
                    list.insertAtLast(ins);
                    cout<<"\n---------->INSERTION SUCCESSFUL<----------";	
                }
                break;
            case 3://Insert by Position
                {
                    cout<<"\nEnter the position:";
                    cin>>pos;
		    if(list.isEmpty() && pos!=1){
			 cout<<"\n---------->Invalid Position - List Empty<----------";
			 break;
		    }
                    cout<<"\n\t*************Enter College details to insert at the given position*************\n";
                    cin>>col;
                    Node *ins=new Node(col,NULL,NULL);
                    flag=list.insertByPos(ins,pos);
                    if(flag==1)
                        cout<<"\n---------->INSERTION SUCCESSFUL<----------";
                    else
                        cout<<"\n---------->INSERTION FAILED!<----------";
                    break;
                }
            case 4://Delete First
                cout<<"\n****************Deleting First Entry****************\n";
                flag=list.deleteAtFirst();
                if(flag==1)
                    cout<<"\n---------->DELETION SUCCESSFUL<----------";
                else
                    cout<<"\n---------->DELETION FAILED!<----------";
                break;
            case 5://Delete Last
                cout<<"\n****************Deleting Last Entry****************\n";
                flag=list.deleteAtLast();
                if(flag==1)
                    cout<<"\n---------->DELETION SUCCESSFUL<----------";
                else
                    cout<<"\n---------->DELETION FAILED!<----------";
                break;
            case 6://Delete by Position
                cout<<"\nEnter the position:";
                cin>>pos;
                cout<<"\n****************Deleting Given Entry****************\n";
                flag=list.deleteByPos(pos);
                if(flag==1)
                    cout<<"\n---------->DELETION SUCCESSFUL<----------";
                else
                    cout<<"\n---------->DELETION FAILED!<----------";
                break;
            case 7://Replace element by position
                {
                    College rep;
                    cout<<"\nEnter the position:";
                    cin>>pos;
                    cout<<"\n\t*************Enter Replacement Details*************\n";
                    cin>>rep;
                    Node *newNode=new Node(rep,NULL,NULL);
                    flag=list.replaceElementByPos(newNode,pos);
                    if(flag==1)
                        cout<<"\n---------->REPLACED SUCCESSFULLY<----------";
                    else
                        cout<<"\n---------->REPLACEMENT NOT POSSIBLE<-----------";
                    break;
                }
            case 8://Search Element By position 
                 cout<<"\nEnter the position to serach:";
                 cin>>pos;
                 cout<<"\nSearching... .... ....";
                 col=list.searchByPos(pos);
                 if(col.getNoOfStud()!=0)
                 {
                     cout<<"\n-------------->Element Found<--------------";
                     cout<<col;
                 }
                 else
                     cout<<"\n-------------->Element NOT Found<--------------";
                 break;
            case 9://Make List Empty
                 flag=list.makeListEmpty();
                 if(flag==1)
                     cout<<"\n------------->List is Emptied now!<-------------";
                 else 
                     cout<<"\n------------->List is already Empty<-------------";
                 break;
            case 10://Display List
                 list.displayList();
                 break;
	    case 11:
		 list.reverseList();
	    case 12:ch=13;break;
            default:cout<<"\nInvalid Choice!";break;
        }
    }while(ch<=13);
}
