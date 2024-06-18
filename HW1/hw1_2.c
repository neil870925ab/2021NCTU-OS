#include <stdio.h>
#include <unistd.h>

#define MAX_LINE 80

int main(void)
{
	pid_t process_id;
	process_id = getpid();
	printf("Main process ID : %d\n\n", process_id);
	
	pid_t pid;
	pid = fork();	//fork 1
	if(pid == 0){
		pid = fork();	//fork 4
		if(pid == 0){
			pid = fork();	//fork 5
			if(pid > 0){
				printf("Fork 5. I'm the child %4d, my parent is %4d.\n", pid, getpid());	//add
				wait(NULL);
			}
		}
		else if(pid > 0){
			printf("Fork 4. I'm the child %4d, my parent is %4d.\n", pid, getpid());	//add
			wait(NULL);
		}
	}
	else if(pid > 0){
		printf("Fork 1. I'm the child %4d, my parent is %4d.\n", pid, getpid());	//add
		wait(NULL);
		pid = fork();	//fork 2
		if(pid > 0){
			printf("Fork 2. I'm the child %4d, my parent is %4d.\n", pid, getpid());	//add
			wait(NULL);
		}
		pid = fork();	//fork 3
		if(pid > 0){
			printf("Fork 3. I'm the child %4d, my parent is %4d.\n", pid, getpid());	//add
			wait(NULL);
		}
	}

	return 0;
	
}


