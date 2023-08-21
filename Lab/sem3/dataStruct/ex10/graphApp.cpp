#include"graphHead.h"
int main()
{
int n,ch;
cout<<"\n Enter no of vertices : ";
cin>>n;
Graph g(n);
g.getData();
g.createGraph();
while(true)
{
cout<<"\n Enter 1 to perform DFS traversal.";
cout<<"\n Enter 2 to print adjacent matrix.";
cout<<"\n Enter 3 to find connected component.";
cout<<"\n Enter 4 to display all student details.";
cout<<"\n Enter 5 to exit.";
cout<<"\n Enter your choice : ";
cin>>ch;
switch(ch)
{
case 1:
{
cout<<"\n DFS traversal : \n";g.performDFS();
break;
}
case 2:
{
cout<<"\n Adjacent matrix : \n";
g.printAdjacent();
break;
}
case 3:
{
g.implementConnectedComponent();
break;
}
case 4:
{
g.displayAll();
break;
}
case 5:
exit(0);
default:
cout<<"\n Invalid choice.\n";
}
}
}
