/*

NAME:- AKHILESH POTHURI
ROLL NUMBER:- 1610110049

*/
#include <stdio.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include<sys/wait.h>
int j=0;
#define MAX_LINE 80 /* define the maximum length command */
void storedata(char arr[]);
pid_t pid; int tok=0;int proper=0;
FILE *f; 
int main(void){
int should_run = 1,run=1; /* program terminator */
char command[MAX_LINE];
char *token;char *token1;
char check[100];
int k=0;
char *args[MAX_LINE/2 + 1]; /* command line arguments */
char *argss[MAX_LINE/2 + 1]; /* command line arguments */
while (should_run) {
int i=0,x=0;//count tokens
int counter=0;
printf("osh>");
fflush(stdout);

gets(command);//taking input
 storedata(command);
token=strtok(command," ");//tokenizing the command entered
//args[1]=NULL;
int wait_null=0;
while(token!=NULL){
//
    args[i++]=token;
    token=strtok(NULL," ");
}
args[i]=NULL;
//printf(args[i-1]);
int len=strlen(command);
//printf("%d",len);

if(len==2&&command[0]=='!')
{counter=0;
char *abc[100][100];FILE *fp;char str[100];
fp=fopen("historyitems.txt","r");
//printf("hiio");
if(args[0]!=NULL)
if(command[1]!='0')
{
if(command[1]=='!')
printf("yo");
else if (isdigit(command[1]))
{
while(fgets(str,sizeof(str),fp))
{
strcpy(abc[counter],str);
//printf(abc[counter]);
counter++;

}
int parse=command[1]-'0';
int h=counter-parse;
token1=strtok(abc[h]," ");//tokenizing the command entered
//args[1]=NULL;
while(token1!=NULL){
//
    args[x++]=token1;
    token1=strtok(NULL," ");}
args[x]=NULL;
return 1;}}
}
else if(strcmp(args[0],"prompt")==0&&args[1]==NULL)
{//counter=0;
char str[100];char ch[20];
int d;char *abc[100][100];int count=0;
FILE *fp,*in,*out;int pos;
fp=fopen("historyitems.txt","r");

//fseek(fp,7,SEEK_END);
//while(fscanf(fp,"%s",str)!=EOF)
//printf("%s",str);


/*fseek(fp,10,SEEK_END);
      pos=ftell(fp);
      //printf("Current postion is %d\n",pos);
      d=0;
      while(d<pos)
       {
            d++;
            fseek(fp,d,SEEK_END);
            //printf("%c",fgetc(fp));
            ch[0]=gets(fp);
            printf("%s\n",ch);
      }
      return 0;

*/

while(fgets(str,sizeof(str),fp))
{
strcpy(abc[counter-1],str);
counter++;
}int h;int r=10;
if(counter>=10)
{for(h=counter-11;h<=counter;h++)
{if(r>=1){printf("%d %s",r,abc[h]);
r--;}}}
else
{
for(h=0,r=0;h<=counter;h++)
{if(r<=10){printf("%d %s",r,abc[h]);
r++;}}
}

 
/*while(fscanf(fp,"%s",str)!=EOF)
{
//printf("%s",str);
counter++;
//abc[counter-1]=str;
//printf(abc[counter-1]);//printf("%d\n",counter);
strcpy(abc[counter-1],str);

}
int h;//printf(abc[counter-5]);
for( h=counter-10;h<counter;h++)
{

printf("%s\n",abc[h]);

}
*/

//else
//printf("%s\n",str);


// Moving pointer to end
//    fseek(q, 50, SEEK_SET);
     
    // Printing position of pointer
  //  printf("%ld", ftell(q));
//

fclose(fp);}
   else   if (strcmp(args[i-1],"&") == 0){
    wait_null = 1;
      args[i-1] = NULL;
            pid = fork();//CREATE A CHILD PROCESS
            if (pid < 0){
//printf("Helooo");
                fprintf(stderr, "Fork Failed");
                return 0;
            }else  if (pid == 0) {
	//	printf(args[0]);
//for(i=0;i<=1;i++)
//printf(args[0]);
//printf(args[1]);
//printf("Helooo");
//printf("%s",args[i-1]);
//printf(args[1]);

execvp(args[0], args);

//{
	printf("command not found\n");
	return 1;
//}
            } 
else {
//printf("Helooo");
                if(wait_null==0)
{wait(NULL);
}
} }
  else if (strcmp(args[0],"quit") == 0&& args[1]==NULL){
//printf("Helooo");
            should_run = 0;
        return 0;      
        }else{
            pid = fork();//CREATE A CHILD PROCESS
            if (pid < 0){
//printf("Helooo");
                fprintf(stderr, "Fork Failed");
                return 0;
            }else  if (pid == 0) {
	//	printf(args[0]);
//for(i=0;i<=1;i++)
//printf(args[0]);
//printf(args[1]);
//printf("Helooo");
//printf("%s",args[i-1]);
//printf(args[1]);

execvp(args[0], args);

//{
	printf("command not found\n");
	return 1;
//}
            } 
else {
//printf("Helooo");
                if(wait_null==0)
{wait(NULL);
}
}}} 
return 0;
}
/**
* After reading user input, the steps are:
* (1) fork a child process using fork()* (2) the child process will invoke execvp()
* (3) if command included &, parent will not invoke wait()
* (4) if command is quit, the shell should exit
* Explain your steps as comments in the code itself.
*/
//FILE HANDLING TO STORE DATA
void storedata(char arr[]){
    char c;int count=0;
//char word[50];
    //word[50]=arr[50];
    FILE *fp;
//    fp=fopen("historyitems.txt","r");
//printf("hey");
/*for(c=getc(fp);c!=EOF;c=getc(fp))
if(c=='\n')
count=count+1;
printf("%d",count);
 */
fp=fopen("historyitems.txt","a");
fprintf(fp,"%s\n",arr);
    fclose(fp);
    return;
}
