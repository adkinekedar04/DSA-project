#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"kdTree.h"
#include"stack.h"
#include"helper.h"
#define N 1000

extern int count;
extern int k;
extern int arr[N];
extern int target[N];
// declare k-Dimension


// Creating new node
node *create(int arr[])
{
    struct node *temp = (node *)calloc(1, sizeof(struct node));
    temp->point = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++){
        temp->point[i] = arr[i];
    }
    temp->left = temp->right = NULL;
    return temp;
}

// Helper function to insert a node in the KD Tree
node *insert(node *root, int point[], int depth)
{
    // if tree is empty
    if (root == NULL)
        return create(point);

    // Current dimension
    int cd = depth % (k-1);

    // comparing points with root wrt dimension before insertion
    if (point[cd] < (root->point[cd]))
        root->left = insert(root->left, point, depth + 1);
    else
        root->right = insert(root->right, point, depth + 1);

    return root;
}

//  Main function to insert a node
node *insert_main(node *root, int point[])
{
    return insert(root, point, 0);
}

// checking if two arrays are equal or not 
bool equal(int arr1[], int arr2[])
{
    // Checking if all elements of array 1 = array 2
    for (int i = 0; i < k-1; i++)
        if (arr1[i] != arr2[i])
            return false;

    return true;
}

// Helper function to search a node in the KD Tree
bool search(node *root, int point[], int depth)
{

    if (root == NULL)
        return false;
    if (equal(root->point, point))
        return true;

    // current dimenson
    int cd = depth % (k-1);
    push(root->point);

    // traversing points by comparision with root wrt dimension
    if (point[cd] < root->point[cd])
        return search(root->left, point, depth + 1);

    return search(root->right, point, depth + 1);
}

// main function to search element 
bool search_main(node *root, int point[])
{
    // initial depth 0
    return search(root, point, 0);
}