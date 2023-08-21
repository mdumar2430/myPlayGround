#include"bstHead.h"

College::College()
{
    name="";
    city="";
    acc="";
    noOfStud=0;
    noOfFac=0;
    code=0;
}
College::College(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
    this->name=name;
    this->city=city;
    this->acc=acc;
    this->noOfStud=noOfStud;
    this->noOfFac=noOfFac;
    this->code=code;
}
College::College(const College &ref)
{
    name=ref.name;
    city=ref.city;
    acc=ref.acc;
    noOfFac=ref.noOfFac;
    noOfStud=ref.noOfStud;
    code=ref.code;
}
College::~College()
{
}
void College::setName(string x)
{
    name=x;
}
void College::setCity(string x)
{
    city=x;
}
void College::setAcc(string x)
{
    acc=x;
}
void College::setNoOfStud(int x)
{
    noOfStud=x;
}
void College::setNoOfFac(int x)
{
    noOfFac=x;
}
void College::setCode(int code)
{
    this->code=code;
}
string College::getName()
{
    return name;
}
string College::getCity()
{
    return city;
}
string College::getAcc()
{
    return acc;
}
int College::getNoOfStud()
{
    return noOfStud;
}
int College::getNoOfFac()
{
    return noOfFac;
}
int College::getCode()
{
    return code;
}
istream & operator >>(istream& myin ,College& C)
{
    cout<<"\nEnter the name of the College:";
    myin>>C.name;
    C.setName(C.name);
    cout<<"\nEnter the city name:";
    myin>>C.city;
    C.setCity(C.city);
    cout<<"\nEnter Accreditations of the college:";
    myin>>C.acc;
    C.setAcc(C.acc);
    cout<<"\nEnter no. of students studying:";
    myin>>C.noOfStud;
    C.setNoOfStud(C.noOfStud);
    cout<<"\nEnter no. of faculty working:";
    myin>>C.noOfFac;
    C.setNoOfFac(C.noOfFac);
    cout<<"\nEnter Counselling code:";
    myin>>C.code;
    C.setCode(C.code);
    return myin;
}
ostream & operator <<(ostream& myout ,College& C)
{
    myout<<"\n\nName:"<<C.getName();
    myout<<"\nCity:"<<C.getCity();
    myout<<"\nAccreditations:"<<C.getAcc();
    myout<<"\nNo. of Colleges:"<<C.getNoOfStud();
    myout<<"\nNo. of Faculty:"<<C.getNoOfFac();
    myout<<"\nCounselling code:"<<C.getCode();
    return myout;
}
void College::dispDetails()
{
    cout<<name<<"\t"<<city<<"\t"<<acc<<"\t\t"<<noOfStud<<"\t\t"<<noOfFac<<"\t\t"<<code<<"\n";
}

TreeNode::TreeNode()
{
    left=NULL;
    right=NULL;
}
TreeNode::TreeNode(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
    C=new College(name,city,acc,noOfStud,noOfFac,code);
    right=NULL;
    left=NULL;
}
TreeNode::~TreeNode()
{
    right =NULL;
    left=NULL;
}
College * TreeNode::getCollege(TreeNode *node)
{
    return node->C;
}
void TreeNode::dispDetails()
{
    C->dispDetails();
}

BST::BST()
{
    root=NULL;
}
BST::~BST()
{
    root=NULL;
}
int BST::isEmpty()
{
    return root==NULL;
}
TreeNode * BST::getRoot()
{
    return root;
}
int BST::insert(TreeNode *temp,TreeNode *newNode)
{
    if(isEmpty()) 
    {
        root=newNode;
        return 1;
    }
    else //Tree is not empty
    {
        if(temp->C->getCode() > newNode->C->getCode())
        {
            if(temp->left==NULL)//Left insertion possible
                temp->left=newNode;
            else
                insert(temp->left,newNode);
            return 1;
        }
        if(temp->C->getCode() < newNode->C->getCode())
        {
            if(temp->right==NULL)//Right insertion possible
            {
                temp->right=newNode;
                return 1;
            }
            else
                insert(temp->right,newNode);
            return 1;
         }
         return -1;
    }
}
TreeNode* BST::search(TreeNode *temp,int ele)
{
	if(temp==NULL || temp->C->getCode()==ele)
         return temp;
    else if(temp->C->getCode() > ele)
         search(temp->left,ele);
    else if(temp->C->getCode() < ele)
         search(temp->right,ele);
}
College* BST::findMin(TreeNode *temp)
{
    if(temp->left==NULL)
    {
          return temp->C;
    }
    else
          findMin(temp->left);
}
College* BST::findMax(TreeNode *temp)
{
    if(temp->right==NULL)
         return temp->C;
    else
         findMax(temp->right);
}
void BST::inOrder(TreeNode *temp)
{
    if(temp!=NULL)
    {
         inOrder(temp->left);
         temp->C->dispDetails();
         inOrder(temp->right);
    }
}
void BST::preOrder(TreeNode *temp)
{
    if(temp!=NULL)
    {
         temp->C->dispDetails();
         preOrder(temp->left);
         preOrder(temp->right);
    }
}
void BST::postOrder(TreeNode *temp)
{
    if(temp!=NULL)
    {
         postOrder(temp->left);
         postOrder(temp->right);
         temp->C->dispDetails();
    }
}
College* BST :: deleteCollege(int ele)
{
    TreeNode *parent = NULL;
    TreeNode *temp=root;
    while(temp!=NULL) //Tree is not empty
    {
        if(temp->C->getCode()==ele)
         {
            College *del=temp->C;
            if(temp->left==NULL && temp->right==NULL)
            {//Node wothout child
                if(temp==root)//Delete root
                    root=NULL;
                else //Delete node without child
                {
                    if(parent->left == temp)
                         parent->left=NULL;
                    else
                         parent->right=NULL;
                 }
                 delete temp;
                 temp=NULL;
                 return del;
            }
            else if(temp->left!=NULL && temp->right!=NULL)
            { //Node with two child
                 TreeNode *temp1=temp->right;
                 if(temp1->left==NULL)
                  {
                     temp->C=temp1->C;
                     temp->right=temp1->right;
                     delete temp1;
                     temp1=NULL;
                 }
                 else
                 {
                     while(temp1->left!=NULL)
                     {
                         parent=temp1;
                         temp1=temp1->left;
                     }
                     temp->C=temp1->C;
                     if(temp1->right!=NULL)
                         parent->left=temp1->right;
                     else
                         parent->left=NULL;
                     delete temp1;
                     temp1=NULL;
                 }
                 return del;
            }
            else
            {//Node with 1 child
               if(temp==root)
               {
                 if(temp->left!=NULL && temp->right==NULL)
                     root=temp->left;
                 else
                     root=temp->right;
                 delete temp;
                 temp=NULL;
                 return del;
              }
              else
              {
                 if(parent->right==temp)
                 {
                     if(temp->right!=NULL && temp->left==NULL)
                         parent->right=temp->right;
                     else
                         parent->right=temp->left;
                 }
                 else
                 {
                     if(temp->left!=NULL && temp->right==NULL)
                         parent->left=temp->left;
                     else
                         parent->left=temp->right;
                 }
                 delete temp;
                 temp=NULL;
                 return del;
              }
         }
    }
    else if(temp->C->getCode() > ele)
    { //Traverse left
        parent=temp;
        temp=temp->left;
    }
    else
    { //Traverse right
        parent=temp;
        temp=temp->right;
    }
    }
    return NULL;
}
