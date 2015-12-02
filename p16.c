#include <stdio.h>
#include <stdlib.h>

int main(){
    unsigned long long int n = 1; 
    while(n< 100000000000000000){
        printf(" %lld \n", n);
        n *= 2;
        
    }
    return 0;
}