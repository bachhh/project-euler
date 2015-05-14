#include <stdio.h>
#include <math.h>
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


/*			Background:
 *
 *		a + b + c = 1000
 *	and a^2 + b^2 = c^2 
 * 
 * 	gives ab/500 = 1000-2c, since a b c are positive integers
 *	ab > 0 => 1000-2c > 0
 *	
 *	thus a < b < c < 500
 *		 ab mod 5 = 0 
 *
 */

int binary_search(int* array,int length, int key){
    int l = 0; 
	int r = length;
    int pivot = (l + r) / 2;
    while( l <= r){
        if ( key < array[pivot]){
            r = pivot-1, pivot = (l + r)/2;
        }
        else if ( key > array[pivot]){
            l = pivot+1, pivot = (l + r)/2;
        }
        else{
            return pivot;
        }
    }
    return -1; // key not found
}

int main(){
    int a, b, c, array_c[500], array_a[500], array_b[500];
    
    // 3 arrays of perfect square.
    for (int i = 0; i < 500; i++){
    	array_a[i] = array_b[i] = array_c[i] = i*i;
    }

    for (a = 1;  a <= 500; a++){
        for (int i = a*(a+1)/500; i < a; i++){
        	// if i <= (a^2/500) then b <= a
    		// if i >= a then b => 500 > c
        	int ab = 500*i; 
        	if (ab % a != 0 ){
        		continue;
        	}
        	b = ab / a;
    		c = binary_search(array_c, 500, array_a[a] + array_b[b]);
    		if (c != -1 && a + b + c == 1000){
    			goto found;
    		}
        }
    }
    found: printf("Product a*b*c = %d \n", a*b*c);
}
