//The following program simulates FCFS(First Come First Serve) scheduling using C program 
#include<stdio.h>
void main()
{
int n,i=0;
float avgwt=0.0,avgtat=0.0;
printf("Enter the no.of processes: \n");
scanf("%d",&n);
int btime[n],wtime[n],tattime[n];
printf("Enter the burst time of each proccesses: ");
for(i=0;i<n;i++)
 {
  printf("\nP[%d]:   ",i+1);
  scanf("%d",&btime[i]);
 }
wtime[0]=0;
for(i=1;i<n;i++)
 {
  wtime[i]=btime[i-1]+wtime[i-1];
 } 
 for(i=0;i<n;i++)
 {
  tattime[i]=btime[i]+wtime[i];
 }
 int totalwt=0,totaltat=0;
 for(i=0;i<n;i++)
 {
  totalwt+=wtime[i];
  totaltat+=tattime[i];
 }
 avgwt=(float)totalwt/n;
 avgtat=(float)totaltat/n;
 printf("\nAvarage Waiting Time = %f",avgwt);
 printf("\nAvarage Turn Around Time = %f",avgtat);
 printf("\nProccess_ID  Burst_Time  Waiting_Time  Turn_Around_Time");
 printf("\n________________________________________________________");
 for(i=0;i<n;i++)
 {
  printf("\nP[%d] \t\t%d\t\t%d\t\t%d\n",i,btime[i],wtime[i],tattime[i]);
 }
printf("\nGANTT CHART\n");
int temp=0;
printf("=================================\n");
for(i=0;i<n;i++)
 {
  printf("   P%d  ",i+1);
 }
printf("\n=================================\n");
for(i=0;i<=n;i++)
 {
  printf("%d      ",temp);
  temp+=btime[i];
 }
}
