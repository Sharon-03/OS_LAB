#include<stdio.h>
void main()
{
 int nb,nj,i,k;
 printf("\n Enter the number of blocks: ");
 scanf("%d",&nb);
 int b[nb];
 printf("\n Enter the sizes of respective blocks.\n");
 for(i=0;i<nb;i++)
 {
  printf("Block%d: ",i+1);
  scanf("%d",&b[i]);
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
 for(i=0;i<nb;i++)
{
 for(k=0;k<nj;k++)
 {
 if((j[k]<=b[i])&&(vis[k]==0))
 {
  printf("The job %d is allocated to %d\n",k+1,b[i]);
  vis[k]=1;
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
