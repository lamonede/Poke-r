//Spade > Diamond > Clover > Heart
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

void main_screen();

int main(){
    int result = 0;
    int num_of_people = 4;
    int temp;
    int i = 0;
    int j = 0;
    char key;
    unsigned char card[13];
    srand(time(NULL));

    for(int k = 0; k < 13; k++){
        card[k] = '\0';
    }

    while(1){
        system("cls");
        main_screen();
        key = _getch();
        if(key == '1'){
            break;
        } else if(key == '2'){
            return 0;
        }
    }

    while(i != 13){
        card[i] = rand()%52;
        for(int j = 0; j < i; j++){
            if(card[j] == card[i]){
                i--;
                break;
            }
        }
        i++;
    }

    system("cls");
    printf("My Card: ");
    for(int i = 0; i < 2; i++){
        if(((card[i]) / 13) == 0){
            printf("Spade%d", card[i] + 1);
        } else if(((card[i]) / 13) == 1){
            printf("Diamond%d", card[i] - 12);
        } else if(((card[i]) / 13) == 2){
            printf("Heart%d", card[i] - 25);
        } else if(((card[i]) / 13) == 3){
            printf("Clover%d", card[i] - 38);
        }
        if(i != 1){
            printf(", ");
        } else {
            printf("\n");
        }
    }


    printf("\n1) Bet\n");
    printf("2) Fold\n");

    while(1){
        key = _getch();
        if(key == '1'){
            ;
        } else if(key == '2'){
            ;
        }
    }



    /*for(int i = 0; i < 13; i++){
        if(((card[i]) / 13) == 0){
            printf("Card is Spade%d\n", card[i] + 1);
        } else if(((card[i]) / 13) == 1){
            printf("Card is Diamond%d\n", card[i] - 12);
        } else if(((card[i]) / 13) == 2){
            printf("Card is Heart%d\n", card[i] - 25);
        } else if(((card[i]) / 13) == 3){
            printf("Card is Clover%d\n", card[i] - 38);
        }
    }*/

    return 0;
}

void main_screen(){
    /*printf("\n");
    printf("______         _                    ______ \n");
    printf("| ___ \\       | |                   | ___ \\\n");
    printf("| |_/ /  ___  | | __  ___   ______  | |_/ /\n");
    printf("|  __/  / _ \\ | |/ / / _ \\ |______| |    / \n");
    printf("| |    | (_) ||   < |  __/          | |\\ \\ \n");
    printf("\\_|     \\___/ |_|\\_\\ \\___|          \\_| \\_|\n");
    printf("\n\n\n");*/
    printf("1) Start\n");
    printf("2) Exit\n"); 
}

void in_game(char key, char card[]){
    int j = 0;
    system("cls");
    printf("My Card: ");
    for(int i = 0; i < 2; i++){
        if(((card[i]) / 13) == 0){
            printf("Spade%d", card[i] + 1);
        } else if(((card[i]) / 13) == 1){
            printf("Diamond%d", card[i] - 12);
        } else if(((card[i]) / 13) == 2){
            printf("Heart%d", card[i] - 25);
        } else if(((card[i]) / 13) == 3){
            printf("Clover%d", card[i] - 38);
        }
        if(i != 1){
            printf(", ");
        } else {
            printf("\n");
        }
    }
    j = 11;
    printf("Community Card: ");
    for(int i = 8; i < j; i++){
        if(((card[i]) / 13) == 0){
            printf("Spade%d", card[i] + 1);
        } else if(((card[i]) / 13) == 1){
            printf("Diamond%d", card[i] - 12);
        } else if(((card[i]) / 13) == 2){
            printf("Heart%d", card[i] - 25);
        } else if(((card[i]) / 13) == 3){
            printf("Clover%d", card[i] - 38);
        }
        if(i != 12){
            printf(", ");
        } else {
            printf("\n");
        }
    }

    printf("\n1) Bet\n");
    printf("2) Fold\n");

    while(1){
        system("cls");
        key = _getch();
        if(key == '1'){
            j++;
            break;
        } else if(key == '2'){
            j = 13;
            break;
        }
    }
}