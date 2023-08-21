#include"avlHead.h"
int main()
{
 	string name,city,acc;
 	int noOfStud,noOfFac,code;
 	int flag,choice=0;
 	AVL a1;
 	while(choice<6)
 	{
 		cout<<"\n***************************\n";
 		cout<<"1.Insert College details\n";
 		cout<<"2.Search using code\n";
 		cout<<"3.Display details InOrder\n";
 		cout<<"4.Display details PreOrder\n";
 		cout<<"5.Display details postOrder\n";
 		cout<<"6.Exit";
 		cout<<"\n***************************\n";
 		cout<<"\nEnter your choice:";
 		cin>>choice; //User enters choice
 		switch(choice)
 		{
 			case 1: //Insertion
 				{
 					cout<<"Enter the details of the College:\n";
 					cout<<"\nEnter name:";
 					cin>>name;
					cout<<"\nEnter city:";
					cin>>city;
					cout<<"\nEnter accreditation:";
					cin>>acc;
					cout<<"\nEnter no. of students:";
					cin>>noOfStud;
					cout<<"\nEnter no. of Faculty:";
					cin>>noOfFac;
					cout<<"\nEnter conselling code:";
					cin>>code;
 					Node *node=new Node(name,city,acc,noOfStud,noOfFac,code);
 					Node *temp=a1.getRoot();
 					Node *ins=a1.insert(temp,node);
 					a1.setRoot(ins);
 					break;
 				}
 		case 2: //Search using key
 			{
 					cout<<"Enter College code to search:";
 					cin>>code;
 					Node *temp=a1.getRoot();
 					if(temp==NULL)
 						cout<<"\nTree is empty\n";
 					else
 					{
 						Node *ret1=a1.search(temp,code);
 						if(ret1==NULL)
 							cout<<"\nCode doesn't exist\n";
 						else
						{
 							cout<<"\n\nCollege details are:\n\n\n";
							cout<<"Name\tCity\tAccreditation\tNo.of Students\tNo.of Faculty\tcode\n";
							ret1->dispDetails();
 						}
 					}
 					break;
 			}
 		case 3: //Inorder display
 			{
 				Node *temp=a1.getRoot();
 				if(temp!=NULL)
 				{
 					cout<<"\n\nCollege details are:\n\n\n";
 					cout<<"Name\tCity\tAccreditation\tNo.of Students\tNo.of Faculty\tcode\n";
					a1.inOrder(temp);
 				}
 				else
 					cout<<"\nTree is Empty\n";
 					break;
 			}
 		case 4: //Preorder display
 			{
 				Node *temp=a1.getRoot();
 				if(temp!=NULL)
 				{
 					cout<<"\n\nCollege details are:\n\n\n";
 					cout<<"Name\tCity\tAccreditation\tNo.of Students\tNo.of Faculty\tcode\n";
					a1.preOrder(temp);
 				}
 				else
 					cout<<"\nTree is Empty\n";
 					break;
 			}
 		case 5: //Postorder display
 			{
 				Node *temp=a1.getRoot();
 				if(temp!=NULL)
 				{
 					cout<<"\n\nCollege details are:\n\n\n";
	 				cout<<"Name\tCity\tAccreditation\tNo.of Students\tNo.of Faculty\tcode\n";
					a1.postOrder(temp);
 				}
 				else
				{
 					cout<<"\nTree is Empty\n";
 					break;
 				}
 			}
		}
 	}
}
