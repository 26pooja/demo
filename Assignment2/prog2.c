#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc,char *argv[])
{
int status;
pid_t pid;

if(fork() == 0)
{	
	printf("Child process1 running -------- Parent of Process 2\n");
	if(fork()==0)
         {
	    printf("Child process2 running -------- Parent of Process 3\n");
                 if(fork()==0)
                 {
	            printf("Child process3 running\n");
                  }
         }
	
	
}


return 0;
}
