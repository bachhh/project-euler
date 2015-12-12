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
    if (i < 20) {
        return strlen(names[i]);
    }
    else if ( i <= 99){
        return convert(names,i%10) + strlen(names[i/10+18]);
    }
    else if (i <= 999){
        int temp = strlen(names[i/100]) + strlen("hundred");
        if (i%100!=0) 
            temp = temp + strlen("and") + convert(names,i%100); 
        return temp;
    }
    else{
        return strlen("onethousand");
    }
}
int main(){
    // Sum from 1 -> 99
    int hundredsum=0;
    int i=1001;
    while(i-->0) 
        hundredsum += convert(names,i);
    printf("%d \n", hundredsum);
    
    return 0;
}