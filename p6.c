#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
 *	The sum of the squares of the first ten natural numbers is,
 *	1^2 + 2^2 + ... + 10^2 = 385
 *
 *	The square of the sum of the first ten natural numbers is,
 *	(1 + 2 + ... + 10)^2 = 55^2 = 3025
 *
 *	Hence the difference between the sum of the squares of the
 *	first ten natural numbers and the square of the sum is 
 *	3025 − 385 = 2640.
 *
 *	Find the difference between the sum of the squares of the 
 *	first one hundred natural numbers and the square of the sum.
 */

int main(){
	printf("Enter limit \n");
	int n;
	scanf("%d", &n);
	int sum_of_square = n*(n+1)*(2*n+1)/6;
	int square_of_sum = pow((n*(n+1))/2, 2);
	printf("Result: %d \n", (int)fabs(sum_of_square - square_of_sum));
	return 0;
}