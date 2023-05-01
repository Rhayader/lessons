#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {                           //Definition of the tree node
    int value;
    struct treenode *left;
    struct treenode *right;
} treenode;

int exception = 0;


treenode *createnode(int value);                    //Create a single tree node

int main (void)
{
    //Populate sample tree
    //This will be our test tree
    /*
           root
         /     \
    node1       node2
               /     \
         node3        node4
                     /     \
                node5       node6
                     \
                      node7
                     /     \
                node8       node9
    */
    treenode *root = createnode(101);
    root->left = createnode(102);
    root->right = createnode(103);
    root->right->left = createnode(104);
    root->right->right = createnode(105);
    root->right->right->left = createnode(106);
    root->right->right->right = createnode(107);
    root->right->right->left->right = createnode(108);
    root->right->right->left->right->left = createnode(109);
    root->right->right->left->right->right = createnode(110);

    if (!exception){
      //Our code goes here
    } else {                                 //Catch exception, the tapor way
        printf("We done goofed up - createnode() failed to create one or more tree nodes.\n");
        return exception;
    }

    //Free the memory in reverse order - child to parent
    free(root->right->right->left->right->right);
    free(root->right->right->left->right->left);
    free(root->right->right->left->right);
    free(root->right->right->right);
    free(root->right->right->left);
    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);

    return 0;
}

treenode *createnode(int value)                     //Function to create a single tree node
{
    treenode* result =(treenode*) malloc(sizeof(treenode));
    if (result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    } else {
        printf("Failure to create tree node, malloc() returned NULL pointer!\n");
        exception = 1;                              //Throw exception, the tapor way
    }

    return result;
}
