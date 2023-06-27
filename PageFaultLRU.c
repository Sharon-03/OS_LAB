#include<stdio.h>
int fq[10],frames[10],pages[50],front=-1,rear=-1;
int pop()
{
	int t = fq[rear];
	rear=(rear+1)%10;
	return t;
}
void push(int n)
{
  if(rear==-1)
   {
	 rear=0;
    }
 front=(front+1)%10;
 fq[front]=n;
}
 int main()
 {
  int i,j,nf,np,fPos,flag;
  printf("Enter the number of pages : ");
  scanf("%d",&np);
  printf("Enter the sequence : ");
  for(i=0;i<np;i++)
  scanf("%d",&pages[i]);
 printf("Enter the number of frames : ");
 scanf("%d",&nf);
 for(i=0;i<nf;i++)
 frames[i]=-1;
 printf("Page\t\tFrames\n");
 for(i=0;i<np;i++){
 flag=0;
 for(j=0;j<nf;j++){
  if(frames[j]==pages[i])
  {
   flag=1;
   pop();
   push(j);
   break;
 }
 else if(frames[j]==-1)
 {
  frames[j]=pages[i];
  push(j);
  flag=-1;
  break;
 }
}
 if(flag==0)
 {
  fPos=pop();
  frames[fPos]=pages[i];
  push(fPos);
 }
printf("%d\t\t",pages[i]);
if(flag<1)
 {
  for(j=0;j<nf;j++)
  {
   printf("%d\t",frames[j]);
  }
 printf("\n");
 }
 else
 {
  printf("page hit\n");
 }

 }
 return 0;
}
	
