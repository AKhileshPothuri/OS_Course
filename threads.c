
/*Name:- Akhilesh Pothuri*/



#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
int *list; 
int *mlist;
int n;
// structure to pass as parameters.
typedef struct
{
	int start;
	int end;
}parameters;
// Function to sort the two halves
void * sort(void *ptr1)
{	
	parameters* ptr = (parameters*) ptr1;
	//Bubble Sort
	for(int i=(ptr->start);i<=(ptr->end);++i)
	{
		for(int j=i+1;j<=(ptr->end);++j)
		{
			if((*(list+i))>(*(list+j)))
			{
				int tmp = *(list+i);
				*(list+i)=*(list+j);
				*(list+j) = tmp;
			}
		}
	}
	return NULL;
}

//Program to merge the two sorted halves.
void * mergelist(void *ptr1)
{	
	parameters* ptr = (parameters*) ptr1;
	int a = ptr->start;
	int b = ptr->end;
	int num = 0;

	while(num<n)
	{
		if((*(list+a))<(*(list+b)))
		{
			*(mlist+num) = *(list+a);
			++a;
		}
		else
		{
			*(mlist+num)=*(list+b);
			++b;
		}
		++num;
		if(a==(n/2+1) || b==n)
		{
			if(a==(n/2+1))
			{
				for(int i=b;i<n;++i)
				{
					*(mlist+num) = *(list+i);
					++num;
				}
			}
			else
			{
				for(int i=a;i<(n/2+1);++i)
				{
					*(mlist+num) = *(list+i);
					++num;
				}
			}
			break;

		}
		
	}
	return NULL;
}
		


int main(int argc,char *argv[])
{	
	FILE *fptr;
	fptr = fopen(argv[1],"r");
	if(fptr == NULL)
	{
		printf("File not found");
		return 0;
	}


	int i =0;
	char ch;
	ch = fgetc(fptr);
	n = 0;

	while((ch)!=EOF)
	{	
		if(ch==',')
			++n;
		++i;
		ch = fgetc(fptr);
	}
	fclose(fptr);
	
	fptr = fopen(argv[1],"r");

	++n;
	char *str = (char*)malloc(i*sizeof(char));
	i = 0;
	char ac = fgetc(fptr);
	
	while(ac!=EOF)
	{
		*(str+i) = ac;
		++i;
		ac = fgetc(fptr);
	}
	fclose(fptr);
	list = (int*) malloc(n * sizeof(int));
	mlist = (int*) malloc(n* sizeof(int));

	i= 0;
	char *tmp = strtok(str,",");
	while(tmp!=NULL)
	{
	
		*(list+i) = atoi(tmp);
		++i;
		tmp = strtok(NULL,",");
	}
printf("The number of elements are %d\n\n",n);	
	pthread_t first,second,merge;
//Making two threads.
	parameters *data = (parameters *) malloc(sizeof(parameters));
	data->start = 0;
	data->end = n/2;
	pthread_create(&first,NULL,sort,data);
	parameters *data1 = (parameters *) malloc(sizeof(parameters));
	data1->start = n/2 +1;
	data1->end = n-1;
	pthread_create(&second,NULL,sort,data1);
 	parameters *data2 = (parameters *) malloc(sizeof(parameters));	
	if(pthread_join(first,NULL)==0 && pthread_join(second,NULL)==0)
	{
		printf("\n\nFirst thread sorted:\n");
		for(int i=0;i<=n/2;++i)
			printf("%d ",*(list+i));
		printf("\n\nSecond thread sorted:\n");
		for(int i=(n/2)+1;i<n;++i)
			printf("%d ",*(list+i));
		data2->start = 0;
		data2->end = n/2+1;
		printf("\n\nElements before merge are:\n");
		for(int i=0;i<n;++i)
			printf("%d ",*(list+i));
		pthread_create(&merge,NULL,mergelist,data2);
	}
	if(pthread_join(merge,NULL)==0)
	{
		printf("\n\nAfter merge are:\n");
		for(int i=0;i<n;++i)
			printf("%d ",*(mlist+i));	
	fptr = fopen("Sorted_Elements","w");
	// Writing back to file.
	fprintf(fptr,"%d",*(mlist));
	
	for(int i=1;i<n;++i)
		fprintf(fptr,",%d",*(mlist+i));
	
	fclose(fptr);
	}
	printf("\n");
	return 0;

}


