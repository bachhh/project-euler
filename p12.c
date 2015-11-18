#include <stdio.h>
#include <stdlib.h>
#define COUNT 100000000


/* 
 *  Honestly I've discovered how to use the index of array as an 
 * integer value itself, here's my augmented Sieve of Eratothense
 *  
 *  Each index are the largest prime factor of that index. Or itself
 * if the index is prime.
 * 
 */


int divisors(long int number, long int* sieve){
    if ( number > COUNT) printf("ERROR! number out of sieve range!\n");
    if ( number % 2 == 0) number = number/2;
    long int divider = number;
    int divisors = 1;
    int prevfactor = sieve[divider];
    int exponent = 1;
    while(divider > 1){
        int factor = sieve[divider];
        divider = divider/sieve[divider];
        if ( factor != prevfactor){
            divisors *= exponent;
            exponent = 1; // reset exponent
        }
        exponent++;
        prevfactor = factor;
    }
    divisors *= exponent;
    return divisors;
    
}

int main(){
    // Augmented Sieve
    long int *sieve = malloc(COUNT*sizeof(long int));
    int primecount = 0;
    for (long int i = 0; i < COUNT; i++) sieve[i] = i;
    for (long int i = 2; i < (COUNT/2); i++){
        if(sieve[i] == i){
            primecount++;
            long int multiples = 2*i;
            do{
                sieve[multiples] = i;
                multiples += i;
            } while(multiples < COUNT);
        }
    }
    
    long int prevN = 1, nextN = 2;
    int prevNdivisors = divisors(prevN, sieve);
    int nextNdivisors = divisors(nextN, sieve);
    int totaldivisors = prevNdivisors * nextNdivisors;
    while (totaldivisors < 502){
        prevN = nextN;
        prevNdivisors = nextNdivisors;
        nextN++;
        nextNdivisors = divisors(nextN, sieve);
        totaldivisors = prevNdivisors * nextNdivisors;
    }
    printf("Triangular = %ld \n", prevN*nextN/2);
    
    return 0;
}