#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int tab[]={15,18,6,8,4};
    int n = sizeof(tab)/sizeof(int);
    int i=0;
    
    for(int i=1; i<n; i++){
        int tmp = tab[i];
        int j=i-1;
        while (j>=0 && tab[j]>tmp) {
            tab[j+1] = tab[j];
            j--;
        }
        tab[j+1] = tmp;
    }

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }
    
    return 0;
}