#include <stdio.h>
#include <string.h>

char* names[28] = {
    "",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "fifteen",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "thirty",
    "forty",
    "fifty",
    "sixty",
    "seventy",
    "eighty",
    "ninety",
  };
  
int convert(char** names,int i){
    if (i < 20) return strlen(names[i]);
    else if ( i <= 99) return convert(names,i%10) + strlen(names[i/10+18]);
    
}

int main(){
    
    return 0;
}