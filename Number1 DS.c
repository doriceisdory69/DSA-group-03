#include<stdio.h>
void exchange(int *p, int *q){//function to exchange two variable
int temp;
temp=*p;
*p=*q;
*q= temp;
}

int main(){
	int num1, num2;
	printf("enter two numbers\n");
	scanf("%d%d", &num1, &num2);
	printf("\nThe number before exchange: %d   %d", num1, num2);
	exchange(&num1, &num2);
    printf("\nThe number after exchange: %d   %d", num1, num2);
	return 0;
}

