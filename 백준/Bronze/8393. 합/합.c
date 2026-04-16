#include <stdio.h>

int main(void){
    int k;
    scanf("%d", &k);
    int total=0;
    for(int i = 1; i<=k; i++){
        total +=i;
    }
    printf("%d",total);
}