#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LIMIT 1000000

typedef struct stack{
    long int* array;
    long int top;
} Stack;

Stack* stack_init(){
    Stack* ptr = malloc(sizeof(Stack));
    ptr->array = (long int*) malloc(600*sizeof(long int));
    ptr->top = -1;
    return ptr;
}

void stack_add(Stack* stack, long int n){
    if (stack->top >= LIMIT-1) {
        printf("Out of bound stack add\n");
        exit(EXIT_FAILURE);
    }
    else{
        stack->top++;
        stack->array[stack->top] = n;
    }
}

long int stack_pop(Stack* stack){
    if (stack->top>-1){
        long int value = stack->array[stack->top];
        stack->top--;
        return value;
    }
    else {
        printf("Out of bound stack pop\n");
        exit(EXIT_FAILURE);
    }
        
}


long int collatz(long int n){
    return (n%2==0) ? n/2 : 3*n +1;
}


int find(int* array, Stack* stack, long int n){
    long int n_copy = n;
    
    // For every unknown number appear, solve their children
    // first, then their collatz number = collatz(children) + 1
    while (n > LIMIT-1 || array[n] == 0){
        stack_add(stack, n);
        n = collatz(n);
    }
    
    int x = 0; // Counter
    long int from_stack;
    
    // Solving collatz number for subsequence number in stack
    while(stack->top>-1){
        from_stack = stack_pop(stack);
        // Increment position counter for every pop from stack
        x++;
        
        // Write position for numbers < 1000000 
        if (from_stack <= LIMIT-1){
            array[from_stack] = x + array[n];
        }
        
    }
    return array[n_copy];
}


int main(){
    clock_t t = clock(); // Start clocking
    Stack* stack = stack_init();
    int* array = malloc(LIMIT*sizeof(int));

    memset( array, 0, sizeof(int));
    array[1] = 1;
    int largest = 0;
    long int number = 0;
    
    
    for (int i = 1; i < LIMIT; i++){
        if(array[i] == 0) array[i] = find(array, stack, i);
        if (largest < array[i]){
            largest = array[i];
            number = i;
        }
    }
    t = clock() - t;
    printf ("Run time: %f \n",((float) t)/CLOCKS_PER_SEC);
    printf("Largest: %ld length %d \n", number, largest); 
    
    return 0;
}
