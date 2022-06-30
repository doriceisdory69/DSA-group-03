#include<stdio.h>
#include<math.h>
int main(){ 
 float avg, std, var, sum1=0, k;
  int size, num, i, max, min, sum = 0, j=0;   
 printf("\nEnter number of element: "); 
 scanf("%d", &size);    int stat[size];  
  //alocate element to array 
 for(i = 0; i<size; i++) 
 {  	
printf("\nEnter element %d: ", i+1);  	
scanf("%d", &stat[i]);  
	sum = sum + stat[i]; 
 } 
 /* display array entered */ 
 for(i=0; i<size; i++)  {  
	printf("%d\t", stat[i]);  
	j++;  	
if(j==4)	  {  	
	printf("\n");  	
	j=0;	
  } 
 }    //maximum and minimum number
  int temp;
  for(i= 0; i<size; i++)  {
  	for(j=i+1; j<size; j++)	  {	
  	if(stat[i] < stat[j])		  {
  	temp = stat[j];		
  	stat[j] = stat[i];		
  	stat[i] = temp;		  }	  }  }  
max = stat[0]; 
 min = stat[size-1]; 
 avg=sum/size; 
   for(i=0; i<size; i++)  { 
   k=pow((stat[i]-avg),2);    
  	sum1 = sum1 + k; 
 }  var = sum1/size; 
 std = sqrt(var); 
   printf("\nstd = %.2f", std);
  printf("\nvar =%.2f", var);
  printf("\nsum = %d", sum); 
 printf("\nmax = %d", max); 
 printf("\nmin = %d", min); 
 printf("\navg = %.2f", avg);  
return 0;
}

