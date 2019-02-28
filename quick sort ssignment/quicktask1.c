#include <stdio.h>
#include<time.h>
#include <stdlib.h>
static int count=0;
static int swaps=0;
//#define RAND_MAX 10000
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
	swaps++;
	//printf(" swaping \n");
}

int Partition(int Ar[],int low, int high)
{
	int pivot=Ar[high];
	int i=low-1;
	int j=high;
	while(1)
	{
		do{
		i=i+1;
		count++;
		}
		while(Ar[i]<=pivot && i<high&&i<=j);

		do{
		j=j-1;
		count++;
		}
		while(Ar[j]>pivot && j>0);
		
		if(i>=j)
		{
			//printf(" i value check \n");
			//printf(" %d index  of the pivot element \n",j+1);
			if(i==j && j!=high){
			swap(&Ar[j],&Ar[high]);
			//printf("\nSwaping when i==j \n");
			return j;
		}
			if((j+1)!=high)
			{
			swap(&Ar[j+1],&Ar[high]);
			}
			return j+1;
		}
		swap(&Ar[i],&Ar[j]);
	}
	
	//return j+1;
	
}

void quicksort(int Arr[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=Partition(Arr,p,r);
		quicksort(Arr,p,q-1);
		quicksort(Arr,q+1,r);
	}
}
int check(int array[])
{
	int i,flag=0;
	for(i=0;i<10000;i++)
	{
		if(array[i]<=array[i+1])
		{
			flag++;
		}
	}
	if(flag%10000!=0)
	return 1;
    else
    return 0;
}


int main()
{
	int ch;
	int A[100];
	int newArray[10000];
	int random;
	int a;
	int i,n,c,x=0;
	int RArray[10000];
	int j=0;
	//for(a=0;a<6;i++)
	//{
	printf("Enter\n1. For Unique Random Value \n2.For Ramdom values\n3.for Ascendinf Array\n4.For Desending Array\n5.For Uniform list\n6.For Sorting Of 10000 Values\n");
	scanf("%d",&c);
	
	switch(c)
	{
		case 1:
			swaps=0;
			srand(time(NULL));
			for(i=0;i<10000;i++)
				{
					RArray[i]=rand();
					for(j=0;j<i;j++)
					{
						if(RArray[j]==RArray[i])
						{
							i--;
							break;
						}
					}
				}
			quicksort(RArray,0,9999);
			printf("After sorting\n");
			
			/*for(i=0;i<10000;i++)
			{
				printf("%d\n ",RArray[i]);
			}*/
			
			printf(" TEST : Unique Random Value\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 2:
			swaps=0;
			srand(time(NULL));
			for(i=0;i<10000;i++)
				{
					RArray[i]=rand()%10000;
					
				}
			quicksort(RArray,0,9999);
			printf("After sorting\n");
			
			/*for(i=0;i<10000;i++)
			{
				printf("%d\n ",RArray[i]);
			}*/
			
			printf(" TEST : Random Value\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		
		case 3:
			swaps=0;
			srand(time(NULL));
			for(i=0;i<10000;i++)
				{
					RArray[i]=rand();
					for(j=0;j<i;j++)
					{
						if(RArray[j]==RArray[i])
						{
							i--;
							break;
						}
					}
				}
			quicksort(RArray,0,9999);	
			swaps=0;	
			quicksort(RArray,0,9999);
			printf("After sorting\n");
			
			/*for(i=0;i<10000;i++)
			{
				printf("%d\n ",RArray[i]);
			}*/
			
			printf(" TEST :Ascending Value\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 4:
			swaps=0;
			srand(time(NULL));
			for(i=0;i<10000;i++)
				{
					RArray[i]=rand();
					for(j=0;j<i;j++)
					{
						if(RArray[j]==RArray[i])
						{
							i--;
							break;
						}
					}
				}
			quicksort(RArray,0,9999);
			for(i=9999;i>=0;i--)
			{
				newArray[x]=RArray[i];
				x++;
			}	
			quicksort(newArray,0,9999);
			printf("After sorting\n");
			
			/*for(i=0;i<10000;i++)
			{
				printf("%d\n ",RArray[i]);
			}*/
			
			printf(" TEST : Descending Value\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 5:
			swaps=0;
			srand(time(NULL));
			random=rand()%10000;
			for(i=0;i<10000;i++)
			{
				RArray[i]=random;
			}
			quicksort(RArray,0,9999);
			printf("After sorting\n");
			
			/*for(i=0;i<10000;i++)
			{
				printf("%d\n ",RArray[i]);
			}*/
			
			printf(" TEST : Uniform List\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		case 6:
			swaps=0;
			srand(time(NULL));
			
			for(i=0;i<10000;i++)
				{
					RArray[i]=rand();
					for(j=0;j<i;j++)
					{
						if(RArray[j]==RArray[i])
						{
							i--;
							break;
						}
					}
				}
			quicksort(RArray,0,9999);
			printf("After sorting\n");
	
			for(i=0;i<10000;i++)
				{
					printf("%d\n ",RArray[i]);
					
				}
			printf(" TEST : 10000 Random Values\n");
			ch=check(RArray);
			if(ch==1)
			printf(" SORTED : Y\n");
			if(ch==0)
			printf(" SORTED : N\n");
			printf(" SWAPS : %d\n",swaps);
			printf(" COMPS : %d\n:",count);
			break;
		default:
		printf("Entered value is incorrect try again");
		break;
	}
	//}
	return 0;
}
