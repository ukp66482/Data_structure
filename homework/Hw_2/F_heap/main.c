#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef struct node{
    struct node *parent;
    struct node *child;
    struct node *left;
    struct node *right;
    //struct node* next;
    int key;
    int value;
    int degree;
    bool mark;
    bool found;
}Node;

Node *mini = NULL;
//Node *minimum = NULL;

int no_of_nodes = 0;

void insertion(int key, int value){
    Node *new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->degree = 0;
    new_node->mark = false;
    new_node->found = false;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if (mini){
        (mini->left)->right = new_node;
        new_node->right = mini;
        new_node->left = mini->left;
        mini->left = new_node;
        if (new_node->key < mini->key)
            mini = new_node;
    }
    else{
        mini = new_node;
    }
    no_of_nodes++;
}

void Fibonnaci_link(Node *ptr2, Node *ptr1){
    (ptr2->left)->right = ptr2->right;
    (ptr2->right)->left = ptr2->left;
    if(ptr1->right == ptr1)
        mini = ptr1;
    ptr2->left = ptr2;
    ptr2->right = ptr2;
    ptr2->parent = ptr1;
    if (!ptr1->child)
        ptr1->child = ptr2;
    ptr2->right = ptr1->child;
    ptr2->left = (ptr1->child)->left;
    ((ptr1->child)->left)->right = ptr2;
    (ptr1->child)->left = ptr2;
    if (ptr2->key < (ptr1->child)->key)
        ptr1->child = ptr2;
    ptr1->degree++;
}

void Consolidate(){
    int temp1 = 0;
    double temp2 = (double)(log(no_of_nodes)) / (log(2));

    int temp3 = (int)temp2;
    Node *arr[temp3 + 1];
    for (int i = 0; i <= temp3; i++)
        arr[i] = NULL;
    Node *ptr1 = mini;
    Node *ptr2;
    Node *ptr3;
    Node *ptr4 = ptr1;
    do
    {
        ptr4 = ptr4->right;
        temp1 = ptr1->degree;
        while (arr[temp1] && temp1 < temp3)
        {
            ptr2 = arr[temp1];
            if (ptr1->key > ptr2->key)
            {
                ptr3 = ptr1;
                ptr1 = ptr2;
                ptr2 = ptr3;
            }
            if (ptr2 == mini)
                mini = ptr1;
            Fibonnaci_link(ptr2, ptr1);
            if (ptr1->right == ptr1)
                mini = ptr1;
            arr[temp1] = NULL;
            temp1++;
        }
        arr[temp1] = ptr1;
        ptr1 = ptr1->right;
    } while (ptr1 != mini);
    mini = NULL;
    for (int j = 0; j <= temp3; j++)
    {
        if (arr[j])
        {
            arr[j]->left = arr[j];
            arr[j]->right = arr[j];
            if (mini)
            {
                (mini->left)->right = arr[j];
                arr[j]->right = mini;
                arr[j]->left = mini->left;
                mini->left = arr[j];
                if (arr[j]->key < mini->key)
                    mini = arr[j];
            }
            else
            {
                mini = arr[j];
            }
            if (!mini)
                mini = arr[j];
            else if (arr[j]->key < mini->key)
                mini = arr[j];
        }
    }
}

void Extract_min(){

    if (mini)
    {
        Node *temp = mini;
        Node *pntr;
        pntr = temp;
        Node *x = NULL;
        if (temp->child)
        {

            x = temp->child;
            do
            {
                pntr = x->right;
                (mini->left)->right = x;
                x->right = mini;
                x->left = mini->left;
                mini->left = x;
                if (x->key < mini->key)
                    mini = x;
                x->parent = NULL;
                x = pntr;
            } while (pntr != temp->child);
        }
        (temp->left)->right = temp->right;
        (temp->right)->left = temp->left;
        mini = temp->right;
        if (temp == temp->right && !temp->child)
            mini = NULL;
        else
        {
            mini = temp->right;
            Consolidate();
        }
        no_of_nodes--;
    }
}

void Cut(Node *found, Node *temp){
    if (found == found->right)
        temp->child = NULL;

    (found->left)->right = found->right;
    (found->right)->left = found->left;
    if (found == temp->child)
        temp->child = found->right;

    temp->degree = temp->degree - 1;
    found->right = found;
    found->left = found;
    (mini->left)->right = found;
    found->right = mini;
    found->left = mini->left;
    mini->left = found;
    found->parent = NULL;
    found->mark = false;
}

void Cascase_cut(Node *temp){
    Node *ptr5 = temp->parent;
    if (ptr5)
    {
        if (!temp->mark)
        {
            temp->mark = true;
        }
        else
        {
            Cut(temp, ptr5);
            Cascase_cut(ptr5);
        }
    }
}

void Decrease_key(Node *found, int key){

    if (!mini){} //empty

    if (!found){} //not found

    found->key = key;

    Node *temp = found->parent;
    if (temp && found->key < temp->key)
    {
        Cut(found, temp);
        Cascase_cut(temp);
    }
    if (found->key < mini->key)
        mini = found;
}

void Find(Node *mini, int old_key, int value, int key){
    Node *found = NULL;
    Node *temp5 = mini;
    temp5->found = true;
    Node *found_ptr = NULL;
    if (temp5->key == old_key && temp5->value == value){
        found_ptr = temp5;
        temp5->found = false;
        found = found_ptr;
        Decrease_key(found, key);
    }
    if (!found_ptr)
    {
        if (temp5->child)
            Find(temp5->child, old_key, value, key);
        if ((temp5->right)->found != true)
            Find(temp5->right, old_key, value, key);
    }
    temp5->found = false;
    found = found_ptr;
}

void Deletion(int key, int value){
    if (mini){
        Find(mini, key, value, -1000000000);
        Extract_min();
    }
}
/*
void insertionll(int key,int data){
    if(!minimum){
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = data;
        newNode->next = NULL;
        minimum = newNode;
    }else{
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->key = key;
        newNode->value = data;
        if(key<minimum->key){
            newNode->next = minimum;
            minimum = newNode;
            return;
        }
        Node *p = minimum;
        Node *prev = minimum;
        for(; p != NULL && p->key <= key; prev = p,p = p->next);
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

void printll(){
    for(Node *p = minimum;p != NULL;p = p->next){
        printf("%d %d\n",p->key,p->value);
    }
}

void Extract_minll(){
    if(minimum==NULL){
        return;
    }else{
        printf("(%d)%d\n",minimum->key,minimum->value);
        Node *temp = minimum;
        minimum = minimum->next;
        free(temp);
    }
}

void Deletionll(int key,int data){
        Node *p = minimum;
        Node *prev = minimum;
        if(minimum->key==key&&minimum->value==data){
            Node *temp = minimum;
            minimum = minimum->next;
            free(temp);
            return;
        }
        for(;p!=NULL && !(p->key == key&& p->value == data); prev = p,p = p->next);
        prev->next = p->next;
        return;
}

void Decrease_keyll(struct node* found, int key,int data,int minus){
    Deletion(key,data);
    insertion(key-minus,data);
}
*/

int main(void){
    char cmd[9];
    while(1){
        scanf("%s",cmd);
        if(strcmp(cmd,"insert") == 0){
            int key,data;
            scanf("%d %d",&key,&data);
            insertion(key,data);
        }else if(strcmp(cmd,"extract") == 0){
            if(mini) {
                printf("(%d)%d\n", mini->key, mini->value);
                Extract_min();
            }
        }else if(strcmp(cmd,"delete") == 0){
            int key,data;
            scanf("%d %d",&key,&data);
                Deletion(key,data);
        }else if(strcmp(cmd,"decrease") == 0){
            int key,data,minus;
            scanf("%d %d %d",&key,&data,&minus);
            Find(mini,key,data,key-minus);
        }else if(strcmp(cmd,"quit") == 0){
            exit(EXIT_FAILURE);
        }/*else if(strcmp(cmd,"insertll") == 0){
            int key,data;
            scanf("%d %d",&key,&data);
            insertionll(key,data);
        }else if(strcmp(cmd,"extractll") == 0){
            Extract_minll();
        }else if(strcmp(cmd,"decreasell") == 0){
            int key,data,minus;
            scanf("%d %d %d",&key,&data,&minus);
            Decrease_keyll(minimum,key,data,minus);
        }else if(strcmp(cmd,"deletell") == 0){
            int key,data;
            scanf("%d %d",&key,&data);
            Deletionll(key,data);
        }*/
        memset(cmd,'\0',9);
    }
}