#include <math.h>
int main () {
	float average, SD, sum=0.0;
	int max, min, i, size, number[size], count=0;
	printf("Entert size of number\n");
	scanf("%d", & size);
	printf("Enter your numbers\n");
	for(i=0;i<size;i++){
		scanf("%d",&number[i]);
	sum= sum +number[i];
		count++;
	}
	
	average =sum/size;
	max = number[0];
	min = number[0];
	SD = sqrt(sum/size);
	for(i=0;i<size;i++){
		if(number[i]>max){
			max = number[i];
		}
	}
	for(i=0;i<size;i++){
		if (number[i]<min){
			min = number[i];
		}
	}
	printf(" the average is %f\n",average);
	printf("the max number is %d\n",max);
	printf("the min number is %d\n",min);
	printf("the Standard deviation is %f" , SD);
	return 0;
}
