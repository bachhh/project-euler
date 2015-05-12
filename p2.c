#include <stdio.h>

int main(){
	int result = 0, f1 = 1, f2 = 2;
	int limit = 4000000;
	while (f2 < limit){
		result += (f2 % 2 == 0) ? f2 : 0;
		f2 = f1 + f2;
		f1 = f2 - f1;
	}
	printf("Result: %d \n", result);
	return 0;
}