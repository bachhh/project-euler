#include <stdio.h>
#include <math.h>

/*
 *	The prime factors of 13195 are 5, 7, 13 and 29.
 *
 *	What is the largest prime factor of the number 600851475143 ?
 *
 */
 
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