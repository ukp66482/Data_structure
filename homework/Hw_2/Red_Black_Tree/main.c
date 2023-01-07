#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum nodeColor { RED , BLACK };

typedef struct rbnode{
  int data, color;
  struct rbnode *left, *right, *parent;
}RBnode;

typedef struct rbtree{
    RBnode *root;
    RBnode *nil;
}RBtree;

RBnode *createRBNode(int data) {
  RBnode *newNode = malloc(sizeof(RBnode));
  newNode->data = data;
  newNode->color = RED;
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->parent = NULL;
  return newNode;
}

RBtree *createRBtree() {
  RBtree *RBtree = malloc(100000);
  RBnode *nil = malloc(sizeof(RBnode));
  nil->color = BLACK;
  nil->left = NULL;
  nil->right = NULL;
  nil->parent = NULL;
  nil->data = 0;
  RBtree->nil = nil;
  RBtree->root = RBtree->nil;
  return RBtree;
}

void getcolor(RBnode *node) {
    if(node == NULL) {
        return;
    }
    if (node->color == RED) {
        printf("red\n");
        return;
    } else {
        printf("black\n");
        return;
    }
}

void left_rotate(RBtree *RBtree,RBnode *theNode) { //conquer
    RBnode *rnode = theNode->right;
    theNode->right = rnode->left;
    if(rnode->left != RBtree->nil) {
        rnode->left->parent = theNode;
    }
    rnode->parent = theNode->parent;
    if(theNode->parent == RBtree->nil) { //x is root
        RBtree->root = rnode;
    }
    else if(theNode == theNode->parent->left) { //???
        theNode->parent->left = rnode;
    }
    else { //x is right child
        theNode->parent->right = rnode;
    }
    rnode->left = theNode;
    theNode->parent = rnode;
}

void right_rotate(RBtree *RBtree,RBnode *theNode) {
    RBnode *lnode = theNode->left;
    theNode->left = lnode->right;
    if(lnode->right != RBtree->nil) {
        lnode->right->parent = theNode;
    }
    lnode->parent = theNode->parent;
    if(theNode->parent == RBtree->nil) { //???
        RBtree->root = lnode;
    }
    else if(theNode == theNode->parent->right) {
        theNode->parent->right = lnode;
    }
    else { //x is right child
        theNode->parent->left = lnode;
    }
    lnode->right = theNode;
    theNode->parent = lnode;
}

void insertion_fix(RBtree *RBtree, RBnode *theNode) {
    while(theNode->parent->color == RED) {
        if(theNode->parent == theNode->parent->parent->left) { //z.parent is the left child

            RBnode *uncle = theNode->parent->parent->right; //uncle of z

            if(uncle->color == RED) { //case 1
                theNode->parent->color = BLACK;
                uncle->color = BLACK;
                theNode->parent->parent->color = RED;
                theNode = theNode->parent->parent;
            }
            else { //case2 or case3
                if(theNode == theNode->parent->right) { //case2
                    theNode = theNode->parent; //marked z.parent as new z
                    left_rotate(RBtree, theNode);
                }
                //case3
                theNode->parent->color = BLACK; //made parent black
                theNode->parent->parent->color = RED; //made parent red
                right_rotate(RBtree, theNode->parent->parent);
            }
        }
        else {
            RBnode *uncle = theNode->parent->parent->left;

            if(uncle->color == RED) {
                theNode->parent->color = BLACK;
                uncle->color = BLACK;
                theNode->parent->parent->color = RED;
                theNode = theNode->parent->parent;
            }
            else {
                if(theNode == theNode->parent->left) {
                    theNode = theNode->parent;
                    right_rotate(RBtree, theNode);
                }
                theNode->parent->color = BLACK;
                theNode->parent->parent->color = RED;
                left_rotate(RBtree, theNode->parent->parent);
            }
        }
    }
    RBtree->root->color = BLACK;
}

void insert_RB(RBtree *RBtree, RBnode *theNode) {
    RBnode* y = RBtree->nil; //variable for the parent of the added node
    RBnode* temp = RBtree->root;

    while(temp != RBtree->nil) {
        y = temp;
        if(theNode->data < temp->data)
            temp = temp->left;
        else if(theNode->data > temp->data)
            temp = temp->right;
        else{
            if(temp->data == theNode->data){
                return;
            }
        }
    }
    theNode->parent = y;

    if(y == RBtree->nil) { //newly added node is root
        RBtree->root = theNode;
    }
    else if(theNode->data < y->data) //data of child is less than its parent, left child
        y->left = theNode;
    else
        y->right = theNode;

    theNode->right = RBtree->nil;
    theNode->left = RBtree->nil;

    insertion_fix(RBtree, theNode);
}

void transplant_rb(RBtree *RBtree, RBnode *u, RBnode *v) {
    if(u->parent == RBtree->nil)
        RBtree->root = v;
    else if(u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

RBnode *minimum(RBtree *RBtree, RBnode *thenode) {
    while(thenode->left != RBtree->nil)
        thenode = thenode->left;
    return thenode;
}

void deletion_fix(RBtree *RBtree, RBnode *theNode) {
    while(theNode != RBtree->root && theNode->color == BLACK) {
        if(theNode == theNode->parent->left) {
            RBnode *rsibling = theNode->parent->right;
            if(rsibling->color == RED) {
                rsibling->color = BLACK;
                theNode->parent->color = RED;
                left_rotate(RBtree, theNode->parent);
                rsibling = theNode->parent->right;
            }
            if(rsibling->left->color == BLACK && rsibling->right->color == BLACK) {
                rsibling->color = RED;
                theNode = theNode->parent;
            }
            else {
                if(rsibling->right->color == BLACK) {
                    rsibling->left->color = BLACK;
                    rsibling->color = RED;
                    right_rotate(RBtree, rsibling);
                    rsibling = theNode->parent->right;
                }
                rsibling->color = theNode->parent->color;
                theNode->parent->color = BLACK;
                rsibling->right->color = BLACK;
                left_rotate(RBtree, theNode->parent);
                theNode = RBtree->root;
            }
        }
        else {
            RBnode *lsibling = theNode->parent->left;
            if(lsibling->color == RED) {
                lsibling->color = BLACK;
                theNode->parent->color = RED;
                right_rotate(RBtree, theNode->parent);
                lsibling = theNode->parent->left;
            }
            if(lsibling->right->color == BLACK && lsibling->left->color == BLACK) { //right left
                lsibling->color = RED;
                theNode = theNode->parent;
            }
            else {
                if(lsibling->left->color == BLACK) {
                    lsibling->right->color = BLACK;
                    lsibling->color = RED;
                    left_rotate(RBtree, lsibling);
                    lsibling = theNode->parent->left;
                }
                lsibling->color = theNode->parent->color;
                theNode->parent->color = BLACK;
                lsibling->left->color = BLACK;
                right_rotate(RBtree, theNode->parent);
                theNode = RBtree->root;
            }
        }
    }
    theNode->color = BLACK;
}

void delete_RB(RBtree *RBtree, RBnode *theNode) {
    if(theNode == NULL){
        return;
    }
    printf("%d\n", theNode->data);
    RBnode *y = theNode;
    RBnode *x;
    enum nodeColor y_orignal_color = y->color;
    if(theNode->left == RBtree->nil) {
        x = theNode->right;
        transplant_rb(RBtree, theNode, theNode->right);
    }
    else if(theNode->right == RBtree->nil) {
        x = theNode->left;
        transplant_rb(RBtree, theNode, theNode->left);
    }
    else {
        y = minimum(RBtree, theNode->right); //find the right_subtree minimum
        y_orignal_color = y->color; //y is minimum of right subtree
        x = y->left;
        if(y->parent == theNode) {
            x->parent = y;
        }
        else {
            transplant_rb(RBtree, y, y->right);
            y->right = theNode->right;
            y->right->parent = y;
        }
        transplant_rb(RBtree, theNode, y);
        y->left = theNode->left;
        y->left->parent = y;
        y->color = theNode->color; //end
    }
    if(y_orignal_color == BLACK)
        deletion_fix(RBtree, x);
}

RBnode *search_RB(RBtree *RBtree, int data) {
    RBnode *temp = RBtree->root;
    if(temp == RBtree->nil){
        return NULL;
    }
    while (temp != RBtree->nil) {
        if (data == temp->data) {
            return temp;
        }
        temp = (data < temp->data) ? temp->left : temp->right;
    }
    return NULL;
}

void inorder_RB(RBtree *t, RBnode *n) {
    if (n != t->nil) {
        inorder_RB(t, n->left);
        printf("%d ", n->data);
        inorder_RB(t, n->right);
    }
}

void preorder_RB(RBtree *t, RBnode *n) {
    if (n != t->nil) {
        printf("%d ", n->data);
        preorder_RB(t, n->left);
        preorder_RB(t, n->right);
    }
}

void postorder_RB(RBtree *t, RBnode *n) {
    if (n != t->nil) {
        postorder_RB(t, n->left);
        postorder_RB(t, n->right);
        printf("%d ", n->data);
    }
}

int main(void){
    char cmd[10];
    RBtree *RBtree = createRBtree();
    scanf("%s",cmd);
    if(strcmp(cmd,"AVL") == 0) { //AVL TREE

    }else if(strcmp(cmd,"red_black") == 0){
        while (1) {
            memset(cmd,'\0',10);
            scanf("%s", cmd);
            if (strcmp(cmd, "insert") == 0) {
                int data;
                scanf("%d", &data);
                insert_RB(RBtree, createRBNode(data));
            } else if (strcmp(cmd, "search") == 0) {
                int data;
                RBnode *temp;
                scanf("%d", &data);
                temp = search_RB(RBtree, data);
                if (temp){
                    getcolor(temp);
                }else{
                    printf("Not found\n");
                }
            } else if (strcmp(cmd, "delete") == 0) {
                int data;
                scanf("%d", &data);
                search_RB(RBtree, data);
                delete_RB(RBtree, search_RB(RBtree, data));
            } else if (strcmp(cmd, "inorder") == 0) {
                inorder_RB(RBtree,RBtree->root);
                printf("\n");
            } else if (strcmp(cmd, "preorder") == 0) {
                preorder_RB(RBtree,RBtree->root);
                printf("\n");
            } else if (strcmp(cmd, "postorder") == 0) {
                postorder_RB(RBtree,RBtree->root);
                printf("\n");
            } else if (strcmp(cmd, "quit") == 0) {
                exit(EXIT_SUCCESS);
            }
        }
    }
}