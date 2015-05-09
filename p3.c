#include <stdio.h>
#include <math.h>

int main(){
	long number;
	printf("Enter number: \n");
	scanf("%ld", &number);
	int i;
	for (i = 0; i <= number; i++){
		if (number % i == 0){
			number = number / i;
		}
	}
	printf("Largest prime factor: %ld \n", i);
	return 0;
}