// C++ program to print postorder traversal
// from preorder and inorder traversals
#include <iostream>
using namespace std;

// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Prints postorder traversal from given
// inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);

    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root);

    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);

    // Print root
    cout << pre[0] << " ";
}

// Driver program to test above functions
int main()
{
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    printPostOrder(in, pre, n);
    return 0;
}
//////////////////////////////////////////////////
// C++ program to print Postorder
// traversal from given Inorder
// and Preorder traversals.
#include <iostream>
using namespace std;

int preIndex = 0;

int search(int arr[], int startIn,int endIn, int data)
{
    int i = 0;
    for (i = startIn; i < endIn; i++)
    {
        if (arr[i] == data)
        {
            return i;
        }
    }
    return i;
}
void printPost(int arr[], int pre[],int inStrt, int inEnd)
{
    if (inStrt > inEnd)
    {
        return;
    }

    // Find index of next item in preorder
    // traversal in inorder.
    int inIndex = search(arr, inStrt, inEnd,pre[preIndex++]);

    // traverse left tree
    printPost(arr, pre, inStrt, inIndex - 1);

    // traverse right tree
    printPost(arr, pre, inIndex + 1, inEnd);

    // print root node at the end of traversal
    cout << arr[inIndex] << " ";
}

// Driver code
int main()
{
    int arr[] = {4, 2, 5, 1, 3, 6};
    int pre[] = {1, 2, 4, 5, 3, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    printPost(arr, pre, 0, len - 1);
}

// This code is contributed by SHUBHAMSINGH10
