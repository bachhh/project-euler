#include <stdio.h>
#define COUNT 1000000

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
    
    
        int triangular = 28; // initial
        while (1){
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
            if (cardinality >= 500) break;
            triangular += triangular + 1;
        }
        
    return 0;
}