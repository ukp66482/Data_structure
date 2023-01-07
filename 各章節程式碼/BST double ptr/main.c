#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

void insert(struct Node **node,int data){
    if(*node == NULL) {
        *node = malloc(sizeof(struct Node));
        (*node)->data = data;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }else{
        struct Node **now = node;
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        (temp)->data = data;
        (temp)->left = NULL;
        (temp)->right = NULL;
        while(*now!=NULL) {
            if((*now)->data < data) {
                now = &((*now)->right);
            } else {
                now = &((*now)->left);
            }
        }
        *now = temp;
    }
}

void inorder(struct Node *node){
    if(node!=NULL){
        inorder((node)->left);
        printf("%d",(node)->data);
        inorder((node)->right);
    }
}


int main(void){
    struct Node **root = malloc(sizeof (struct Node*));
    insert(root,3);
    insert(root,2);
    insert(root,5);
    insert(root,6);
    insert(root,1);
    insert(root,4);
    insert(root,7);
    inorder(*root);
    return 0;
}