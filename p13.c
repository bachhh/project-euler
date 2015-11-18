#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *file_ptr;
    
    char buffer[1000];
    file_ptr = fopen("p13.txt", "r");
    if (file_ptr) {
        printf("ERROR! no file found!\n");
        return 1;
    }
    
    int matrix[50][100];
    int r = 0, c = 0;
    while ( fgets(buffer,1000, file_ptr) != NULL){
        c = 0;
        while(buffer[c] != '\n'){
            matrix[c][r] = atoi(buffer[c]);
        }
        c++;
    }
    
    fclose(file_ptr);
        
    return 0;
}