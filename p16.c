#include <stdio.h>
#include <stdlib.h>

int main(){
    int n[1000] = {0}; 
    n[0] = 2;
    int remain = 0;
    for (int i=0; i<999; i++){
        for (int j=0; j<1000; j++){
            int temp = n[j]*2 + remain;
            remain = temp/10;
            n[j] = temp%10;
            
        }
        remain = 0;
    }
    int result = 0;
    for(int i = 0; i < 1000; i++) result+= n[i];
    printf("%d", result);
    return 0;
}