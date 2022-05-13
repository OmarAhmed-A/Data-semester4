#include <stdlib.h>
#include <stdio.h>
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
int main()
{
    Node *root;
    Node *root2;

    root->data =100;
    root->left =root2;
    root->right=NULL;
    root2->data=190;
    root2->left =NULL;
    root2->right=NULL;
    printf("here %d",root->left->data);
    

    return 0;
    
}