#include"bstHead.h"

int main()
{
	College col;
	int ch,flag;
	BST b;
	do
	{
		cout<<"\n***************************\n";
		cout<<"1.Insert College details\n";
		cout<<"2.Search using counselling code\n";
		cout<<"3.Find highest counselling code\n";
		cout<<"4.Find lowest counselling code\n";
		cout<<"5.Display details InOrder\n";
		cout<<"6.Display details PreOrder\n";
		cout<<"7.Display details postOrder\n";
		cout<<"8.Delete using counselling code\n";
		cout<<"9.Exit\n";
		cout<<"\n***************************\n";
		cout<<"\nEnter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					cout<<"\n*********Enter College Details*********\n";
					cin>>col;
					TreeNode *node=new TreeNode(col.getName(),col.getCity(),col.getAcc(),col.getNoOfStud(),col.getNoOfFac(),col.getCode());
					TreeNode *temp=b.getRoot();
					flag=b.insert(temp,node);
					if(flag==1)
						cout<<"\nInsertion successful\n";
					else
						cout<<"\nInsertion failed---Duplicate element\n";
				}break;
			case 2:
				{
					int key;
					cout<<"\nEnter code to search:";
					cin>>key;
					TreeNode *temp=b.getRoot();
					if(temp==NULL)
						cout<<"\n--->TREE IS EMPTY!!";
					else
					{
						TreeNode *srch=b.search(temp,key);
						if(srch!=NULL)
						{
							cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
							srch->dispDetails();
						}
						else
							cout<<"\n--->No College Found!";
					}

				}break;
			case 3:
				{
					TreeNode *temp=b.getRoot();
					if(temp==NULL)
						cout<<"\nTree is empty\n";
					else
					{
						College *max=b.findMax(temp);
						cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
						max->dispDetails();
					}
				}break;
			case 4:
				{
					TreeNode *temp=b.getRoot();
					 if(temp==NULL)
						  cout<<"\nTree is empty\n";
					  else
					  {
						  College *min=b.findMin(temp);
						  cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
		      				  min->dispDetails();
					  }

				}break;
			case 5:
				{
					TreeNode *temp=b.getRoot();
					if(temp!=NULL)
					{
						cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
						b.inOrder(temp);
					}
					else
						cout<<"\nTree is Empty\n";
				}break;
			case 6:
				{
					TreeNode *temp=b.getRoot();
					if(temp!=NULL)
					{
						cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
						b.preOrder(temp);
					}
					else
						cout<<"\nTree is Empty\n";
				}break;
			case 7:
				{
					TreeNode *temp=b.getRoot();
					if(temp!=NULL)
					{
						cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
						b.postOrder(temp);
					}
					else
						cout<<"\nTree is Empty\n";
				}break;
			case 8:
				{
					int key;
					cout<<"\nEnter counselling code of college to be deleted:";
					cin>>key;
					College *del=b.deleteCollege(key);
					if(del==NULL)
						cout<<"\nDeletion failed---Invalid code";
					else
					{
						cout<<"Name\tCity\tAccreditation\tNo.Of Students\tNo.Of Faculty\tCounselling code\n";
						del->dispDetails();
						cout<<"\n\nDisplayed Details were deleted Successfully\n";
					}
				}break;
			case 9:ch=10;break;
			default:cout<<"\n-->Enter Valid Option!!";
		}
	}while(ch<=9);
}
