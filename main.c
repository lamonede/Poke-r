//Spade > Diamond > Clover > Heart
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CARD_NUM 20

int card_shape_checker(char a, char b);

int main(){
    int result = 0;
    int num_of_people = 3;
    char card[CARD_NUM] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    srand(time(NULL));

    for(int i = 0; i < 5+3*num_of_people; i++){
        card[i] = rand()%61;
    }
    for(int i = 0; i < CARD_NUM-1; i++){
        for(int j = 0; j < CARD_NUM; j++){
            result = card_shape_checker(card[i], card[j]);
            printf("%d\n", result);
        }
    }
}

int card_shape_checker(char a, char b){
    unsigned char result = ~(a^b); //xnor
    return result;
}