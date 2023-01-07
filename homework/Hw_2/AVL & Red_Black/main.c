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

Node *LL(Node *theNode){
    Node *lnode = theNode->left;
    Node *l_r_subtree = lnode->right;

    lnode->right = theNode;
    theNode->left = l_r_subtree;

    theNode->height = max(height(theNode->left), height(theNode->right))+1;
    lnode->height = max(height(lnode->left), height(lnode->right))+1;

    return lnode;
}

Node *RR(Node *theNode){
    Node *rnode = theNode->right;
    Node *r_l_subtree = rnode->left;

    rnode->left = theNode;
    theNode->right = r_l_subtree;

    theNode->height = max(height(theNode->left), height(theNode->right))+1;
    rnode->height = max(height(rnode->left), height(rnode->right))+1;

    return rnode;
}

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

int i = 100050;

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
//------------------------------------------------------------------- RBTREE
enum nodeColor { RED , BLACK };

typedef struct rbnode{
    int data, color;
    struct rbnode *left, *right, *parent;
}RBnode;

typedef struct rbtree {
    RBnode *root;
    RBnode *nil;
}RBtree;

RBnode *createRBNode(int data) {
    RBnode *newNode = malloc(sizeof(RBnode)*10);
    newNode->data = data;
    newNode->color = RED;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}

RBtree *createRBtree() {
    RBtree *RBtree = malloc(sizeof (RBtree)*100000);
    RBnode *nil = malloc(sizeof(RBnode)*100000);
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

void left_rotate(RBtree *RBtree,RBnode *theNode) {
    if(theNode == NULL){ //add
        return;
    }
    RBnode *rnode = theNode->right;
    theNode->right = rnode->left;
    if(rnode->left != RBtree->nil) {
        rnode->left->parent = theNode;
    }
    rnode->parent = theNode->parent;
    if(theNode->parent == RBtree->nil) {
        RBtree->root = rnode;
    }
    else if(theNode == theNode->parent->left) {
        theNode->parent->left = rnode;
    }
    else {
        theNode->parent->right = rnode;
    }
    rnode->left = theNode;
    theNode->parent = rnode;
}

void right_rotate(RBtree *RBtree,RBnode *theNode) {
    if (theNode == NULL) {
        return;
    }
    RBnode *lnode = theNode->left;
    theNode->left = lnode->right;
    if(lnode->right != RBtree->nil) {
        lnode->right->parent = theNode;
    }
    lnode->parent = theNode->parent;
    if(theNode->parent == RBtree->nil) {
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
        if(theNode->parent == theNode->parent->parent->left) {

            RBnode *uncle = theNode->parent->parent->right;

            if(uncle->color == RED) { //case 1
                theNode->parent->color = BLACK;
                uncle->color = BLACK;
                theNode->parent->parent->color = RED;
                theNode = theNode->parent->parent;
            }
            else { //case2 or case3
                if(theNode == theNode->parent->right) {
                    theNode = theNode->parent;
                    left_rotate(RBtree, theNode);
                }
                //case3
                theNode->parent->color = BLACK;
                theNode->parent->parent->color = RED;
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
    RBnode* y = RBtree->nil;
    RBnode* temp = RBtree->root;
    i--;
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

    if(y == RBtree->nil) {
        RBtree->root = theNode;
    }
    else if(theNode->data < y->data)
        y->left = theNode;
    else
        y->right = theNode;

    theNode->right = RBtree->nil;
    theNode->left = RBtree->nil;

    insertion_fix(RBtree, theNode);
}

RBnode * left_most(RBnode * current,RBtree *t){
    while (current->left !=t->nil)
    {
        current = current->left;
    }
    return current;
}
RBnode * successor(RBtree *t, RBnode * current){
    if(current->right != t->nil){
        return left_most(current->right,t);
    }
    RBnode* new = current->parent;
    while (new!= t->nil && current == new->right)
    {
        current = new;
        new = new->parent;
    }
    return new;
}

RBnode *minimum(RBtree *t, RBnode *x)
{
    while (x->left != t->nil)
        x = x->left;
    return x;
}

void rb_delete_fixup(RBtree *t, RBnode *x)
{
    while (x != t->root && x->color == BLACK)
    {
        if (x == x->parent->left)
        {
            RBnode *w = x->parent->right;
            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                left_rotate(t, x->parent);
                w = x->parent->right;
            }

            if (w->left->color == BLACK && w->right->color == BLACK)
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->right->color == BLACK)
                {
                    w->left->color = BLACK;
                    w->color = RED;
                    right_rotate(t, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                left_rotate(t, x->parent);
                x = t->root;
            }
        }
        else
        {
            RBnode *w = x->parent->left;
            //if(w==t->NIL) return;
            //printf("-------------%d------------\n",w->right->color);

            if (w->color == RED)
            {
                w->color = BLACK;
                x->parent->color = RED;
                right_rotate(t, x->parent);
                w = x->parent->left;
            }

            if ((w->right->color == BLACK && w->left->color == BLACK))
            {
                w->color = RED;
                x = x->parent;
            }
            else
            {
                if (w->left->color == BLACK)
                {
                    w->right->color = BLACK;
                    w->color = RED;
                    left_rotate(t, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                right_rotate(t, x->parent);
                x = t->root;
            }
        }
    }
    x->color = BLACK;
}

void rb_delete(RBtree *t, RBnode *z)
{
    //tree_node *y = z;
    RBnode *y;
    RBnode *x;
    //enum COLOR y_orignal_color = y->color;



    if(z->left == t->nil || z->right==t->nil){
        y=z;
    }else{
        y = successor(t,z);
    }
    if( y->left!=t->nil){
        x= y ->left;
    }else{
        //printf("!!!!!\n");
        x= y ->right;
    }
    x->parent = y->parent;
    if(y->parent == t->nil)
    {
        t->root = x;
    }else if(y == y->parent->left){
        y->parent->left = x;
    }
    else{
        y->parent->right = x;
    }
    if(y!=z){
        z->data = y->data;
        //free(y);
        //z->element = y->element;
    }
    if(y->color ==BLACK){
        rb_delete_fixup(t,x);
    }
}

RBnode *search_RB(RBtree *RBtree, int data) {
    RBnode *temp = RBtree->root;
    i--;
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
    AVL *AVL_TREE = create_AVL();
    scanf("%s",cmd);
    if(strcmp(cmd,"AVL") == 0) {
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
    }else if(strcmp(cmd,"red_black") == 0){
        RBtree *RBtree = createRBtree();
        while (i) {
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
                rb_delete(RBtree, search_RB(RBtree, data));
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
