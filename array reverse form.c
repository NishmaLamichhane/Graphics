#include<stdio.h>
#include<conio.h>
int main()
{
	int i,arr[10];
	printf("\n enter 10 numbers");
	for(i=0;i<10;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n enter the numbers in reverse order");
	for(i=9;i>=0;i--)
{
	printf("\t%d",arr[i]);
	}	
	getch();
}
