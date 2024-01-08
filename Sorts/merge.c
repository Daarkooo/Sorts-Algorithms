#include <stdlib.h>
#include <stdio.h>

void merge(int tab[], int l,int mid, int h){
    int *sortedTab = (int *)malloc((h - l + 1) * sizeof(int));
    int i=l;
    int j=mid+1;
    int k=l;
    while (i <= mid && j <= h) {
        if (tab[i] <= tab[j]) {
            sortedTab[k] = tab[i];
            i++;
        } else {
            sortedTab[k] = tab[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        sortedTab[k] = tab[i];
        i++;
        k++;
    }

    while (j <= h) {
        sortedTab[k] = tab[j];
        j++;
        k++;
    }

    for(k=l;k<=h;k++){
        tab[k]=sortedTab[k];
    }

    free(sortedTab);
}

void mergeSort(int tab[], int l, int h){
    if(l<h){
        int mid = (l+h)/2;
        mergeSort(tab, l, mid);
        mergeSort(tab, mid+1, h);
        merge(tab,l, mid, h);
    }
}


int main(){
    int tab[]={15,18,129,6,8,4};
    int n = sizeof(tab)/sizeof(int);
    int i=0;
    
    mergeSort(tab,0,n-1);

    
    
    return 0;
}