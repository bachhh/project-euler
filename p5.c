#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

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
	int limit;
	int i;
	int j;
	int multiple = 1;
	printf("Enter limit \n");
	scanf("%d", &limit);

	for (i = 2; i < limit; i++){
		if (prime_test(i) == true){
			j = 1;
			int temp = (int) pow(i, j);
			while (temp < limit){
				temp = pow(i, ++j);
			}
			multiple = multiple * (int) pow(i, j - 1);
		}
	}

	printf("%d \n", multiple);
}