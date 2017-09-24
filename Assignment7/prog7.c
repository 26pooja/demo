#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
#include <dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{

DIR *dir;
struct dirent *entry;
int fd,ret,status;
char buff[256],buff1[256];
int count1,count2;
int fd2;
fd2=creat("count.txt",0777);
printf("Parent process running\n");
if(fork() == 0)
{	
         
	printf("Child process1 running\n");
         
        if ((fd=open("demo.txt",O_RDONLY))<0)
         {
	       printf("Unable to open file\n");
	       return -1;
         }
         while((ret=read(fd,buff,sizeof(buff)))!=0)
          {
            for(int i=0;i<ret;i++)
             {
                  if(buff[i]>='A' && buff[i]<='Z')
                   count1++;
          
             }
          }
           fd2=open("count.txt",O_WRONLY);
           sprintf(buff1,"Count of demo.txt-%d",count1);
           write(fd2,buff1,sizeof(buff1));
            close(fd2);
         return 1;
}
if(fork() == 0)
{	
         
	printf("Child process2 running\n");
        
        if ((fd=open("hello.txt",O_RDONLY))<0)
         {
	       printf("Unable to open file\n");
	       return -1;
         }
         while((ret=read(fd,buff,sizeof(buff)))!=0)
          {
            for(int i=0;i<ret;i++)
             {
                  if(buff[i]>='A' && buff[i]<='Z')
                   count2++;
          
             }
          }
           fd2=open("count.txt",O_WRONLY);
           
           sprintf(buff1,"Count of hello.txt-%d",count2);
           write(fd2,buff1,sizeof(buff1));
            close(fd2);
         return 1;
}
ret=wait(&status);

printf("Parent terminates\n");
return 0;
}
