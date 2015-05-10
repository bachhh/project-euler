#include <stdio.h>

/*
 *	By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13
 *	We can see that the 6th prime is 13.
 *	What is the 10 001st prime number?
 *
 */
 
typedef enum { false, true } bool;

// Take a number and a list of primes < number.
// If any one prime divides number then number is not prime.
// Else number is prime.

bool prime_check(long* array, int length, long number){
	int j;
	for (j = 0; j < length && array[j] != 0; j++){
		if (number % array[j] == 0){
			return false;
		}
	}
	return true;
}

int main(void){
	int limit;
	printf("Enter the limit ");
	scanf("%d", &limit);
	long array[limit];
	int i;
	for (i = 0; i < limit; i++){
		array[i] = 0;
	}
	array[0] = 2;
	long number;
	for (i = 1; i < limit; i++){
		for(number = array[i-1] + 1; number < 2*array[i-1]; number++){
			if (prime_check(array, limit, number) == true){
				array[i] = number;
				break;
			}
		}
	}
	printf("The %dth prime is %ld \n",limit , array[limit-1]);
	return 0;
}