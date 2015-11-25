#include <stdio.h>
#include <stdlib.h>

#define LIMIT 100000000 // 100 millions limit, also stack limit

typedef struct node{
    long int value;
    long int position;
    struct node *next;
} Node;

typedef struct Stack{
    Node** stackarray;
    long int top;
} Stack;

Stack* stack_init(){
    Stack* stack = malloc(sizeof(Stack)); 
    stack->stackarray = (Node**) malloc(LIMIT*sizeof(Node*));
    stack->top = 0;
    return stack;
}

Node* stack_pop(Stack* stack){
    if (stack->top < 0) return NULL;
    Node* value = stack->stackarray[stack->top];
    stack->top--;
    return value;
}

int stack_add(Stack* stack, Node* node){
    if(stack->top >= LIMIT-1) return 1;
    stack->stackarray[stack->top+1] = node;
    stack->top++;
    return 0;
}

/* Approach "bottom up" to generate a tree of sequences */
void create(Stack* stack, Node** array, Node* n){
    long long int even = n->value * 2;
    long long int odd = ((n->value-1)%3==0) ? (n->value -1 )/3 : 0;
    if(even<LIMIT && !array[even]){
        array[even] = (Node*) malloc(sizeof(Node*));
        array[even]->value = even, n->next = array[even];
        array[even]->position = n->position + 1;
        stack_add(stack, array[even]);
    }
    if(odd>1 && odd%2 != 0 && !array[odd]){
        array[odd] = (Node*) malloc(sizeof(Node*));
        array[odd]->value = odd, n->next = array[odd];
        array[odd]->position = n->position + 1;
        stack_add(stack, array[odd]);
    }
    
}


int main(){
    Stack* mainstack = stack_init();
    Node** list = malloc(LIMIT * sizeof(Node*));
    for (int i=0; i<LIMIT; i++) list[i] = NULL;
    
    printf("line ok\n");
    list[1] = (Node*) malloc(sizeof(Node));
    list[1]->value = 1, list[1]->position = 1;
    stack_add(mainstack, list[1]);
    
    printf("line ok\n");
    long int test;
    while(mainstack->top){
        Node* top = stack_pop(mainstack);
        create(mainstack, list, top);
    }
    
    printf("line ok\n");
    
    long int max_position = 0, max_value = 0;
    
    printf("Max value = %ld \n", max_value);
    return 0;
}
