#include<stdio.h>
#include<conio.h>
int main()
{
	int i,n,arr[20];
	float avg,sum=0;;
	printf("\n enter n numbers");
	scanf("%d",&n);
	printf("\n enter %d numbers",n);
		for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	sum=sum+arr[i];
}
	avg=sum/n;
	printf("\n average of the numbers is %.2f",avg);
	getch();
}
	
