#include <stdio.h>
#include <stdlib.h>


int main(){
    int tab[]={15,18,12,6,8,4};
    int n = sizeof(tab)/sizeof(int);
    int i;
    int max = 0;
    for(i=0; i<n; i++){
        if(tab[i]>max){
            max=tab[i];
        }
    }

    int count[max+1];

    for (i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for(i=0; i<n; i++){
        count[tab[i]]++;
    }
    for(i=1; i<=max; i++){
        count[i]=count[i]+count[i-1];
    }

    int zeroTab[n];
    // int zeroTab[n]={0};

    for(i=0; i<n; i++){
        zeroTab[i]=0;
    }

    for(i=n-1; i>=0; i--){
        zeroTab[--count[tab[i]]]=tab[i];
    }

    for (int i = 0; i < n; i++){
        tab[i]=zeroTab[i];
    }

    for (int i = 0; i < n; i++){
        printf("%d \n", tab[i]);
    }
    
    return 0;
}