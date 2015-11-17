#include <stdio.h>
#define COUNT 1000000


/* 
 *      Honestly I've discovered how to use the index of array as an 
 * integer value itself, here's my  things 
 * 
 */
int main(){
    int sieve[COUNT];
    for (int i = 0; i < COUNT; i++) sieve[i] = i;
    for (int i = 2; i < (COUNT/2); i++){
        if(sieve[i] == i){
            int multiples = 2*i;
            do{
                sieve[multiples] = i;
                multiples += i;
            } while(multiples < COUNT);
        }
    }
    for (int i = 1; i < COUNT; i++) if(sieve[i] == 0) printf("Zero value %d \n", i);
    
        long long int triangular = 1; // initial
        int n = 1;           // 7th triangular number
        while(1){
            int factors[COUNT] = {0};
            int divider = triangular;
            do {
                int factor = sieve[divider];
                if (factor > 1) factors[factor]++;
                divider = divider/factor;
            } while (divider > 1);
            
            int cardinality = 1;
            for (int i = 0; i < COUNT; i++){
                if(factors[i] > 0) cardinality *= (factors[i] + 1);
            }
            if(cardinality >= 500) break;
            n++;
            triangular += n;
        }
        printf("Triangular = %lld \n", triangular);
    return 0;
}