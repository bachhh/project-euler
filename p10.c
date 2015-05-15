#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 *	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 *	Find the sum of all the primes below two million.
 *
 */


int main(void){
	int x = 2000000;
	int array[x];

	// 	Implemented prime sieve of Eratosthenes
	for (int i = 2; i < x; i++){
		array[i] = 1, array[0] = 0, array[1] = 0;
	}
	for (int i = 2; i <= (int)sqrt(x); i++){
		if (array[i] == 1){
			for (int j = i*i; j <= x; j += i){
				array[j] = 0;
			}
		}
	}

	long sum = 0;
	for (int i = 0; i < x; i++){
		sum += (array[i] == 1) ? i : 0;
	}

	printf("Sum = %ld \n", sum);
	return 0;
}