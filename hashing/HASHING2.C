#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ARRAY_SIZE 100 
typedef struct element 
{
	char name[50];
	int count;
}element; 
static int collision=0;
static int num=0;
 element* hashTabel[ARRAY_SIZE];
 

int hashFunction(char* s)
{
	long int hash=0;
	while(*s)
	{
		hash=37*hash+ *s;
		
		s++;
	}
	return (hash%ARRAY_SIZE);
}

void hashtbl()
{
	int i;
	for( i=0;i<ARRAY_SIZE;i++)
	{
		hashTabel[i]=NULL;
	}
}
void Hash(char* buff)
{
	
	element* ele=(element*)malloc(sizeof(element));
	long int index=hashFunction(buff);
	int n;n=search(buff);
	
	if(n==0)
	{
		while(hashTabel[index]!=NULL)
		{
			
		//index=hashFunction(buff);   
		collision++;
		index++;
	    }
	    strcpy(ele->name,buff);
		ele->count=n;
		hashTabel[index]=ele;
    }
    else
    {
    	hashTabel[index]->count++;
	}
    
    
}

void fileRead()
{
	
	FILE* file;
	char buffer[100];
	file=fopen("names(1).csv","r");
	do
	{
		fgets(buffer,100,file);
		int l=strlen(buffer);
		buffer[l-1]='\0';
		num++;
		Hash(buffer);  
	}
	while(!feof(file));
	fclose(file);
	printf("names.csv Loaded! ");
	//Hash(buffer);
}	

int search(char* s)
{
	int i,c=0;
	for(i=0;i<ARRAY_SIZE;i++)
	{
		if(hashTabel[i]!=NULL)
		{
		
		if((strcmp(hashTabel[i]->name,s))==0)
		{
			c++;
			break;
		}
	}
	}
	return c;
}
int searcharray(char* srch)
{
	
	int k,p=0;
	
	for(k=0;k<ARRAY_SIZE;k++)
	{
		if(hashTabel[k]!=NULL)
		{
			if((strcmp(hashTabel[k]->name,srch))==0)
			{
				
			p=hashTabel[k]->count;	
			
			return p;
			break;	
			}
		}
	}
		
return p;
}

void display()
{
	int j;
	printf("\n\tName\t\t\tOccurence\n\n");
	for(j=0;j<ARRAY_SIZE;j++)
	{
		if(hashTabel[j]!=NULL)
		{
			
			printf("\t%d\t%s\t\t\t%d\n",j,hashTabel[j]->name,hashTabel[j]->count+1);
			
		}
	}
}

int main()
{
	hashtbl();
	fileRead();
	printf("\n\tCapacity\t\t:%d",ARRAY_SIZE);
	printf("\n\tNum Terms\t\t:%d",num);
	printf("\n\tNo of collisons\t\t:%d",collision);
	printf("\n\tLoad\t\t\t:%f",(float)num/ARRAY_SIZE);
	//display();
    printf("\n\nenter the name to be searched\n");
	char check[10];
	//printf("%s",hashTabel[305]->name);
	scanf("%s",check);
	int q;
	q=searcharray(check);
	printf("%s",check);
	printf("\tOccurence\t%d",q+1);

	return 0;
}


