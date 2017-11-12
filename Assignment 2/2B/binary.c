#include <stdio.h>
#include <stdlib.h>

int a[20];

int main(int argc,char *argv[])
{
	int i,key,low,high,mid;
	int flag;
	for(i=0;i<argc;i++)
		a[i] = atoi(argv[i]);
	printf("\nEnter the Element to be searched");
	scanf("\n%d",&key);
	
	low=0;
	high=argc-1;
	mid=(high/2);
	while(low <= high){
		if(key == a[mid])
		{	
			printf("\n%d Found at location %d",key,mid+1);
			flag=1;
			break;
		}
			
		else if(key < a[mid])
			high=mid-1;
		else{
			low = mid+1;
		}
		mid=(low+high)/2;			
	}
	if(flag==0)
		printf("\nElement not found");
		
	return 0;
}
