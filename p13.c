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
        while(c<50){
            matrix[c][r] = buffer[c] - '0';
            c++;
        }
        r++;
    }
    
    for (int r =0; r< 100; r++){
        for (int c = 0; c < 50; c++)
            printf("%d", matrix[c][r]);
        printf("\n");
    }
    
    int temp = 0, result[50];
    for (int digit = c = 49; c >= 0  ; c--){
        for ( int r = 0; r < 100; r++){
            temp += matrix[c][r];
        }
        result[c] = temp % 10;
        temp = temp/10;
    }
    
    printf("\ntemp =  %d", temp);
    for (int i = 0; i < 10; i++) printf("%d", result[i]);
    printf("\ntemp =  %d \n", temp);
    fclose(file_ptr);
        
    return 0;
}