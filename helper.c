#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include"kdTree.h"
#include"stack.h"
#include"helper.h"
#define N 1000


extern int k;
extern int count;
int target[N];
int c1=0,c2=0;
int t=-1;

void push_to_array(int data){
    t++;
    target[t]=data;
}


void count_1(){
    for(int i=t;i>=0;i--){
        if(target[i]==1) c1++;
        else if(target[i]==0) c2++;
    }
    
}

void display_array(){
    for(int i=t;i>=0;i--){
        printf("%d ",target[i]);
    }
}