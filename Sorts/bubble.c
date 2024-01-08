#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a=*b; 
    *b = temp;
}

int main(){
    int tab[]={15,18,6,8,4};
    int n = sizeof(tab)/sizeof(int);
    int i=0;
    bool tmp=true;
    while(tmp){
        tmp = false;
        for(int j=0; j<n-1-i; j++){
            if(tab[j]>tab[j+1]){
                swap(&tab[j], &tab[j+1]);
                tmp = true;
            }
        }
        i++;
    }

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }
    
    return 0;
}