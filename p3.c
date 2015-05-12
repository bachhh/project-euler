#include <stdio.h>
#include <math.h>

int main(){
	long number = 600851475143;
	int i;
	for (i = 1; i <= number; i++){
		if (number % i == 0){
			number = number / i;
		}
	}
	printf("Largest prime factor: %d \n", i - 1);
	return 0;
}