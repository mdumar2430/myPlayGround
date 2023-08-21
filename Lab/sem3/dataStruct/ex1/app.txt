#include"ArrayHead.h"
#include<iostream>
using namespace std;

int main()
{
    int cap,size,ch,flag,i,pos;
    cout<<"\nEnter Capacity of the list:";
    cin>>cap;
    cout<<"\nEnter no. of Colleges to be added:";
    cin>>size;
    College C,search;
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
    A_List list(col,size,cap);
    do
    {
        cout<<"\n\n----------------------->MENU<-----------------------";
        cout<<"\n1.Insert Entry at First\n2.Insert Entry at Last\n3.Insert Entry at gievn position\n4.Delete First Entry\n5.Delete Last Entry\n6.Delete Entry at gievn position\n7.Search Element at given position\n8.Make List Empty\n9.Display List\n10.EXIT\n----------------------------------\nEnter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1://Insert at First
                cout<<"\n\t*****************************Enter College Detail to be inserted at first****************************";
                cin>>C;
                flag=list.insertAtFirst(C);
                if(flag==1)
                    cout<<"\nInsertion Successfull,Click 9 to see the modification";
                else
                    cout<<"\nInsertion Failed";
                break;
            case 2://Insert At Last
                cout<<"\n\t*****************************Enter College Detail to be inserted At Last*****************************";
                cin>>C;
                flag=list.insertAtLast(C);
                if(flag==1)
                    cout<<"\nInsertion Successfull,Click 9 to see the modification";
                else
                    cout<<"\nInsertion Failed";
                break;
            case 3://insert by position
                {
                cout<<"\n\t*****************************Enter College Detail to be inserted*****************************";
                cin>>C;
                cout<<"\nEnter position:";
                cin>>pos;
                if(pos<=cap)
                {
                    flag=list.insertByPos(C,pos);
                    if(flag==1)
                        cout<<"\nInsertion Successfull,Click 9 to see the modification";
                    else
                        cout<<"\nInsertion Failed";
                }
                else
                    cout<<"\nInsertion Failed";
                }break;
            case 4://Delete at first
                {
                cout<<"\nDeleting First element..................";
                flag=list.deleteAtFirst();
                if(flag==1)
                    cout<<"\n\n>>>>>>>>>Deletion successful,Click 9 to see the modification";
                else
                    cout<<"\n\n>>>>>>>>>Deletion Failed";
                }break;
            case 5://Delete At Last
                {
                cout<<"\nDeleting Last element..................";
                flag=list.deleteAtLast();
                if(flag==1)
                    cout<<"\n\n>>>>>>>>>Deletion successful,Click 9 to see the modification";
                else
                    cout<<"\n\n>>>>>>>>>Deletion Failed";
                }break;
            case 6://Delete by Position
                {
                cout<<"\nEnter Position:";
                cin>>pos;
                cout<<"\nDeleting given entry...................";
                flag=list.deleteByPos(pos);
                if(flag==1)
                    cout<<"\n\n>>>>>>>>>Deletion successful,Click 9 to see the modification";
                else
                    cout<<"\n\n>>>>>>>>>Deletion Failed";
                }break;
            case 7://serach element by position
                cout<<"\n>>>>>>>>>>>SEARCH<<<<<<<<<<<";
                cout<<"\nEnter position to search:";
                cin>>pos;
                search=list.searchByPos(pos);
                if(search.getNoOfStud()!=0)
                {
                    cout<<"\n>>>>>>>>>>Element Found!<<<<<<<<<<";
                    cout<<search;
                }
                else
                    cout<<"\n>>>>>>>>>Element not Found<<<<<<<<<<";
                break;
            case 8://Make List Empty
                flag=list.makeListEmpty();
                if(flag==1)
                {
                    cout<<"\nEmptying the List..............";
                    cout<<"\n>>>>>>>>List is Empty<<<<<<<<";
                }
                else
                    cout<<"\nList is already Empty";
                break;
            case 9://Display List
                temp=list.displayList();
                cout<<"\n\t------------------------DETAILS------------------------";
                cout<<"\nNAME\tCITY\t\tACCREDITATION\tNo. Of Students\t\tNo. Of Faculty\n";
                cout<<"--------------------------------------------------------------------------------|\n";
                if(temp[0].getNoOfStud()!=0)
                {
                    for(i=0;temp[i].getNoOfStud()!=0;i++)
                    {
                            cout<<temp[i].getName()<<"\t"<<temp[i].getCity()<<"\t\t"<<temp[i].getAcc()<<"\t\t\t"<<temp[i].getNoOfStud()<<"\t\t\t\b\b"<<temp[i].getNoOfFac()<<"\n";
                            cout<<"--------------------------------------------------------------------------------|\n";
                    }
                }
                else
                    cout<<"\nList is empty!";
                break;
            case 10:break;
            default:cout<<"\n-----------------Invalid choice!-----------------";
        }
    }while(ch<10);
}
