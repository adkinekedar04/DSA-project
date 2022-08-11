#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"kdTree.h"
#include"stack.h"
#include"helper.h"
#define N 1000

extern int k;
extern int count;
extern int t;
extern int target[N];
extern int c1,c2;



struct node_in *create_data(int arr[])
{
    struct node_in *temp = (struct node_in *)calloc(1, sizeof(struct node_in));
    temp->point = calloc(k, sizeof(int));
    for (int i = 0; i < k; i++){
        temp->point[i] = arr[i];
    }
    return temp;
}

// Function to push node in the custom stack
void push(int arr[])
{
    if (top == NULL)
    {
        top = (struct node_s *)malloc(1 * sizeof(struct node_s));
        top->next = NULL;
        top->info = create_data(arr);
    }
    else
    {
        temp = (struct node_s *)malloc(1 * sizeof(struct node_s));
        temp->next = top;
        temp->info = create_data(arr);
        top = temp;
    }
    count++;
}

// Function to pop a node in custom stack
void pop()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Stack is empty \n");
        return;
    }

    for (int i = 0; i < k; i++)
    {
        printf("%d ", top1->info->point[i]);
    }
    printf("\n");

    push_to_array(top1->info->point[k-1]);

    top1 = top1->next;
    top = top1;
    count--;
}

// dislaying the elements of stack
void display()
{
    top1 = top;

    if (top1 == NULL)
    {
        printf("Stack is empty");
        return;
    }

    while (top1 != NULL)
    {
        for (int i = 0; i < k; i++)
            printf("%d \n", top1->info->point[i]);
        top1 = top1->next;
    }
}


