#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define inRange(n, from, to) (from <= n && n <= to ? 1 : 0)

// These types of problems have more trouble getting input.

int getInt(char* string, int* destination, int from){
    char temp[10];
    int end = 0;
    
    while( inRange(string[from+end] -'0',0 ,9) ){
        end++;
    }
    
    if (end>0){
        memcpy(temp, string+from, end);
        *destination = atoi(temp);
        return from + end;
    }
    else return -1;
}

int getIntLine(int** matrix, FILE* file){
    char buffer[1000];
    int r=0, c=0;
    int tempint=0;
    
    while(fgets(buffer, 1000, file)!= NULL){
        int position=0;
        
        while(position != -1){
            position = getInt(buffer, &tempint, position);
            matrix[c][r] = tempint;
            c++;
        }    
        r++;
    }  
}


int main(){
    FILE* file = fopen("p18.txt", "r");
    char buffer[1000];
    int matrix[100][100];
    getIntLine
    int result;
    
    return 0;
}