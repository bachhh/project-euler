#include <stdio.h>

/*	If we list all the natural numbers below 10 
 *	that are multiples of 3 or 5, we get 3, 5, 6 and 9. 
 *	The sum of these multiples is 23.
 *
 *	Find the sum of all the multiples of 3 or 5 below 1000.
 */

int main(){
	int result = 0;
	for (int i = 0; i < 1000; i++){
		result += (i % 3 == 0) ? i : (i % 5 == 0) ? i : 0;
	}
	printf("Result: %d \n", result);
}