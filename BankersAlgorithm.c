#include<stdio.h>
void main()
{
int n,r,i,j,ind=0,flag,k,count,ans[ind],y;
printf("\n Enter no.of proccesses: ");
scanf("%d",&n);
printf("\n Enter no.of resources: ");
scanf("%d",&r);
int alloc[n][r],max[n][r],available[r],finish[n],a[n],need[n][r];
for(i=0;i<=n;i++)
 {
  printf("Enter the allocated resources of proccess P%d : ",i);
  for(j=0;j<r;j++)
  {
   scanf("%d",&alloc[i][j]);
  }
 }
 printf("\n");
for(i=0;i<=n;i++)
 {
  printf(" Enter the maximum of resources of proccess P%d : ",i);
  for(j=0;j<r;j++)
  {
   scanf("%d",&max[i][j]);
   finish[i]=0;
  }
 }
  printf("\n Enter the available resources  : ");
  for(j=0;j<r;j++)
  {
   scanf("%d",&available[j]);
  }
  for(i=0;i<r;i++)
  {
   finish[i]=0;
  }
  for(i=0;i<=n;i++)
 {
  for(j=0;j<r;j++)
  {
   need[i][j]=max[i][j]-alloc[i][j];
  }
 }
 printf("\nProccess\tAllocation\tMaximum\t\tNeed");
 printf("\n");
 for(i=0;i<=n;i++)
 {
   printf("P%d",i);
 printf("\t\t");
 for(j=0;j<r;j++)
   printf(" %d",alloc[i][j]);
 printf("\t\t");
 for(j=0;j<r;j++)
  printf(" %d",max[i][j]);
 printf("\t\t");
 for(j=0;j<r;j++)
   printf(" %d",need[i][j]);
 printf("\n");
}
 //checking for safe sequence
 /*
 for(k=0;k<n;k++)
 {
  for(i=0;i<n;i++)
  {
  if(finish[i]==0)
   {
    flag=0;
    for(j=0;j<r;j++)
    {
     if(need[i][j]>available[j])
     {
      flag=1;
      break;
     }
    }
    if(flag=0)
    {
     ans[ind++]=i;
     for(j=0;j<r;j++)
       available[j]+=alloc[i][j];
     finish[i]=1;
    }
   }
  }
 }
 flag = 1;  
for (i = 0; i < n; i++)  
{  
if (finish[i] == 0)  
 {  
 flag = 0;  
 printf("The following system is not safe");  
 break;  
 }  
}  
if (flag == 1)  
*/
 {  
 printf("Following is the SAFE Sequence\n");  
 for (i = 0; i < n ; i++)  
 printf(" P%d ->", ans[i]);  
 printf(" P%d", ans[++i]);  
 }  
}
