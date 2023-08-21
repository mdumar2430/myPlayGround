#include<iostream>
#include<stdlib.h>
using namespace std;
class College
{
	public:
		College(); // Default constructor
		College(string,string,string,int,int,int); // Parameterized constructor
		College(const College&);
		~College(); // Destructor
		void dispDetails(); // To display the details of the employees
		int getCode();
	private:
		string name,city,acc;
		int code,noOfStud,noOfFac;
		friend class Graph;
};
class Graph
{
	public:
		Graph(int);
		~Graph();
		void getData();
		void createGraph();
		void displayAll();
		void performDFS();
		void DFS(int);
		void showVertexData(int);
		void printAdjacent();
		void implementConnectedComponent();
	private:
		College * vertices;
		int noOfVertices;
		bool *visited;
		int **adjMatrix;
};