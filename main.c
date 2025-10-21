//Spade > Diamond > Clover > Heart.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

void main_screen();
void in_game(char card[], char commu_card[][11], char player_card[][11]);

int main(){
    int result = 0;
    int num_of_people = 4;
    int temp;
    int i = 0;
    int j = 0;
    char key;
    unsigned char card[13];
    char player_card[2][11] = {
        "???",
        "???"
    };
    char commu_card[5][11] = {
        "???",
        "???",
        "???",
        "???",
        "???"
    };
    int calc_table[4][7];
    srand(time(NULL));

    for(int k = 0; k < 13; k++){ //card array reset
        card[k] = '\0';
    }

    while(i != 13){ //shuffle card no duplication
        card[i] = rand()%52;
        for(int j = 0; j < i; j++){
            if(card[j] == card[i]){
                i--;
                break;
            }
        }
        i++;
    }

    while(1){ //main screen selection step
        main_screen(); //call print screen
        key = _getch();
        if(key == '1'){
            break;
        } else if(key == '2'){
            return 0;
        }
    }

    in_game(card, commu_card, player_card);

    for(int i = 0; i < 4; i++){ //player card& commu card move to calc table
        for(int j = 2; j < 7; j++){
            calc_table[i][j] = card[j+6];
        }
        for(int k = 0; k < 2; k++){
            calc_table[i][k] = card[(i*2)+k];
        }
    }

    for(int n = 0; n < 4; n++){
        for(int o = 0; o < 7; o++){
            printf("calc[%d][%d] = %d\n", n, o, calc_table[n][o]);
        }
        printf("---------------\n");
    }

    for(int l = 0; l < 4; l++){//5   4   3   2   1
        for(int m = 0; m < 7; m){
            if(calc_table[l][m] > calc_table[l][m+1]){
                temp = calc_table[l][m];
                calc_table[l][m] = calc_table[l][m+1];
                calc_table[l][m+1] = temp;
                m = 0;
            } else {
                m++;
            }
        }
    }

    for(int n = 0; n < 4; n++){
        for(int o = 0; o < 7; o++){
            printf("calc[%d][%d] = %d\n", n, o, calc_table[n][o]);
        }
        printf("---------------\n");
    }


    system("pause");
    return 0;
}

void main_screen(){ /**초기 화면 제목 및 선택 단계 */
    char key;
    //system("cls");
    /*printf("\n");
    printf("______         _                    ______ \n");
    printf("| ___ \\       | |                   | ___ \\\n");
    printf("| |_/ /  ___  | | __  ___   ______  | |_/ /\n");
    printf("|  __/  / _ \\ | |/ / / _ \\ |______| |    / \n");
    printf("| |    | (_) ||   < |  __/          | |\\ \\ \n");
    printf("\\_|     \\___/ |_|\\_\\ \\___|          \\_| \\_|\n");
    printf("\n\n\n");
    */
    printf("1) Start\n");
    printf("2) Exit\n"); 
}

void in_game(char card[], char commu_card[][11], char player_card[][11]){
    int i = 0;
    int j = 8;
    int k = 11;
    int lemonade = 1;
    char key = 0;
    char card_name[13][3] = {
        "A",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "J",
        "Q",
        "K"
    };

    while(lemonade){ //print card
        //system("cls");
        while(i < 2){ //card[0~7] Player1,2,3,4 Card
            if ((0 <= card[i]) && (card[i] <= 12)){
                sprintf(player_card[i], "Spade-%s", card_name[card[i]%13]);
                i++;
            } else if((13 <= card[i]) && (card[i] <= 25)){
                sprintf(player_card[i], "Diamond-%s", card_name[card[i]%13]);
                i++;
            } else if((26 <= card[i]) && (card[i] <= 38)){
                sprintf(player_card[i], "Heart-%s", card_name[card[i]%13]);
                i++;
            } else if((39 <= card[i]) && (card[i] <= 51)){
                sprintf(player_card[i], "Clover-%s", card_name[card[i]%13]);
                i++;
            }
        }
        printf("My Card: %s, %s\n", player_card[0], player_card[1]);
        
        while(j < k){ //card[8]부터 Community Card
            if ((0 <= card[j]) && (card[j] <= 12)){
                sprintf(commu_card[j-8], "Spade-%s", card_name[card[j]%13]); //j의 값은 commu card의 순서 즉 이미 배부된 카드 하지만 필요한 값은 card임, 값을 잘 못 불러옴
                j++;
            } else if((13 <= card[j]) && (card[j] <= 25)){
                sprintf(commu_card[j-8], "Diamond-%s", card_name[card[j]%13]);
                j++;
            } else if((26 <= card[j]) && (card[j] <= 38)){
                sprintf(commu_card[j-8], "Heart-%s", card_name[card[j]%13]);
                j++;
            } else if((39 <= card[j]) && (card[j] <= 51)){
                sprintf(commu_card[j-8], "Clover-%s", card_name[card[j]%13]);
                j++;
            }
        }
        printf("Community Card: %s, %s, %s, %s, %s", commu_card[0], commu_card[1], commu_card[2], commu_card[3], commu_card[4]);

        printf("\n1) Bet\n");
        printf("2) Fold\n");

        while(1){
            if(j == 13){
                lemonade = 0;
            }
            key = _getch();
            if(key == '1'){
                k++;
                break;
            } else if(key == '2'){
                k = 13;
                break;
            }
        }
    }
}