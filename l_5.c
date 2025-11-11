// fork

#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<stdlib.h>

int main(){
int fd[2];
pid_t pid;
char w_msg[]="THIS IS THE PARENT PROCESS ";
char r_msg[100];

if(pipe(fd)==-1){
printf("ERROR IN CREATING THE PIPE");
exit(1);
}

pid=fork();

if(pid<0){
printf("ERROR IN EXECUTION OF THE FORK");
exit(1);
}

if(pid>0){
close(fd[0]);
write(fd[1],w_msg,strlen(w_msg)+1);

wait(NULL);
}

else{
close(fd[1]);
read(fd[0],r_msg,sizeof(r_msg));
printf("THIS IS CHILD PROCESS THE MSG FROM PARENT IS - %s \n",r_msg);

}

return 0;

}
