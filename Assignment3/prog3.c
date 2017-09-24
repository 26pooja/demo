#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{


if(fork() == 0)
{	
	printf("Child process2 running\n");
         return 1;
}
if(fork()==0)
{
      printf("Child process3 running\n");
       return 1;          
}
if(fork()==0)
{
	printf("Child process4 running\n");
      return 1;
}	

return 0;
}
