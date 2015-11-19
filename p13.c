#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file_ptr;
    
    char buffer[1000];
    file_ptr = fopen("p13.txt", "r");
    if (!file_ptr) {
        printf("ERROR! no file found!\n");
        return 1;
    }
    
    int matrix[50][100];
    int r = 0, c = 0;
    while ( fgets(buffer,1000, file_ptr) != NULL){
        c = 0; 
        while(buffer[c] != '\n' && buffer[c] != '\000'){
            matrix[c][r] = buffer[c] - '0';
            c++;
        }
        r++;
    }
    int temp = 0, result[10], digit = 9;
    for (int c = 49; c > 39 ; c--){
        for ( int r = 0; r < 100; r++){
            temp += matrix[c][r];
        }
        result[digit] = temp % 10;
        temp = temp/10;
        digit--;
        
    }
    
    for (int i = 0; i < 10; i++) printf("%d", result[i]);
    fclose(file_ptr);
        
    return 0;
}