#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

class College
{
    private:
        string name;
        string city;
        string acc;
        int noOfStud;
        int noOfFac;
	int code;
    public:
        College();
        College(string,string,string,int,int,int);
        College(const College &);
        ~College();
        void setName(string);
        string getName();
        void setCity(string);
        string getCity();
        void setAcc(string);
        string getAcc();
        void setNoOfStud(int);
        int getNoOfStud();
        void setNoOfFac(int);
        int getNoOfFac();
	void setCode(int);
	int getCode();
	void dispDetails();
        friend istream & operator >>(istream& ,College&);
        friend ostream & operator <<(ostream& ,College&);
	friend class TreeNode;
};

class TreeNode
{
    private:
        College *C;
        TreeNode *left;
        TreeNode *right;
    public:
        TreeNode();
        TreeNode(string,string,string,int,int,int);
        ~TreeNode();
        College * getCollege(TreeNode *);
        void dispDetails();
	friend class BST;
};

class BST
{
	private:
		TreeNode *root;
	public:
		BST(); 
	 	~BST(); 
	      	int isEmpty();
	       	TreeNode * getRoot();
	       	int insert(TreeNode *,TreeNode *);
	       	void preOrder(TreeNode *);
	       	void inOrder(TreeNode *);
	       	void postOrder(TreeNode *);
	       	TreeNode* search(TreeNode *,int);
	       	College* findMax(TreeNode *);
	       	College* findMin(TreeNode *); 
		College* deleteCollege(int); 
};





            

