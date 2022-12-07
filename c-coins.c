#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<stdbool.h>
int main(){ system("TITLE C-Coins");

    // TAKING LAST VALUES (SAVED) //

    //taking your last wallet data.
    float wallet = 1500;
    FILE * fPointer;
    fPointer = fopen("wallet.txt", "r");
    fscanf(fPointer, "%f", &wallet);
    fclose(fPointer);
    //printf("\nwallet: %f", wallet);

    //taking your last c-coins.
    float coins = 0;
    fPointer = fopen("coins.txt", "r");
    fscanf(fPointer, "%f", &coins);
    fclose(fPointer);
    //printf("\ncoins: %f", coins);

    //taking your last c-coins value.
    float coinsValue;
    fPointer = fopen("value.txt", "r");
    fscanf(fPointer, "%f", &coinsValue);
    fclose(fPointer);    
    //printf("\ncoinsValue: %f", coinsValue);


    float randomValueChanger = 0;
    float randomValueMultiplier = 0;
        float valueAdd = 0;

    float randomValueDecrease = 0;
    float randomValueDecreaseMultiplier = 0;
        float valueDecrease = 0;

    float coinsAmount = 0;
    float coinsCheckout = 0;


//start
char option, exit, shop;
do{
    do{

        // MAIN MENU //

        system("cls");
        //main menu with the following options: Wallet, Shop.
        printf("[E] Banking System");
        printf("\n[S] C-Coins Market");

        //printing some informations that the user can read and use during the game!
        printf("\n\nWelcome to C-Coins platform.\nBuy or Sell C-Coins easely and quickly!\n");
        printf("\n- The value of the C-Coins changes by the supply and demand.");
        printf("\n- Each transaction between you and the platform is charged with 0.00$ of taxes.");
        printf("\n- You can basically do it from every country in the planet.");

        //user choise.
        option = getch();

    }while(option != 'E' && option != 'e' && option != 'S' && option !='s');


    // BANKING SYSTEM //

    if(option == 'E' || option == 'e'){
        system("cls");
        printf("[Wallet]");
        printf("\nBalance: %f$", wallet);
        printf("\nC-Coins: %f (%f$)", coins, coinsValue*coins);
    }


    // C-COINS MARKET //

    if(option == 'S' || option == 's'){
        coinsAmount = 0;
        coinsCheckout = 0;

        do{
            //this cicle will repeat the same instructions until shop will be true

            system("cls");
            system("cls");
            printf("[Shop]");
            printf("\n[B] (+) Buy");
            printf("\n[S] (-) Sell");
            printf("\n\n[E] (/) Deny");

            //C-Coins value system.
                srand(time(0));
                //we can only get a number from 1 to 3 as changer multiplier.
                randomValueMultiplier = (rand() % 3) + 1;
                //we can get a number from 1 to 10 as changer to multiply.
                randomValueChanger = (rand() % 10) + 1;      
                //final step to get a pseudo-random variation on the coin value.
                valueAdd = randomValueMultiplier * randomValueChanger;
                //we can only get a number from 1 to 3 as changer multiplier.
                randomValueDecreaseMultiplier = (rand() % 3) + 1;
                //we can get a number from 1 to 10 as changer to multiply.
                randomValueDecrease = (rand() % 10) + 1;
                //final step to get a pseudo-random variation on the coin value.
                valueDecrease = randomValueDecreaseMultiplier * randomValueDecrease;
                //adding the value we got previously.
                coinsValue = coinsValue + (valueAdd * 1.020) - (valueDecrease * 0.900);

            //printing current C-Coins value.
            sleep(1);
            printf("\n\n[R] Refresh");
            printf("\nC-Coins Live Value: %f$", coinsValue);
            printf("\nLast Value Change: %f$", valueAdd-valueDecrease);
            shop = getch();

        }while(shop != 'B' && shop != 'b' && shop != 'S' && shop != 's' && shop != 'E' && shop != 'e');


        // BUY C-COINS //

        if(shop == 'B' || shop == 'b'){
            printf("\n\ntype the amount to buy: ");
            scanf("%f", &coinsAmount);
                coinsCheckout = coinsAmount * coinsValue;

                if(coinsCheckout > wallet){
                    printf("\nsorry, you can't afford this amount of C-Coins.");
                    printf("\nGo back into 'Home' and check your wallet!");
                    coinsValue = coinsValue + 0.005 * coinsCheckout;
                }

                if(coinsCheckout <= wallet){
                    coins = coins + coinsAmount;
                    wallet = wallet - coinsCheckout;
                    printf("\nTransaction complete. C-Coins redeemed!");
                    coinsValue = coinsValue + 0.005 * coinsCheckout;
                }

        }


        // SELL YOUR C-COINS //

        if(shop == 'S' || shop == 's'){

            printf("\n\ntype the amount to sell: ");
            scanf("%f", &coinsAmount);

                if(coinsAmount > coins){
                    printf("\nsorry, you've not this amount of C-Coins.");
                    printf("\nGo back into 'Home' and check your wallet!");
                    coinsValue = coinsValue + 0.005 * coinsCheckout;
                }

                if(coinsAmount <= coins){
                    coinsCheckout = coinsAmount * coinsValue;
                    wallet = wallet + coinsCheckout;
                    coins = coins - coinsAmount;
                    printf("\nTransaction complete.");
                    coinsValue = coinsValue + 0.005 * coinsCheckout;
                }
    
        }

    }   


    // LAST SAVE //

    //wallet last value.
    FILE * fPointer;
    fPointer = fopen("wallet.txt", "w");
    fprintf(fPointer, "%f", wallet);
    fclose(fPointer);

    //coins last amount you had into your wallet.
    fPointer = fopen("coins.txt", "w");
    fprintf(fPointer, "%f", coins);
    fclose(fPointer);

    //coins last value.
    fPointer = fopen("value.txt", "w");
    fprintf(fPointer, "%f", coinsValue);
    fclose(fPointer);


    //stay or exit.
        printf("\n\n\n\n");
        printf("\n\n\n\n");
    printf("\t[P] Go Back.");
        printf("\n");
    printf("\t[ENTER] Save and Exit");
        exit = getch();


}while(exit == 'P' || exit == 'p');

printf("\n\nYou're leaving!\nSee you next time!");

getch();
return 0;
}

/*
    //C-Coins value system.
    srand(time(0));
    //we can only get a number from 1 to 3 as changer multiplier.
    randomValueMultiplier = (rand() % 3) + 1;
    //we can get a number from 1 to 10 as changer to multiply.
    randomValueChanger = (rand() % 10) + 1;      
    //final step to get a pseudo-random variation on the coin value.
    valueAdd = randomValueMultiplier * randomValueChanger;
    //we can only get a number from 1 to 3 as changer multiplier.
    randomValueDecreaseMultiplier = (rand() % 3) + 1;
    //we can get a number from 1 to 10 as changer to multiply.
    randomValueDecrease = (rand() % 10) + 1;
    //final step to get a pseudo-random variation on the coin value.
    valueDecrease = randomValueDecreaseMultiplier * randomValueDecrease;
    //adding the value we got previously.
    coinsValue = coinsValue + (valueAdd * 1.020) - (valueDecrease * 0.980);

    //printing current C-Coins value.
    sleep(1);
    printf("\n\n[R] Refresh");
    printf("\nC-Coins Live Value: %f$", coinsValue);
*/