#include"horHead.h"
int*ShiftTable(string P,int len)
{
	int *Table = new int[300];
	for(int i=0;i<300;i++)
	{
	  Table[i] = len; //filling table 
	}
	for(int j=0;j<len-2;j++)
	{
	  Table[int(P[j])] = len-1-j; //filling needed pattern value
	}
	return Table;
}
int Horspools(string P,string T,int plen,int tlen)
{
	int *Table=ShiftTable(P,plen);
	int i = plen-1,k;
	while(i<=tlen-1)
	{
	  k=0;
	  while(k<=plen-1 && P[plen-1-k]==T[i-k])
	  {
	    k=k+1;
	  }
	  if(k == plen) 
		  return i-plen+1;
	  else
            i = i+Table[int(T[i])];
	}
	return -1;
}
