#include"graphHead.h"
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
int College::getCode()
{
	return code;
}
Graph::Graph(int n)
{
	noOfVertices = n;
	vertices = new College[noOfVertices];
	adjMatrix = new int*[noOfVertices];
	for( int i=0; i<noOfVertices; i++ )
		adjMatrix[i] = new int[noOfVertices];
	for( int i=0;i<noOfVertices ; i++)
		for( int j=0; j<noOfVertices ; j++)
			adjMatrix[i][j] = 0;
}
Graph::~Graph()
{
}
void Graph::getData()
{
	string name,city,acc;
	int code,noOfStud,noOfFac;
	cout<<"\n Enter College details : \n\n";
	for(int i=0;i<noOfVertices;i++)
	{
		cout<<"Vertices " << i <<"\n";
		cout<<"\n Enter the name of the College : ";
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
		College C(name,city,acc,noOfStud,noOfFac,code);
		vertices[i]= C;
	}
}
void Graph::createGraph()
{
	int edge,v,w;
	cout<<"\n Enter no of edges in the graph : ";
	cin>>edge;
	for(int i=0;i<edge;i++)
	{
		cout<<"\n Enter the adjacent vertices\n";
		cout<<"\n Enter v : ";
		cin>>v;
		cout<<"\n Enter w : ";
		cin>>w;
		adjMatrix[v][w] =1;
		adjMatrix[w][v] =1;
	}
}
void Graph :: displayAll()
{
	cout<<"\nName\tCity\tAccreditation\tNo,of Students\tNo.of Faculty\tcode \n";
	for(int i=0;i<noOfVertices;i++)
	{
		cout<<vertices[i].name<<" \t "<<vertices[i].city<<" \t"<<vertices[i].acc<<" \t\t "<<vertices[i].noOfStud<<"\t\t"<<vertices[i].noOfFac<<"\t\t"<<vertices[i].code<<"\n";
	}
}
void Graph :: showVertexData(int i)
{
	cout<<"\n Vertice : "<<i<<"\n";
	cout<<"\nName\tCity\tAccreditation\tNo,of Students\tNo.of Faculty\tcode \n";
	cout<<vertices[i].name<<" \t "<<vertices[i].city<<" \t"<<vertices[i].acc<<" \t\t "<<vertices[i].noOfStud<<"\t\t"<<vertices[i].noOfFac<<"\t\t"<<vertices[i].code<<"\n";
}
void Graph::performDFS()
{
	visited = new bool[noOfVertices];
	for( int i=0; i<noOfVertices; i++)
		visited[i] = false;
	for( int i=0; i<noOfVertices; i++)
	{
		if(!visited[i])
			DFS(i);
	}
}
void Graph::DFS(int i)
{
	showVertexData(i);
	visited[i] = true;
	for( int j=0; j<noOfVertices; j++)
	{
		if( adjMatrix[i][j] == 1)
			if(!visited[j])
				DFS(j);
	}
}
void Graph::printAdjacent()
{
	for(int i=0;i<noOfVertices;i++)
		cout<<"\t"<<i;
	cout<<"\n";
	for(int i=0; i<noOfVertices ; i++)
		cout<<"________";
	cout<<"\n";
	for( int i=0;i<noOfVertices ; i++)
	{
		cout<<i<<" |\t";
		for( int j=0; j<noOfVertices ; j++)
			cout<<adjMatrix[i][j]<<"\t";
		cout<<"\n";
	}
}
void Graph::implementConnectedComponent()
{
	visited = new bool[noOfVertices];
	for( int i=0; i<noOfVertices; i++)
		visited[i] = false;
	int count = 0;
	for( int i=0; i<noOfVertices; i++)		
	{
		if(!visited[i])
		{
			cout<<"Connected Component "<<++count<<endl;
			DFS(i);
		}
	}
}
