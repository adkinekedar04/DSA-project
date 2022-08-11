#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include"kdTree.h"
#include"stack.h"
#include"helper.h"
#define N 1000

int k;
int count=0;
int arr[N];
extern int c1;
extern int c2;

int min(int a, int b)
{
    if (a <= b) return a;
    else return b;
    
}

int main()
{
    // comment the below line if you want an interactive console
    FILE *fileptr;
    fileptr = fopen("input.txt", "r");

    // for interactive console
  
    
    struct node *root = NULL;
    //printf("Enter dimension : ");
    fscanf(fileptr,"%d", &k);
    printf("%d\n",k);

    int n;
    // printf("Enter number of points : ");
    fscanf(fileptr,"%d", &n);
    printf("%d\n",n);

    int neighbours;
    //printf("Enter number of neighbours : ");
    fscanf(fileptr,"%d", &neighbours);
    printf("%d",neighbours);
    for (int i = 0; i < n; i++)
    {
        //printf("Enter %d th set of data point : ", i + 1);
        for (int i = 0; i < k; i++)
        {
            fscanf(fileptr,"%d", &arr[i]);
        }
        
        root = insert_main(root, arr);
    }
    
    // printf("Enter the set of data point you want to find : ");
    int find[k-1];
    for (int i = 0; i < k-1; i++)
    {
        fscanf(fileptr,"%d", &find[i]);
    }
    //printf("\n");
    if (search_main(root, find))
    {
        printf("\nFound\n");
    }
    else
    {
        printf("\nNot found\n");
    }

    int req = min(neighbours, count);
    printf("The %d closest data points related to this data point are : \n", neighbours);
    for (int i = 0; i < req; i++)
    {
        pop();
    }
    //display_array();
    count_1();
    //printf("%d %d",c1,c2);
    if(c1>c2){ 
        if(search_main(root, find)){
            printf("\nPredicted Outcome %d",1);

            printf("Original Outcome %d",root->point[k-1]); 
        }
        else{
            printf("\nPredicted Outcome %d",1);

        }
    }
    else if(c1<c2){
        if(search_main(root, find)){
            printf("\nPredicted Outcome %d",0);

            printf("Original Outcome %d",root->point[k-1]); 
        }
        else{
            printf("\nPredicted Outcome %d",0);

        }
    }
    else{
        if(search_main(root, find)){
            printf("\nPredicted Outcome %d/%d",0,1);

            printf("Original Outcome %d",root->point[k-1]); 
        }
        else{
            printf("\nPredicted Outcome %d/%d",0,1);

        }
    }   
    return 0;
}