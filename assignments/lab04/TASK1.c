#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define FORK_DEPTH 3

int main(){
	int i, r;
	pid_t my_pid;
	
	my_pid = getpid();

	for(i = 1; i <= FORK_DEPTH; i++){
		r = fork();
//		printf("----------------------------->%d %d\n", r, getpid());
		printf("[OUTSIDE] my_pid->%d, pid=>%d\n", my_pid, getpid());
		//printf("i-------------------->%d\n", i);
		if(r>0){		
		//	printf("i-------------------->%d\n", i);
			printf("[PARENT] my_pid->%d, pid=>%d\n", my_pid, getpid());
			printf("Parent process %d forked child process %d\n", my_pid, r);
		}else if(r==0){
  //         		printf("here when r==0\n");
  		       printf("[CHILD] my_pid->%d, pid=>%d\n", my_pid, getpid());
                       my_pid = getpid();
		       printf("----------------------------->%d %d\n", r, getpid());
                       if(i == FORK_DEPTH){
			      printf("here when i == 3 pid is=>%d and r=>%d\n", getpid(), r);
                              r = execl("/bin/echo", "/bin/bash", "Hello World\n", NULL);
			      //printf("\n");
                              exit(1);
                       }
                }else{
//			printf("here\n");
                       	exit(1);
                }
	}
	return 0;
}                                                                                                                                                                                                           
