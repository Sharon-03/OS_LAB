//Program 1

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
//#include<sys/wait.h>
int main()
{
 pid_t pid;
 pid= fork();
 if(pid<0)
 {
  printf("\nChild process ID is:  %d%d",getpid(),getppid());
  exit(0);
 }else if(pid==0){
  printf("\nChild process is:  %d",getpid());
  printf("\nParent process is: %d",getppid());
 }else{
 //wait(NULL);
 printf("\nChild Complete \n Parents ID:  %d ",getpid()); 
 }
 return(0);
}

//Program 2
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
char *args[]={"./EXEC",NULL};
execvp(args[0],args);
printf("TERMINATED\n");
return(0);
}

//EXEC


#include<stdio.h>
#include<unistd.h>
int main()
{
printf("This file is called by syscall2a.c .");
printf("\nHAI,BYE\n");
return(0);
}
