#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define Array_size 20000
#define buff_size 256

static int count=0;
static int swaps=0;

//#define RAND_MAX 10000

typedef struct element
{
	int score;
	char title[buff_size];
	char platform[buff_size];
	int year;
}element;

element* GameArray[Array_size];
static int s=0;

void swap(element **x,element **y)
{
	element *temp;
	temp=*x;
	*x=*y;
	*y=temp;
	swaps++;
	//printf(" swaping \n");
}
 
/*void next_field(FILE *f,char *buffer,int max)
{
	int i=0,flag=0;
	while(!feof(f)&&buffer[i]!='\n')
	{
		buffer=fgetc(f);
		if(buffer[i]=='"')
		{
			flag=!flag;
			buffer[i]=fgetc(f);
		}
		if(buffer[i]==',')
		{
			break;
		}
		if(i<max-1)
		{
			i++;
		}	
	}
	buffer[i]=0;
}*/

 void next_field( FILE *f, char *buf, int max ) {
	int i=0, end=0, quoted=0;
	
	for(;;) {		
		buf[i] = fgetc(f);
		
		if(buf[i]=='"') { quoted=!quoted; buf[i] = fgetc(f); }
		
		if(buf[i]==',' && !quoted) { break; }
		
		if(feof(f) || buf[i]=='\n') { end=1; break; } 
		
		if( i<max-1 ) { ++i; } 
	}
	buf[i] = 0; // null terminate the string
 }
 void getData(FILE *f)
 {
 	element* p=(element*)malloc(sizeof(element));
 							 
 	char buffer[buff_size];
 	next_field(f,p->title,buff_size);
 	next_field(f,p->platform,buff_size);
 	next_field(f,buffer,buff_size);
 	p->score=atoi(buffer);
 	next_field(f,buffer,buff_size);
 	p->year=atoi(buffer);
 	GameArray[s]=p;
 	//printf(" what happened\n");
 	//printf("score iss =========%d",GameArray[s]->year);
 	s++;
 	//printf("\n value of index =====%d\n",s);
 }
 
 int Partition(int low, int high)
{
	int pivot=GameArray[high]->score;
	int i=low-1;
	int j=high;
	while(1)
	{
		do{
		i=i+1;
		count++;
		}
		while(GameArray[i]->score<=pivot && i<high&&i<=j);

		do{
		j=j-1;
		count++;
		}
		while(GameArray[j]->score>pivot && j>0);
		
		if(i>=j)
		{
			//printf(" i value check \n");
			//printf(" %d index  of the pivot element \n",j+1);
			if(i==j && j!=high){
			swap(&GameArray[j],&GameArray[high]);
			//printf("\nSwaping when i==j \n");
			return j;
		}
			if((j+1)!=high)
			{
			swap(&GameArray[j+1],&GameArray[high]);
			}
			return j+1;
		}
		swap(&GameArray[i],&GameArray[j]);
	}
	//return j+1;
}
void quicksort(int p,int r)
{
	int q;
	if(p<r)
	{
		q=Partition(p,r);
		quicksort(p,q-1);
		quicksort(q+1,r);
		
	}
}


void display()
 {
 	printf("in print");
 	int i;
 	for(i=1;i<s;i++)
 	{
 		printf("%s\t|| %s\t|| \n%d\t ||%d\t",GameArray[i]->title,GameArray[i]->platform,GameArray[i]->score,GameArray[i]->year);
	 			
	 	printf("\n");
	}
 }
	
int main()
{
	int i;
	FILE *f;
	f=fopen("ign.csv","r");
	//getData(f);
	while(!feof(f))
	{
		//printf("hi");
		getData(f);
		//printf("hellooo");
		//display2(p);
	}
			quicksort(0,s-1);
			
			//printf("%d\n",GameArray[3]->score);
			printf("After sorting\n");
			//display();
			printf(" TEST : IGN Games Sorted\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			printf("The Top 10 Games From Last 20 Years are :\n");
			for(i=s-1;i>s-11;i--)
			{
				printf("%s\t|| %s\t|| \n%d\t ||%d\t",GameArray[i]->title,GameArray[i]->platform,GameArray[i]->score,GameArray[i]->year);
	 			printf("\n");
			}
			
				
	//display();
	printf(" Values are Readed");
	fclose(f);
	return 0;
}

/*int main()
{
	int A[100];
	int i,n,c;
	int RArray[RAND_MAX];
	printf("Enter\n1. For Unique Random Value \n2.For Ramdom values\n3.for Ascendinf Array\n4.For Desending Array\n5.For Uniform list\n6.For Sorting Of 10000 Values\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			swaps=0;
			printf("enter the total no of values to be entered : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
	
				printf("Enter Unique Random values In array :");
				scanf("%d",& A[i]);
		
			}
			quicksort(A,0,n-1);
			printf("After sorting\n");
			
			for(i=0;i<n;i++)
			{
				printf("%d\n ",A[i]);
			}
			printf(" TEST : Unique Random Value\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 2:
			swaps=0;
			printf("enter the total no of values to be entered : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
	
				printf("Enter Random values In array :");
				scanf("%d",& A[i]);
		
			}
			quicksort(A,0,n-1);
			printf("After sorting\n");
			
			for(i=0;i<n;i++)
			{
				printf("%d\n ",A[i]);
			}
			printf(" TEST : Random Value\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		
		case 3:
			swaps=0;
			printf("enter the total no of values to be entered : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
	
				printf("Enter Ascending values In array :");
				scanf("%d",& A[i]);
		
			}
			quicksort(A,0,n-1);
			printf("After sorting\n");
			
			for(i=0;i<n;i++)
			{
				printf("%d\n ",A[i]);
			}
			printf(" TEST :Ascending Value\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 4:
			swaps=0;
			printf("enter the total no of values to be entered : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
	
				printf("Enter Descending values In array :");
				scanf("%d",& A[i]);
		
			}
			quicksort(A,0,n-1);
			printf("After sorting\n");
			
			for(i=0;i<n;i++)
			{
				printf("%d\n ",A[i]);
			}
			printf(" TEST : Descending Value\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 5:
			swaps=0;
			printf("enter the total no of values to be entered : ");
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
	
				printf("Enter uniform values In array  :");
				scanf("%d",& A[i]);
		
			}
			quicksort(A,0,n-1);
			printf("After sorting\n");
			
			for(i=0;i<n;i++)
			{
				printf("%d\n ",A[i]);
			}
			printf(" TEST : Uniform List\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 6:
			swaps=0;
			for(i=0;i<RAND_MAX;i++)
				{
					RArray[i]=rand();
				}
			quicksort(RArray,0,RAND_MAX-1);
			printf("After sorting\n");
	
			for(i=0;i<RAND_MAX;i++)
				{
					printf("%d\n ",RArray[i]);
				}
			printf(" TEST : 10000 Random Values\n");
			printf(" SORTED : Y\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		default:
		printf("Entered value is incorrect try again");
		break;
	}

	return 0;
}*/
