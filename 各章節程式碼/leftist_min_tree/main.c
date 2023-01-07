#include <stdio.h>
#include <stdlib.h>

struct leftist_node {
    int key;
    int s;
    struct leftist_node *left;
    struct leftist_node *right;
};

struct leftist_node *leftist_merge(struct leftist_node *a, struct leftist_node *b) {
    if (a == NULL) {//if a is empty, return b
        return b;
    }
    if (b == NULL) {//if b is empty, return a
        return a;
    }
    if (a->key > b->key) {//if a is bigger than b, swap them
        struct leftist_node *tmp = a;
        a = b;
        b = tmp;
        free(tmp);
    }
    a->right = leftist_merge(a->right, b);//merge the right subtree of a with b
    if (a->left == NULL || a->left->s < a->right->s) {//if the left subtree of a is empty or smaller than the right subtree of a, swap them
        struct leftist_node *tmp = a->left;
        a->left = a->right;
        a->right = tmp;
        free(tmp);
    }
    a->s = a->right == NULL ? 0 : a->right->s + 1;//update the shortest of a
    return a;
}

struct leftist_node *leftist_insert(struct leftist_node *root, int key) {
    struct leftist_node *node = malloc(sizeof(struct leftist_node));
    node->key = key;
    node->s = 0;
    node->left = NULL;
    node->right = NULL;
    return leftist_merge(root, node);
}

struct leftist_node *leftist_delete(struct leftist_node *root) {
    struct leftist_node *left = root->left;
    struct leftist_node *right = root->right;
    free(root);
    return leftist_merge(left, right);
}

void leftist_print(struct leftist_node *root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->key);
    leftist_print(root->left);
    leftist_print(root->right);
}

int main() {
    struct leftist_node *root = NULL;
    root = leftist_insert(root, 1);
    root = leftist_insert(root, 2);
    root = leftist_insert(root, 3);
    root = leftist_insert(root, 4);
    root = leftist_insert(root, 5);
    root = leftist_insert(root, 6);
    root = leftist_insert(root, 7);
    root = leftist_insert(root, 8);
    root = leftist_insert(root, 9);
    root = leftist_insert(root, 10);
    root = leftist_insert(root, 11);
    root = leftist_insert(root, 12);
    root = leftist_insert(root, 13);
    root = leftist_insert(root, 14);
    root = leftist_insert(root, 15);
    root = leftist_insert(root, 16);
    root = leftist_insert(root, 17);
    root = leftist_insert(root, 18);
    root = leftist_insert(root, 19);
    root = leftist_insert(root, 20);
    root = leftist_insert(root, 21);
    root = leftist_insert(root, 22);
    root = leftist_insert(root, 23);
    root = leftist_insert(root, 24);
    root = leftist_insert(root, 25);
    root = leftist_insert(root, 26);
    root = leftist_insert(root, 27);
    root = leftist_insert(root, 28);
    root = leftist_insert(root, 29);
    root = leftist_insert(root, 30);
    root = leftist_insert(root, 31);
    root = leftist_insert(root, 32);
    root = leftist_insert(root, 33);
    root = leftist_insert(root, 34);
    root = leftist_insert(root, 35);
    root = leftist_insert(root, 36);
    root = leftist_insert(root, 37);
    root = leftist_insert(root, 38);
    root = leftist_insert(root, 39);
    root = leftist_insert(root, 40);
    root = leftist_insert(root, 41);
    root = leftist_insert(root, 42);
    root = leftist_insert(root, 43);
    root = leftist_insert(root, 44);
    root = leftist_insert(root, 45);
    root = leftist_insert(root, 46);
    root = leftist_insert(root, 47);
    root = leftist_insert(root, 48);
    root = leftist_insert(root, 49);

    leftist_print(root);

    return 0;
}
