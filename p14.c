#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100000000 // 100 millions limit

typedef struct node{
    long long int value;
    long long int position;
    struct node *next;
} Node;

int main(){
    
    
    Node* list = malloc(LIMIT * sizeof(Node));
    list[0].value = 1;
    if(!list[0].next)printf("YES\n");
    return 0;
}
