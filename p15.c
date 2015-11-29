#include <stdio.h>
#include <stdlib.h>
#include <time.h>
scp
typedef struct node{
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* newLeft(){
    Node* ptr = malloc(sizeof(Node));
    ptr->value = 1;
    ptr->left = ptr->right = NULL;
    return ptr;
}

Node* newRight(){
    Node* ptr = malloc(sizeof(Node));
    ptr->value = 0;
    ptr->left = ptr->right = NULL;
    return ptr;
}

int permutation( Node* node, int leftcounter, int rightcounter){
    if(node == NULL) return 0;
    if(leftcounter)
        node->left = newLeft();
    if(rightcounter)
        node->right = newRight();
    int left_leaves = permutation(node->left, leftcounter-1, rightcounter);
    int right_leaves = permutation(node->right, leftcounter, rightcounter-1);
    if (node->left == NULL && node->right == NULL) return 1;
    else return left_leaves + right_leaves;
}
int main(){
    clock_t t = clock();
    Node* root = malloc(sizeof(Node));
    root->left = newLeft();
    root->right = newRight();
    int degree = 20;
    int n = permutation(root, degree, degree);
    t = clock() - t;
    printf("Runtime: %f\n", (float) t/CLOCKS_PER_SEC);
    printf("result: %d \n", n);
    return 0;
}
 