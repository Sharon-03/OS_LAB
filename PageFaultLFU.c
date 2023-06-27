#include<stdio.h>
int main()
{
 int i,j,count[50],frames[10],pages[50],fn,pn,flag,fPos;
 printf("Enter the number of pages : ");
 scanf("%d",&pn);
 printf("Enter the reference string : "); 
 for(i=0;i<pn;i++)
 {
  scanf("%d",&pages[i]);
  count[i]=0;
 }
 printf("Enter the number of frames : ");
 scanf("%d",&fn);
 printf("\nPage\t\tFrames\n");
 for(i=0;i<fn;i++)
	frames[i]=-1;
 for(i=0;i<pn;i++)
  {
   flag=0;
   fPos=0;
   for(j=0;j<fn;j++)
  {
   if(frames[j]==pages[i])
    {
     flag=1;
     break;
    }
    if(count[frames[fPos]]>count[frames[j]])
     {
      fPos=j;
     }
   }
   if(!flag)
   {
    frames[fPos]=pages[i];
   }
  printf("%d\t\t",pages[i]); 
  if(flag)
  {
   printf("Page hit\n");
  }
  else
  {
   for(j=0;j<fn;j++)
    {
     printf("%d\t",frames[j]);
    }
   printf("\n");
  }
 count[pages[i]]+=1;
 }
 return 0;
}
