#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;

Node* create_node(int data){
    Node *temp = malloc(sizeof (Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node* insert(Node *node,int insert_data){
    if(node == NULL){
        return create_node(insert_data);
    }else{
        if(node->data<insert_data){
            node->right = insert(node->right,insert_data);
        }else{
            node->left = insert(node->left,insert_data);
        }
    }
}

Node* delete(Node *node,int value){
    if(node==NULL){
        return node;
    }
    if(node->data<value){
        node->right = delete(node->right,value);}
    else if(node->data>value){
        node->left = delete(node->left,value);}
    else{
        if(node->left==NULL){//if node has only right child
            Node *temp = node->right;
            free(node);
            return temp;
        }else if(node->right==NULL){//if node has only left child
            Node *temp = node->left;
            free(node);
            return temp;
        }
        Node *temp = node->right;//if node has both child
        while(temp->left!=NULL){
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = delete(node->right,temp->data);
    }
    return node;
}

void inorder(Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(Node* root){
    if(root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}



int main() {
    Node *root = NULL;
    root = insert(root,15);
    insert(root,2);
    insert(root,40);
    insert(root,6);
    insert(root,35);
    insert(root,7);
    insert(root,30);
    insert(root,8);
    insert(root,25);
    insert(root,10);
    insert(root,20);
    insert(root,18);
    delete(root,15);

    printf("\ninorder: ");
    inorder(root);
    printf("\npreorder: ");
    preorder(root);
    printf("\npostorder: ");
    postorder(root);

    return 0;
}
