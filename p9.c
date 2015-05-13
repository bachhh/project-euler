#include <stdio.h>
/* 
 *
 *  A Pythagorean triplet is a set of three natural numbers 
 *  a < b < c, for which,
 *  a^2 + b^2 = c^2
 *
 *  For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 *
 *  There exists exactly one Pythagorean triplet for which 
 *  a + b + c = 1000.
 *  Find the product abc.
 *
 */
 
/*          
 *  ### Math ###
 *  (a + b) = 1000 - c
 *  (a + b)^2 = (1000 - c)^2
 *  a^2 + b^2 + 2ab = 1000^2 - 2000c + c^2, also: a^2 + b^2 = c^2
 *  ab/500 = 1000 - 2c
 *  a b are natural number -> ab/500 > 0 -> 1000 -2c > 0 -> c < 500
 *   0 < c < 500 -> 1000 - 2c belongs to N -> ab % 500 == 0
 *
 */
 

int binary_search(int* array,int length, int key){
    int l = 0; r = length;
    int pivot = (l + r) / 2;
    while( l <= r){
        if ( key < array[pivot]){
            r = pivot-1, pivot = (l + r)/2;
        }
        else if ( key > array[pivot]{
            l = pivot+1, pivot = (l + r)/2;
        }
        else{
            return pivot;
        }
    }
    return -1; // key not found
}

int main(){
    int a, b, c;
    int array_c[500], array_a[334], array_b[500];
    for (int i = 0; i < 500; i++){
        array_c[i] = i*i;
        array_b[i] = i*i;
    }
    for (int i = 0; i < 334; i++){
        array_a[334] =  i * i;
    }
    
    for (a = 0;  a < 334; a++){
        for (b = 500/a; b < 500 && b 
    }
        
        
        
        
}
