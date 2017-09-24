#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{

int status1,ret1;
printf("Parent process running\n");
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
ret1=wait(&status1);

printf("Parent process terminated\n");
return 0;
}
