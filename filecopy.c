/* Names: Akhilesh Pothuri
Explain your steps as comments in the code itself.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include<stdlib.h>
#define READ_END 0
#define WRITE_END 1

int main(int argc, char *argv[]){

    int x, y;
    int fd[2];                    /* pipe file descriptor */
    pid_t cpid;                   /* Process id : pid of child in parent, 0 in child */ 
    FILE *fp;                     /* file pointer to open files  */
    FILE *fc;
    char *c = (char *) malloc(sizeof(char));

    pipe(fd);                     /* create pipe */
  
    char inbuf[1];                 /* data retrieved from pipe */
	
	fflush(stdin);
	
    if(argc != 3){
	
    printf("Invalid number of arguments.\n");
	
    }
	
    else{
    
    		
      		fp = fopen(argv[2], "r");
      		
      		if(fp != NULL){
      			printf("File already exists. Overwrite? 1 for yes, 0 for no \n");
      			scanf("%d", &x);
      			if(x == 0){
      				exit(0);
      			}
      			
      			fclose(fp);
      		}
      		
      

    	if((cpid = fork()) == -1){
		
      	perror("fork");
      	exit(1);
		
    	}
	
    	if(cpid == 0){
		
      		/* child only reads. Close the write end */
      		close(fd[WRITE_END]);
      		
      		/* First Check if destination file exists */
      		
      
      		/* Open the destination file and read from pipe */
      
      		fp = fopen(argv[2], "w");
			while(read(fd[READ_END],inbuf,1) == 1){
				fprintf(fp,"%s",inbuf);
      		}
      
      		close(fd[READ_END]);
      
      
      		/* Create the destination file if it does not exist */
      		if(fp == NULL){
	
      		}
      		
      		fclose(fp);
		
    	}else{
	
      		/* parent only writes. Close the read end */
      		close(fd[READ_END]);
      
      		/* Open the source file and write to pipe */
      		fp = fopen(argv[1], "r");

      		/* Print error message if the source file does not exist */
      		if(fp == NULL){
			printf("Error : Source File not found\n");
			exit(0);
      		}

      		/* Else, Write to the pipe */
      		else{
			while((*c = getc(fp)) != EOF){
				if(write(fd[WRITE_END], c, 1) < 1){
    				printf("Write Failed\n");
   				exit(0);
  				}
			}
      		}
printf("Content Copied Successfully\n");
      		close(fd[WRITE_END]);
      		fclose(fp);
      		
    	}
  	}
  	return 0;
}

