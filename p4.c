#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h> 

typedef enum { false, true } bool;

int palindrome_test(int n){
    int digits = (n == 0) ? 1 : (int) (log10((double) n) + 1);
    int array_number[digits];
    int number = n;
    int i;
    for (i = 0; i < digits; i++){
        array_number[i] = n % 10;
        n = n / 10; 
    }
    int l = 0;
    int r = digits - 1;
    while(l <= r){
        if(array_number[l] != array_number[r]){
            return false;
        }
        l++;
        r--;
    }
    return true;
}
int main(){
    int i;
    int j;
    int largest = 0;
    int product;
    for (i = 900; i < 1000; i++){
        for (j = i; j < 1000; j++){
            product = i * j;
            if (palindrome_test(product) == true){
                largest = (largest < product) ? product : largest;
            }
        }
    }
    printf("result: %d \n", largest);
    return 0;    
}
