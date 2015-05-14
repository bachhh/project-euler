#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
 *	2520 is the smallest number that can be divided by each 
 *	of the numbers from 1 to 10 without any remainder.
 *
 *	What is the smallest positive number that is 
 *	evenly divisible by all of the numbers from 1 to 20?
 *
 */
 
typedef enum { false, true } bool;

bool prime_test(int number){
	int i;
	if (number <= 1){
		return false;
	}
	for (i = 2; i <= sqrt(number); i++){
		if ( number % i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int limit = 20;
	int multiple = 1;

	for (int i = 2; i < limit; i++){
		if (prime_test(i) == true){
			int j = 1;
			int temp = (int) pow(i, j);
			while (temp < limit){
				temp = pow(i, ++j);
			}
			multiple = multiple * (int) pow(i, j - 1);
		}
	}
	printf("%d \n", multiple);
}