#include<iostream>
using namespace std;
class College
{
 	public:
 		College();
 		College(string,string,string,int,int,int);
 		~College();
 		void dispDetails();
	private: 
		int noOfStud,noOfFac,code;
		string name,city,acc;
		friend class AVL;
};

class Node
{
	public:
		Node();
		Node(string,string,string,int,int,int);
 		~Node(); 
 		void dispDetails();
 		College * getCollege(Node *);
	private:
	 	College *C;
 		Node *left;
 		Node *right;
 		int height;
		friend class AVL;
};

class AVL
{
 	public:
 		AVL();
 		~AVL();
 		int height(Node *);
 		int balFactor(Node *); //Method for finding Balance Factor
 		void inOrder(Node *); //Method for inorder display
 		void preOrder(Node *); //Method for preorder display
 		void postOrder(Node *); //Method for postorder display
 		Node * getRoot(); //Method for getting root
 		void setRoot(Node *); //Method for setting root
 		Node * LLRotate(Node *); //Method for LL Rotation
 		Node * RRRotate(Node *); //Method for RR Rotation
 		Node * LRRotate(Node *); //Method for LR Rotation
 		Node * RLRotate(Node *); //Method for RL Rotation
 		Node * insert(Node *,Node *); //Method for insert a node in the tree
 		Node * search(Node *,int); //Method for to search a element

 	private:
 		Node *root;
};
