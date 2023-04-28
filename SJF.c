//The following programme executes Shortest Job First Scheduling in C language.
//SJF is provably optimal, in that for a given set ofprocesses and their CPU bursts/execution 
//times it gives the least average waiting time for each process.
#include<stdio.h>
void main()
{
int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,totalT=0,pos,temp;
float avg_wt,avg_tat;
printf("Enter number of process:");
scanf("%d",&n);
  //getting the burst time of each processes.
printf("\nEnter Burst Time of each proccesses:\n");
for(i=0;i<n;i++)
{
printf("p%d:",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}
for(i=0;i<n;i++)
{
pos=i;
for(j=i+1;j<n;j++)
{
    if(bt[j]<bt[pos])
        pos=j;
}
temp=bt[i];
bt[i]=bt[pos];
bt[pos]=temp;
temp=p[i];
p[i]=p[pos];
p[pos]=temp;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
 wt[i]+=bt[j];
total+=wt[i];   
}
  //printing the details in a tabular form.
avg_wt=(float)total/n;  
printf("\nProccess_ID  Burst_Time  Waiting_Time  Turn_Around_Time");
 printf("\n________________________________________________________");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i]; 
totalT+=tat[i];      
printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(float)totalT/n;    
  //Printing the Avarage Waiting Time and Avarage Turn Around Time
printf("\n\nAverage Waiting Time=%f",avg_wt);
printf("\nAverage Turnaround Time=%f",avg_tat);
printf("\nGANTT CHART\n");
temp=0;
printf("=================================\n");
for(i=0;i<n;i++)
 {
  printf("   P%d  ",p[i]);
 }
printf("\n=================================\n");
for(i=0;i<=n;i++)
 {
  printf("%d      ",temp);
  temp+=bt[i];
 }
}
