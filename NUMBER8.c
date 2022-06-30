#include<stdio.h>
#include<string.h>
#include<math.h>
struct statistics{
	float data[100];
char name[20];
}stat;
int main(){		
int i,size,sum=0,max,min,total=0;	
float avg=0,standard=0;	
float data[100];	
char name[20];		
printf("enter the statistics size\n ");
	scanf("%d",&size);	
	printf("enter the statistics data\n");
	for(i=1; i<=size; i++)	{	
	scanf("%d", &stat.data[i]);	
}	
min=max=stat.data[0];	
for(i=1; i<=size; i++)	{	
	total=total+stat.data[i];	
	avg=total/size;	
	if(min>stat.data[i])	
	{		

min=stat.data[i];		
}		
if(max<stat.data[i])		{	
		max=stat.data[i];	
	}
 }
  for(i=0;i<size;i++){     
 sum+=(stat.data[i]-avg)*(stat.data[i] -avg); 
  standard=sqrt(sum/size);
}  
  printf("enter the user name\n ");	
scanf("%d",&stat.name); 
   printf("the user name is %d\n",stat.name); 
   printf("statistics data are %d\n",stat.data[i]);   
printf("the total is %d\n",total); 
  printf("the avarage is %.2f\n",avg);  
  printf("the minimum is %d\n",min);
   printf("the maximum is %d\n",max); 
  printf("the standard is %.2f\n",standard);
Return 0;
}

