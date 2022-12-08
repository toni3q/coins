#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<stdbool.h>
int main(){ system("TITLE C-Coins");
            system("color 9");

    // TAKING LAST VALUES (SAVED) //

    //taking your last wallet data.
    double wallet = 1500;
    FILE * fPointer;
    fPointer = fopen("wallet.txt", "r");
    fscanf(fPointer, "%lf", &wallet);
    fclose(fPointer);
    //printf("\nwallet: %lf", wallet);

    //taking your last c-coins.
    double coins = 0;
    fPointer = fopen("coins.txt", "r");
    fscanf(fPointer, "%lf", &coins);
    fclose(fPointer);
    //printf("\ncoins: %lf", coins);

    //taking your last c-coins value.
    double coinsValue;
    fPointer = fopen("value.txt", "r");
    fscanf(fPointer, "%lf", &coinsValue);
    fclose(fPointer);    
    //printf("\ncoinsValue: %lf", coinsValue);

    //taking your last bank details.
    double bankBalance;
    fPointer = fopen("bank.txt", "r");
    fscanf(fPointer, "%lf", &bankBalance);
    fclose(fPointer);

    double transfer;

    double randomValueChanger = 0;
    double randomValueMultiplier = 0;
        double valueAdd = 0;

    double randomValueDecrease = 0;
    double randomValueDecreaseMultiplier = 0;
        double valueDecrease = 0;

    double coinsAmount = 0;
    double coinsCheckout = 0;


//start
char option, exit, shop, bank, atm;
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
        printf("\n\n[Q] Quit");

        //user choise.
        option = getch();

    }while(option != 'E' && option != 'e' && option != 'S' && option !='s' && option !='Q' && option !='q');


    // BANKING SYSTEM //

    if(option == 'E' || option == 'e'){
        do{
            system("cls");
            printf("[Wallet]");
            printf("\nAvaible: $%.2f", wallet);
            printf("\nC-Coins: %.2f ($%.2f)", coins, coinsValue*coins);

            printf("\n\n[B] Bank Account");
            printf("\n\n[X] (/) Deny");
            bank = getch();
        }while(bank != 'B' && bank != 'b' && bank != 'X' && bank != 'x');

        if(bank == 'B' || bank == 'b'){
            do{
                system("cls");
                printf("[Bank Details]");
                printf("\nBalance: $%.2f\n", bankBalance);
                printf("\n[D] (+) Deposit");
                printf("\n[W] (-) Withdraw");
                printf("\n\n[X] (/) Deny");
                atm = getch();
            }while(atm != 'D' && atm != 'd' && atm != 'W' && atm != 'w' && atm != 'X' && atm != 'x');

            if(atm == 'D' || atm == 'd'){
                printf("\n\nDeposit Amount: $");
                scanf("%lf", &transfer);

                // TAXES //
                double taxes;
                taxes = transfer * 0.0025;
                printf("Taxes: $%.2f", taxes);

                wallet = wallet - transfer;
                bankBalance = bankBalance + transfer;
                bankBalance = bankBalance - taxes;
            }

            if(atm == 'W' || atm == 'w'){
                printf("\n\nWithdraw Amount: $");
                scanf("%lf", &transfer);

                // TAXES //
                double taxes;
                taxes = transfer * 0.0025;
                printf("Taxes: $%lf", taxes);

                wallet = wallet + transfer;
                bankBalance = bankBalance - transfer;
                bankBalance = bankBalance - taxes;
            }
        }
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
                coinsValue = coinsValue + (valueAdd * 1.025) - (valueDecrease * 0.875);

            //printing current C-Coins value.
            sleep(1);
            printf("\n\n[R] Refresh");
            printf("\nC-Coins Live Value: %.2f$", coinsValue);
            printf("\nLast Value Change: %.2f$", valueAdd-valueDecrease);

            printf("\n\n[X] (/) Deny");
            shop = getch();

        }while(shop != 'B' && shop != 'b' && shop != 'S' && shop != 's' && shop != 'X' && shop != 'x');


        // BUY C-COINS //

        if(shop == 'B' || shop == 'b'){
            printf("\n\ntype the amount to buy: ");
            scanf("%lf", &coinsAmount);
                coinsCheckout = coinsAmount * coinsValue;

            if(coinsCheckout > wallet){
                printf("\nsorry, you can't afford this amount of C-Coins.");
                printf("\nGo back into 'Home' and check your wallet!");
                coinsValue = coinsValue - (0.0005 * coinsCheckout);
            }

            if(coinsCheckout <= wallet){
                coins = coins + coinsAmount;
                wallet = wallet - coinsCheckout;
                printf("\nTransaction complete. C-Coins redeemed!");
                coinsValue = coinsValue + (0.0025 * coinsCheckout);
            }
        }


        // SELL YOUR C-COINS //

        if(shop == 'S' || shop == 's'){
            printf("\n\ntype the amount to sell: ");
            scanf("%lf", &coinsAmount);

            if(coinsAmount > coins){
                printf("\nsorry, you've not this amount of C-Coins.");
                printf("\nGo back into 'Home' and check your wallet!");
                coinsValue = coinsValue - (0.0005 * coinsCheckout);
            }

            if(coinsAmount <= coins){
                coinsCheckout = coinsAmount * coinsValue;
                wallet = wallet + coinsCheckout;
                coins = coins - coinsAmount;
                printf("\nTransaction complete.");
                coinsValue = coinsValue + (0.0010 * coinsCheckout);
            }
        }
    }   


    // LAST SAVE //

    //wallet last value.
    FILE * fPointer;
    fPointer = fopen("wallet.txt", "w");
    fprintf(fPointer, "%lf", wallet);
    fclose(fPointer);

    //coins last amount you had into your wallet.
    fPointer = fopen("coins.txt", "w");
    fprintf(fPointer, "%lf", coins);
    fclose(fPointer);

    //coins last value.
    fPointer = fopen("value.txt", "w");
    fprintf(fPointer, "%lf", coinsValue);
    fclose(fPointer);

    //bank balance last value.
    fPointer = fopen("bank.txt", "w");
    fprintf(fPointer, "%lf", bankBalance);
    fclose(fPointer);


    //stay or exit.
        printf("\n\n\n\n\n");
    printf("\t[P] Main Menu");
        printf("\n");
    printf("\t[/] Save and Exit");
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
    printf("\nC-Coins Live Value: %lf$", coinsValue);
*/