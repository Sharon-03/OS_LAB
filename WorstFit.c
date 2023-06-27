#include<stdio.h>
void main()
{
 int nb,nj,i,k,big=0,bigindex,temp;
 printf("\n Enter the number of blocks: ");
 scanf("%d",&nb);
 int b[nb];
 printf("\n Enter the sizes of respective blocks.\n");
 for(i=0;i<nb;i++)
 {
  printf("Block%d: ",i+1);
  scanf("%d",&b[i]);
  if(b[i]>big)
  {
   big=b[i];
   bigindex=i;
  }
 }
 printf("\n Enter the number of jobs: ");
 scanf("%d",&nj);
 int j[nj],vis[nj];
 printf("\n Enter the sizes of respective jobs: \n");
 for(i=0;i<nj;i++)
 {
  vis[i]=0;
  printf("Job%d: ",i+1);
  scanf("%d",&j[i]);
 }
 //sorting
 for(i=0;i<nb;i++)
 {
  for(k=0;k<nb;k++)
  {
  if(b[i]<b[k])
   {
    temp=b[i];
    b[i]=b[k];
    b[k]=temp;
   } 
  } 
 }
for(i=0;i<nb;i++)
{
 for(k=0;k<nj;k++)
 {
  if((j[i]<=b[i])&&(vis[k]==0))
  {
  b[i]=b[i]-j[k];
  printf("The job %d is allocated to %d\n",i+1,b[i]);
  vis[i]=1;
  break;
  }
 }
}
for(k=0;k<nj;k++)
{
 if(vis[k]!=1)
  {
   printf("The job %d is not allocated\n",k+1);
  }
 }
}



