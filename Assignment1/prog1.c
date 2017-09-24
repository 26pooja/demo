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
	printf("Child process running\n");
	printf("PID of child process is %d\n",getpid());
	
	return 1;
}

pid = wait(&status);

printf("Child process having PID %d terminates with exit status %d\n",pid,status);

return 0;
}
