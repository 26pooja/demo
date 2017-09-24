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
char buff[256];
char *name="/Desktop";

char * home_dir = getenv ("HOME");
char * user = getenv ("USER");
//getlogin_r(buff,sizeof(buff));
printf("%s",user);
strcat(home_dir,user);
strcat(home_dir,name);
printf("%s",home_dir);
printf("Parent process running\n");
if(fork() == 0)
{	
         
	printf("Child process running\n");
         fd=creat("demo.txt",0777);
        if ((dir = opendir(home_dir)) == NULL)
         {
	       printf("Unable to open specified directory\n");
	       return -1;
         }

         while ((entry = readdir(dir)) != NULL)
          {
              sprintf(buff,"%s\n",entry->d_name);
             write(fd,buff,256);
           
          }   
           

         return 1;
}
ret=wait(&status);

printf("Parent terminates\n");
return 0;
}
