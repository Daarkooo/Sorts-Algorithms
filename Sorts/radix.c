#include <stdlib.h>
#include <stdio.h>


void countSort(int tab[], int n, int pos){
    int count[10]={0};

    int sortedTab[n];

    for(int i=0; i<n; i++){
        ++count[(tab[i]/pos)%10];
    }

    for(int i=1; i<10; i++){
        count[i] += count[i-1];
    }

    for(int i=n-1; i>=0; i--){
        sortedTab[--count[(tab[i]/pos)%10]] = tab[i]; 
    }

    for(int i=0; i<n; i++){
        tab[i] = sortedTab[i];
    }

}


int main(){
    int tab[]={315,218,129,006,208,318};
    int n = sizeof(tab)/sizeof(int);
    int max=0;
    for(int i=0; i<n; i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    for(int pos=1;max/pos>0 ; pos*=10){ // pos=1 , pos=10, pos=100 .... until max/pos==0
        countSort(tab,n,pos);
    }

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }


    return 0;
}