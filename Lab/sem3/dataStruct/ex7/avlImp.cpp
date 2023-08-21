#include"avlHead.h"
//Methods of class College
College::College()
{
 	code=0;
 	noOfStud=0;
 	noOfFac=0;
 	name="";
 	city="";
 	acc="";
}
College::College(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
	this->name=name;
	this->city=city;
	this->acc=acc;
	this->noOfFac=noOfFac;
	this->noOfStud=noOfStud;
	this->code=code;
}
College::~College()
{
}
void College::dispDetails()
{
 	cout<<name<<"\t"<<city<<"\t"<<acc<<"\t\t"<<noOfStud<<"\t\t"<<noOfFac<<"\t\t"<<code<<"\n";
}
//Methods of class Node
Node::Node()
{
 	left=NULL;
 	right=NULL;
}
Node::Node(string name,string city,string acc,int noOfStud,int noOfFac,int code)
{
 	C=new College(name,city,acc,noOfStud,noOfFac,code);
 	right=NULL;
 	left=NULL;
 	height=0;
}
Node::~Node()
{
 	right =NULL;
 	left=NULL;
}
void Node::dispDetails()
{
 	C->dispDetails();
}
College * Node::getCollege(Node *node)
{
 	return node->C;
}
//Methods of class AVL
AVL::AVL() //default constructor
{
 	root=NULL;
}
AVL::~AVL()
{
 	root=NULL;
}
int AVL::height(Node* temp) //to calculate height of node
{
 	if(temp==NULL)
 		return -1;
 	return temp->height;
}
int AVL::balFactor(Node* temp) //to calculate BalanceFactor of node
{
 //temp-node whose height to find
 	if(temp==NULL)
 		return -1;
 	return (height(temp->left) - height(temp->right));
}
void AVL::inOrder(Node *temp)
{
 	if(temp!=NULL)
 	{
 		inOrder(temp->left);
 		temp->C->dispDetails();
 		inOrder(temp->right);
 	}
}
void AVL::preOrder(Node *temp)
{
 	if(temp!=NULL)
 	{
 		temp->C->dispDetails();
 		preOrder(temp->left);
 		preOrder(temp->right);
 	}
}
void AVL::postOrder(Node *temp)
{
 	if(temp!=NULL)
 	{
 		postOrder(temp->left);
 		postOrder(temp->right);
 		temp->C->dispDetails();
 	}
}
Node* AVL::getRoot() //getter to root address
{
 	return root;
}
void AVL::setRoot(Node *newNode) //setter to set root node
{
 	root=newNode;
}
Node * AVL::insert(Node* temp,Node* newNode) //insert a node in the tree
{
 //temp-root
 //newNode-node to insert
 	if(temp==NULL)
 	{
 		root=newNode;
 		cout<<"\n\nInsertion successful\n";
 		return root;
 	}
 	else if(temp->C->code > newNode->C->code)
 	{
 		if(temp->left==NULL)
 		{
 			temp->left=newNode;
 			cout<<"\n\nInsertion successful\n";
 		}	
 		else
 			temp->left=insert(temp->left,newNode);
 	}
 	else if(temp->C->code < newNode->C->code)
 	{
 		if(temp->right==NULL)
 		{
 			temp->right=newNode;
 			cout<<"\n\nInsertion successful\n";
 		}
 		else
 			temp->right=insert(temp->right,newNode);
 	}
 	else
 		cout<<"\nInsertion failed--Duplicate element\n";
 	temp->height = max(height(temp->left),height(temp->right)) + 1;
 	int bal=balFactor(temp);
 	if(bal>1)
 	{
 		if(newNode->C->code < temp->left->C->code)
 			return LLRotate(temp);
 		else
 			return LRRotate(temp);
 	}
 	if(bal<-1)
 	{
 		if(newNode->C->code > temp->right->C->code)
 			return RRRotate(temp);
 		else
 			return RLRotate(temp);
 	}
 	return temp;
}
Node* AVL::search(Node *temp,int key) //to search for an account
{
 	if(temp==NULL || temp->C->code==key)
 		return temp;
 	else if(temp->C->code < key)
 		search(temp->right,key);
 	else if(temp->C->code > key)
 		search(temp->left,key);
 	else
 		return NULL;
}
Node * AVL::LLRotate(Node* k3) //LL Rotation
{
 	//k3 - root node
 	Node *k2=k3->left;
 	Node *temp=k2->right;
 	k2->right=k3;
 	k3->left=temp;
 	//height update
 	k3->height=max(height(k3->left),height(k3->right))+1;
 	k2->height=max(height(k2->left),height(k2->right))+1;
 	return k2;
}
Node * AVL::RRRotate(Node* k1) //RR Rotation
{
 	//k1- root node
 	Node *k2=k1->right;
 	Node *temp=k2->left;
 	k2->left=k1;
 	k1->right=temp;
 	k1->height=max(height(k1->left),height(k1->right))+1;
 	k2->height=max(height(k2->left),height(k2->right))+1;
 	return k2;
}
Node * AVL::LRRotate(Node *k3) //LR rotation
{
 	//k3- root node
 	k3->left=RRRotate(k3->left); //RR rotate
 	return LLRotate(k3); //LL rotate
}
Node * AVL::RLRotate(Node *k1) //LR rotation
{
 	//k3- root node
 	k1->right=RRRotate(k1->right); //RR rotate
 	return RRRotate(k1); //LL rotate
}
