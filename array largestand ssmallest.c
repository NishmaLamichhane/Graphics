#include<stdio.h>
#include<conio.h>
int main()
{
	int i,arr[20],smallest,second_smallest,largest;
	printf("\n enter 20 numbers");
	for(i=0;i<20;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(i=1;i<20;i++)
	{
		if(arr[i]<smallest)
		{
			second_smallest=smallest;
			smallest=arr[i];
		}
		else if(arr[i]<second_smallest)
		{
			second_smallest=arr[i];
		}
		else if(arr[i]>largest)
		{
			largest=arr[i];
		}
	}
		printf("\n second smallest number is %d",second_smallest);
		printf("\n largest number is %d",largest);
	getch();
	}
