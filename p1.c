#include <stdio.h>

int main(){
	int result = 0;
	for (int i = 0; i < 1000; i++){
		result += (i % 3 == 0) ? i : (i % 5 == 0) ? i : 0;
	}
	printf("Result: %d \n", result);
}