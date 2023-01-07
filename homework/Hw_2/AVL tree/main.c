#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
    int height;
}Node;

typedef struct AVL{
    Node *root;
}AVL;

typedef struct redblack{
    Node *root;
}redblack;

int height(Node *Node){
    if(!Node)
        return 0;
    else
        return Node->height;
}

int balance_factor(Node *theNode){
    if(!theNode)
        return 0;
    else
        return (height(theNode->left)- height(theNode->right));
}

int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}

//create node
Node *create_node(int data){
    Node *newNode = malloc(sizeof (Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVL *create_AVL(){
    AVL *AVL_tree = malloc(sizeof (AVL));
    AVL_tree->root = NULL;
    return AVL_tree;
}

//all kinds of rotation RR,LL
Node *LL(Node *theNode){ //right rotate
    Node *lnode = theNode->left;
    Node *l_r_subtree = lnode->right;

    lnode->right = theNode;
    theNode->left = l_r_subtree;

    theNode->height = max(height(theNode->left), height(theNode->right))+1;
    lnode->height = max(height(lnode->left), height(lnode->right))+1;

    return lnode;
}

Node *RR(Node *theNode){  //left rotate
    Node *rnode = theNode->right;
    Node *r_l_subtree = rnode->left;

    rnode->left = theNode;
    theNode->right = r_l_subtree;

    theNode->height = max(height(theNode->left), height(theNode->right))+1;
    rnode->height = max(height(rnode->left), height(rnode->right))+1;

    return rnode;
}

//API
Node *insert(Node *theNode,int data){
    if(!theNode)
        return (create_node(data));
    else{
        if(theNode->data>data){
            theNode->left = insert(theNode->left,data);
        }else if(theNode->data<data){
            theNode->right = insert(theNode->right,data);
        }else{
            return theNode; //data already exist
        }
    }
    theNode->height = 1 + max(height(theNode->left), height(theNode->right));

    int bf = balance_factor(theNode);
    if(bf>1){
        if(data<theNode->left->data){
            return LL(theNode);
        }else if(data>theNode->left->data){
            theNode->left = RR(theNode->left);
            return LL(theNode);
        }
    }else if(bf<-1){
        if(data>theNode->right->data){
            return RR(theNode);
        }else if(data<theNode->right->data){
            theNode->right = LL(theNode->right);
            return RR(theNode);
        }
    }else if(bf == 1 || bf == -1 || bf == 0){
        return theNode;
    }
}

void search(Node *theNode,int data){
    if(!theNode)
        printf("Not found\n");
    else {
        while (theNode){
            if(theNode->data == data){
                printf("%d\n", balance_factor(theNode));
                return;
            }else if(theNode->data>data){
                theNode = theNode->left;
            }else if(theNode->data<data){
                theNode = theNode->right;
            }
        }
        printf("Not found\n");
    }
}

Node *left_subtree_max(Node *theNode){
    Node *temp = theNode->left;
    while(temp->right){
        temp = temp->right;
    }
    return temp;
}

Node *delete(Node *theNode,int data){
    if(!theNode){
        return theNode; //root is empty or data isn't exist
    }
    if(theNode->data>data){
        theNode->left = delete(theNode->left,data);
    }else if(theNode->data<data){
        theNode->right = delete(theNode->right,data);
    }else{
        if(!(theNode->left)||!(theNode->right)){
            Node *temp = NULL;
            if(theNode->left)
                temp = theNode->left;
            else if(theNode->right)
                temp = theNode->right;
            if(!temp){
                temp = theNode;
                theNode = NULL;
            }else{
                *theNode = *temp;
                free(temp);
            }
        }else{
            Node *temp = left_subtree_max(theNode);
            theNode->data = temp->data;
            theNode->left = delete(theNode->left,temp->data);
        }
    }
    if(!theNode)
        return theNode;
    theNode->height = 1 + max(height(theNode->left), height(theNode->right));

    int bf = balance_factor(theNode);
    if(bf>1){
        if(balance_factor(theNode->left) >= 0){
            return LL(theNode);
        }else if(balance_factor(theNode->left) < 0){
            theNode->left = RR(theNode->left);
            return LL(theNode);
        }
    }else if(bf<-1){
        if(balance_factor(theNode->right) <= 0){
            return RR(theNode);
        }else if(balance_factor(theNode->right) > 0){
            theNode->right = LL(theNode->right);
            return RR(theNode);
        }
    }else if(bf == 1 || bf == -1 || bf == 0){
        return theNode;
    }
}


void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root) {
    if (root) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}


int main(void){
    char cmd[10];
    AVL *AVL_TREE = create_AVL();
    scanf("%s",cmd);
    if(strcmp(cmd,"AVL") == 0) { //type AVL to start
        while (1) {
            memset(cmd,'\0',10);
            scanf("%s", cmd);
            if (strcmp(cmd, "insert") == 0) {
                int data;
                scanf("%d", &data);
                AVL_TREE->root = insert(AVL_TREE->root, data);
            } else if (strcmp(cmd, "search") == 0) {
                int data;
                scanf("%d", &data);
                search(AVL_TREE->root, data);
            } else if (strcmp(cmd, "delete") == 0) {
                int data;
                scanf("%d", &data);
                AVL_TREE->root = delete(AVL_TREE->root, data);
            } else if (strcmp(cmd, "inorder") == 0) {
                inorder(AVL_TREE->root);
            } else if (strcmp(cmd, "preorder") == 0) {
                preorder(AVL_TREE->root);
            } else if (strcmp(cmd, "postorder") == 0) {
                postorder(AVL_TREE->root);
            } else if (strcmp(cmd, "quit") == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }
}