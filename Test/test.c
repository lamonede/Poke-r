#include <stdio.h>
#include <stdlib.h>

//Learn About malloc.

int main(){
    int* list;
    int n = 0;

    scanf("%d", &n);

    list = (int*)malloc(sizeof(int) * n);

    for(int i  = 0; i < n; i++){
        list[i] = i + 1;
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", list[i]);
    }

    return 0;
}