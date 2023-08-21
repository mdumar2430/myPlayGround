#include"cpuScheduling.h"
void main() 
{   
	int ch,choice,no_of_process,i,time_quantum;
	char op;
	int burst_time[50],arrival_time[50],process[40],priority[40];
	do
	{
	  printf("\n1.FCFS\n2.SJF\n3.Priority\n4.Round Robin\n5.Exit");
	  printf("\nEnter your choice:");
	  scanf("%d",&choice);
	  switch(choice)
	  {
		case 1:
			printf("Enter the number of process:");
			scanf("%d",&no_of_process);
			for(i=0;i<no_of_process;i++)
			{
				printf("\nProcess ID:%d",i+1);
				printf("\nBurst time:");
				scanf("%d", &burst_time[i]);
			}
			fcfs(burst_time,no_of_process,process);
			break;
		case 2:
			printf("a)SJF with Preemption\nb)SJF Non-Preemption");
			printf("\nYour choice:");
			scanf("%s",&op);
			switch(op)
			{
				case 'a':
					printf("Enter the number of process:");
					scanf("%d",&no_of_process);
					int mat[10][6],i;
					for(i=0;i<no_of_process;i++)
					{
						printf("\nProcess:%d",i+1);
	                    mat[i][0]=i+1;
						printf("\nEnter a Arrival time:");
						scanf("%d",&mat[i][1]);
						printf("\nEnter a Burst time:");
						scanf("%d",&mat[i][2]);
					}
					for(i=0;i<no_of_process;i++)
					{
						printf("\nProcess Id :%d\tArrival Time :%d\tBurst Time:%d ",mat[i][0],mat[i][1],mat[i][2]);
						printf("\n");
					}	
					sjf(mat,no_of_process);
					break;
				case 'b':
					printf("Enter the number of Processes:");
					scanf("%d",&no_of_process); 
					for(i=0;i<no_of_process;i++)
					{
						printf("Process:%d",i+1);
						process[i]=i+1;
						printf("\nEnter Arrival time:");
						scanf("%d",&arrival_time[i]);
					 	printf("Enter Burst time:");
					 	scanf("%d",&burst_time[i]);
					 	printf("\n");
					}
					srtf(process,arrival_time,burst_time,no_of_process);
					break;
				default:
					printf("\nEnter correct option");
				}
			break;

		case 3:
			printf("Enter the number of Processes:");
			scanf("%d",&no_of_process); 
			for(i=0;i<no_of_process;i++)
			{
				printf("Processes:%d",i+1);
				process[i]=i+1;
			 	printf("\nEnter Burst time:");
			 	scanf("%d",&burst_time[i]);
			 	printf("Enter a Priority:");
			 	scanf("%d",&priority[i]);
			 	printf("\n");
			}
			prioritySchedule(process,burst_time,priority,no_of_process);
			break;
		case 4:
			printf("Enter the number of Processes:");
			scanf("%d",&no_of_process); 
			for(i=0;i<no_of_process;i++)
			{
				printf("Process:%d",i+1);
				process[i]=i+1;
				printf("\nEnter Arrival time:");
				scanf("%d",&arrival_time[i]);
			 	printf("Enter Burst time:");
			 	scanf("%d",&burst_time[i]);
			}
			printf("\nEnter a Time quantum:");
			scanf("%d",&time_quantum);
			roundRobin(process,arrival_time,burst_time,time_quantum,no_of_process);
			break;	
		case 5:
			printf("\nExitting....\n");
			break;
		default:
			printf("\nEnter the correct option\n");
	}
  }while(choice<=4);
}

