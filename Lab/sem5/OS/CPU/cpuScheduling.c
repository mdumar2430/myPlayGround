#include"cpuScheduling.h"
void fcfs(int burst_time[],int n,int proc[]) 
{
	int total_waiting_time=0;
	int total_turn_around_time=0;
	int turn_around_time[40],waiting_time[40],i;
	waiting_time[0] =0; 
	for(i=1;i<=n;i++) 
	{
		waiting_time[i] = burst_time[i-1]+waiting_time[i-1];
	}
	for(i=0;i<n;i++) 
	{
	        turn_around_time[i]=waiting_time[i]+burst_time[i];
	}
	for(i=0;i<n;i++)
	{
		proc[i]=i+1;
		total_waiting_time=total_waiting_time+waiting_time[i];
		total_turn_around_time=total_turn_around_time+turn_around_time[i];
		printf("\nProcess ID:%d\tBurst Time:%d\tWaiting Time:%d\tTurnaround Time:%d",proc[i],burst_time[i],waiting_time[i],turn_around_time[i]);
	}
	printf("\nAverage waiting time:%.2f",(float)total_waiting_time/(float)n);
	printf("\nAverage turn around time:%.2f\n",(float)total_turn_around_time/(float)n);
}
void sjf(int mat[][6],int n)
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<(n-i-1);j++)
		{
			if(mat[j][1]>mat[j+1][1])
			{
				for(k=0;k<5;k++)
				{
					int *a,*b,temp;
					a =&mat[j][k];
					b =&mat[j+1][k];
					temp= *a;
					*a=*b;
					*b=temp;
				}
			}
		}
	}
    int temp, val,low,tot_wait_time,tot_tat_time;
	tot_wait_time=0;
	tot_tat_time=0; 
    mat[0][3] = mat[0][1] + mat[0][2]; 
    mat[0][5] = mat[0][3] - mat[0][1]; 
    mat[0][4] = mat[0][5] - mat[0][2]; 
    for(i=1;i<n;i++)
    {
    	temp = mat[i-1][3];
    	low = mat[i][2];
    	for(j=i;j<n;j++)
    	{
    		if(temp>=mat[j][1] && low>=mat[j][2])
    		{
    			low=mat[j][2];
    			val = j;
			}
		}
		mat[val][3] = temp+mat[val][2];
		mat[val][5] = mat[val][3]-mat[val][1];
		mat[val][4] = mat[val][5]-mat[val][2]; 
		for(k=0;k<6;k++)
		{
			int *a,*b,temp;
			a =&mat[val][k];
			b =&mat[i][k];
			temp= *a;
			*a=*b;
			*b=temp;	
		}
	}
	for(i=0;i<n;i++)
	{
		printf("\nProcess ID:%d\tArrival Time:%d\tBurst Time:%d\tTurnaround Time:%d\tWaiting Time:%d",mat[i][0],mat[i][1],mat[i][2],mat[i][4],mat[i][5]);
		tot_wait_time = tot_wait_time+mat[i][4];
		tot_tat_time=tot_tat_time+mat[i][5];
	}	
    printf("\nAverage Waiting Time:%.2f",(float)tot_wait_time/(float)n);
    printf("\nAverage Turn Around Time:%.2f",(float)tot_tat_time/(float)n);
}

void srtf(int p[50],int at[40],int bt[40],int n)
{
	int x[40],i,waiting[40],completion[40],turnaround[40];
	int avg,tt,time,count,smallest,end;
	avg=0;
	tt=0;
	 for(i=0; i<n; i++)
        x[i]=bt[i];

    bt[9]=9999;
    for(time=0; count!=n; time++)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
            if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0 )
                smallest=i;
        }
        bt[smallest]--;

        if(bt[smallest]==0)
        {
            count++;
            end=time+1;
            completion[smallest] = end;
            waiting[smallest] = end - at[smallest] - x[smallest];
            turnaround[smallest] = end - at[smallest];
        }
    }
    printf("\nP.ID\tAT\tBT\tTAT\tWT\n");
    for(i=0; i<n; i++)
    {
    	printf("%d\t%d\t%d\t%d\t%d\n",p[i],at[i],x[i],waiting[i],turnaround[i]);
        avg = avg + waiting[i];
        tt = tt + turnaround[i];
    }
    printf("\nAverage Waiting Time:%.2f",(float)avg/(float)n);
    printf("\nAverage Turn Around Time:%.2f",(float)tt/(float)n);
}


void prioritySchedule(int p[50],int bt[40],int priority[40],int n)
{
	int i,j,position,temp;
	int waiting_time[40],tat[40],sum,tot_wait_time,tot_tat_time;
	tot_wait_time=0;
	tot_tat_time=0;
	for(i = 0; i < n; i++)
    {
        position = i;
        for(j = i + 1; j < n; j++)
        {
            if(priority[j] < priority[position])
            {
                  position = j;
            }
        }
        temp = priority[i];
        priority[i] = priority[position];
        priority[position] = temp; 
        temp = bt[i];
        bt[i] = bt[position];
        bt[position] = temp;
        temp = p[i];
        p[i] = p[position];
        p[position] = temp;
    }
    waiting_time[0] = 0;
    for(i = 1; i < n; i++)
    {
        waiting_time[i] = 0;
        for(j = 0; j < i; j++)
        {
            waiting_time[i] = waiting_time[i] + bt[j];
    	}
    	tot_wait_time=tot_wait_time+waiting_time[i];
	}
	printf("\nPID\tPriority\tBT\tTAT\tWT\n");
    for(i = 0; i < n; i++)   
    {
          tat[i] = bt[i] + waiting_time[i];
          tot_tat_time = tot_tat_time + tat[i];
          printf("%d\t%d\t\t%d\t%d\t%d\n", p[i],priority[i],bt[i],waiting_time[i], tat[i]);
    }
    printf("\nAverage Waiting Time:%.2f", (float)tot_wait_time/(float)n);
    printf("\nAverage Turnaround Time:%.2f",(float)tot_tat_time/(float)n);

}

void roundRobin(int p[50],int at[40],int bt[40],int t,int n)
{
	int i,total,x,counter,wait_time,turnaround_time;
	int temp[40];
	counter =0;
	total=0;
	turnaround_time=0;
    wait_time=0;
    x=n;
    for(i=0;i<n;i++)
    {
    	temp[i]=bt[i];
	}
	for(total = 0, i = 0; x != 0;) 
    { 
        if(temp[i] <= t && temp[i] > 0) 
        { 
              total = total + temp[i]; 
              temp[i] = 0; 
              counter = 1; 
        } 
        else if(temp[i] > 0) 
        { 
              temp[i] = temp[i] - t; 
              total = total + t; 
        } 
        if(temp[i] == 0 && counter == 1) 
        { 
              x--; 
              printf("\nProcess ID:%d\tBurst Time:%d\tTurnaround Time:%d\tWaiting Time:%d\n",p[i], bt[i], total - at[i], total - at[i] - bt[i]);
              wait_time = wait_time + total - at[i] - bt[i]; 
              turnaround_time = turnaround_time + total - at[i]; 
              counter = 0; 
        } 
        if(i == n - 1) 
        {
              i = 0; 
        }
        else if(at[i + 1] <= total) 
        {
              i++;
        }
        else 
        {
              i = 0;
        }
    } 
    printf("\nAverage Waiting Time:%.2f", (float)wait_time/(float)n); 
    printf("\nAverage Turnaround Time:%.2f", (float)turnaround_time/(float)n); 	
}

