#include"horHead.h"
int main()
{
	string p,t;
	int plen,tlen,res,opt;
	cout<<"\nUse UNDERSCORES '_' instead leaving blank\n";
	cout<<"\nEnter your text\n";
	do
	{
	  cin>>t;
	}while(!"\n");
	tlen=t.size();
	do
	{
	  cout<<"\nEnter the pattern:";
	  do
 	  { 
	    cin>>p;
	  }while(!"\n");
	  plen=p.size();
	  res = Horspools(p,t,plen,tlen);
	  if(res != -1)
	  {
	 	cout<<"\nThe pattern '"<<p<<"' is present in the text from index ";
	  	cout<<res<<" to "<<res+(plen-1)<<"\n";
	  }
	  else
	   	cout<<"\nThe pattern '"<<p<<"' is not present in the text\n";
	  cout<<"\nTo continue to search in the same text press '1'";
	  cout<<" else press any other key\n";
	  cin>>opt;
	}while(opt == 1);
}
