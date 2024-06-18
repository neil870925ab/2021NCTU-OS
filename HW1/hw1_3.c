#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_LINE 80

void split(char *line, char *arg[]){
	while(*line != '\0'){
		while(*line == ' ' || *line == '\n'){
			*line++ = '\0';
		}
		*arg++ = line;
		while(*line != '\0' && *line != ' ' && *line != '\n'){
			line++;
		}
	}
	
	*arg = '\0';
}

int main(void)
{
	char *arg[MAX_LINE/2+1]; /*command line arguments*/
	int should_run = 1; /*flag to determine when to exit program*/
	char input[MAX_LINE];
	
	while(should_run){
		
		printf("osh>");
		fflush(stdout);
		gets(input);
		split(input, arg);
		
		if(strcmp(arg[0], "exit") == 0){
			should_run = 0;
		}
		else{
			pid_t pid;
			pid = fork();
			if(pid < 0){
				printf("ERROR\n");
				exit(1);
			}
			else if(pid == 0){
				if(execvp(*arg, arg) < 0){
					printf("ERROR Command\n");
				}
			}
			else{
				wait(NULL);
			}
		}
		
		
		
		
		
	}
	

	return 0;
}


