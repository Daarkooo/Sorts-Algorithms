#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a=*b; 
    *b = temp;
}

int partition(int tab[], int l, int h) {
    int pivot = tab[l];
    int start = l;
    int end = h;

    while(start < end) {
        while(tab[start]<=pivot) start++;
        while(tab[end]>pivot) end--;

        if(start < end) swap(&tab[start],&tab[end]);  
    }
    swap(&tab[l],&tab[end]);
    return end;
    
}

void quicksort(int tab[], int l ,int h){
    if(l<h){
        int loc = partition(tab,l,h);
        quicksort(tab,l,loc-1);
        quicksort(tab,loc+1,h);
    }
}

int main(){
    int tab[]={15,18,129,6,8,4};
    int n = sizeof(tab)/sizeof(int);
    int i=0;
    
    quicksort(tab,0,n-1);

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }
    
    return 0;
}