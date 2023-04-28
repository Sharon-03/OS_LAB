//The following program executes priority scheduling using C language
//Priority scheduling is a non-preemptive algorithm and one of the most common scheduling 
//algorithms in batch systems. Each process is assigned a priority. Process with highest priority is 
//to be executed first and so on. Processes with same priority are executed on first come first served basis.


#include<stdio.h>
struct proccess
{
 int priority,bt,tat,wt,pos;
};
void main()
{
  int n,i,j,totaltat,totalwt;
  float avgwt=0.0,avgtat=0.0;
  printf("Enter the no.of proccesses: ");
  scanf("%d",&n);
  int array[10];
  struct proccess p[n];
  //Getting the burst time and priority.
  printf("\nEnter the burst time and priority of each proccesses: ");
  for(i=0;i<n;i++)
  {
   printf("\nP[%d]->burst time: ",i+1);
   scanf("%d",&p[i].bt);
   printf("\nP[%d]->prority: ",i+1);
   scanf("%d",&p[i].priority);
   p[i].pos=i+1;
 }

 //sorting according to priority.
  int t=0;
for(i=0;i<n;i++)
 {
  for(j=0;j<n-i-1;j++)
  {
   if(p[j].priority>p[j+1].priority)
   {
    struct proccess temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
  }
 }
 //Printing Gantt Chart
 printf("\nGANTT CHART\n");

 printf("=================================\n");

 for(i=0;i<n;i++)
  {
   printf("   P%d  ",p[i].pos);
  }
 

 printf("\n=================================\n");
 for(i=0;i<=n;i++)
  {
   printf("%d      ",t);
   t+=p[i].bt;
  }
//Avarage waiting time and Turnaround
 p[i].wt=0;
for(i=1;i<n;i++)
 {
  p[i].wt=p[i-1].bt+p[i-1].wt;
 } 
 for(i=0;i<n;i++)
 {
  p[i].tat=p[i].bt+p[i].wt;
 }
 for(i=0;i<n;i++)
 {
  totalwt+=p[i].wt;
  totaltat+=p[i].tat;
 }
 avgwt=(float)totalwt/n;
 avgtat=(float)totaltat/n;
 printf("\nAvarage Waiting Time = %f",avgwt);
 printf("\nAvarage Turn Around Time = %f",avgtat);
 printf("\nProccess_ID  Burst_Time  Waiting_Time  Turn_Around_Time");
 printf("\n________________________________________________________");
 for(i=0;i<n;i++)
 {
  printf("\nP[%d] \t\t%d\t\t%d\t\t%d\n",p[i].pos,p[i].bt,p[i].wt,p[i].tat);
 }
}
