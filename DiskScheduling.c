#include<stdio.h>
#include<stdlib.h>
void main()
{
 int i,j,init,np,dir,temp1,temp,temp2,size,totaldisk,req[50],cont;
 printf("\n Enter the no.of proccesses: ");
 scanf("%d",&np);
 printf("\n Request sequence.");
 for(i=0;i<np;i++)
 {
  scanf("%d",&temp1);
  req[i]=temp1;
 }
 printf("\n Enter the disk size.");
 scanf("%d",&size);
 size--;
 printf("\n 1) --> FCFS\n 2) --> SCan \n 3) --> CScan\n");
 scanf("%d",&temp2);
 do
 {
  switch (temp2)
  {
	 case 1:
	         printf("\n		FCFS		");
		 printf("\n_____________________________");
		 printf("\n Enter the initial disk position.");
		 scanf("%d",&init);
		 totaldisk=0;
		 for(i=0;i<np;i++)
		 {
		  totaldisk+=abs(req[i]-init);
		  init=req[i];
		 }
		 printf("\n Totaldisk size = %d",totaldisk);
	case 2:
	         printf("\n		SCAN		");
		 printf("\n_____________________________");
		printf("\n Enter the initial disk position(index).");
		 scanf("%d",&init);
		 totaldisk=0;
	      printf("\n Enter direction of head (0 for left to right 1 for right to left) : ");
		    scanf("%d",&dir);
		    for(i=0;i<np;i++)
		    {
 			for(int j=0;j<np-i-1;j++)
			{
 			    if(req[j]>req[j+1]){
				temp=req[j];
				req[j]=req[j+1];
				req[j+1]=temp;
			    }
			}
		    }
		    if(dir==0){
			totaldisk=(size-init)+(size-req[0]);
		    }
		    else{
			totaldisk=(init+req[np-1]);
		    }
    	    printf("\n The  disk movement : %d\n",totaldisk);
      case 3:
                  printf("\n		CSCAN		");
		 printf("\n_____________________________");
                 printf("\nEnter the initial disk position : ");
	    scanf("%d",&init);
	    printf("\nEnter direction of head (0 for left to right any other number for right to left) : ");
	    scanf("%d",&dir);
	    for(i=0;i<np;i++){
		for(int j=0;j<np-i-1;j++){
		    if(req[j]>req[j+1]){
		        temp=req[j];
		        req[j]=req[j+1];
		        req[j+1]=temp;
		    }
		}
	    }
	    int point=init;
	    for(i=0;i<np;i++){
		if(req[i]>point){
		    point=req[i-1];
		    break;
		}
	    }
	    if(!dir){
		totaldisk=(size-init)+(point)+size;
	    }
	    else{
		totaldisk=(init+req[np-1]);
	    }
	    printf("\nThe total disk movement : %d\n",totaldisk);
      default:
              printf("\nDo you want to continue?  (1 => Yes / 0 => No) \n");
              scanf("%d",&cont);
   }
  }while(cont==1);
 }





