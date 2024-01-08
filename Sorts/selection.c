#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a=*b; 
    *b = temp;
}

int main(){
    int tab[]={25,18,6,2,4,19};
    int n = sizeof(tab)/sizeof(int);
    for(int i=0; i<n-1; i++) {
        int min = i;
        for(int j=i+1; j<n; j++) {
            if(tab[j]<tab[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(&tab[i], &tab[min]);
        }
    }

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }
    
    return 0;
}