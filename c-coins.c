#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<stdbool.h>
int main(){ system("TITLE C-Coins");

    double wallet = 1500.00;
    FILE * fPointer;
    fPointer = fopen("wallet.txt", "r");
    fscanf(fPointer, "%lf", &wallet);
    fclose(fPointer);

    double coins = 0.00;
    fPointer = fopen("coins.txt", "r");
    fscanf(fPointer, "%lf", &coins);
    fclose(fPointer);

    double coinsValue = 100.00;
    fPointer = fopen("value.txt", "r");
    fscanf(fPointer, "%lf", &coinsValue);
    fclose(fPointer);    

    double bankBalance = 1000.00;
    fPointer = fopen("bank.txt", "r");
    fscanf(fPointer, "%lf", &bankBalance);
    fclose(fPointer);

    double transfer = 0.00;

    double matrix = 0.00;
    fPointer = fopen("matrix.txt", "r");
    fscanf(fPointer, "%lf", &matrix);
    fclose(fPointer);

    double randomValueChanger = 0;
    double randomValueMultiplier = 0;
        double valueAdd = 0;

    double randomValueDecrease = 0;
    double randomValueDecreaseMultiplier = 0;
        double valueDecrease = 0;

    double coinsAmount = 0;
    double coinsCheckout = 0;

    double LastPurchase = 0;
    fPointer = fopen("purchase.txt", "r");
    fscanf(fPointer, "%lf", &LastPurchase);
    fclose(fPointer);

char option, exit, shop, bankAction;
do{
    do{
        system("cls");
        printf("[W] Wallet");
        printf("\n[S] C-Coins Market");

        printf("\n\nWelcome to C-Coins platform.\nBuy or Sell C-Coins easely and quickly!\n");
        printf("\n- The value of the C-Coins changes by the supply and demand.");
        printf("\n- Each transaction between you and the platform is charged with taxes.");
        printf("\n- You can basically do it from every country in the planet.");

        printf("\n\n\n\n\t[O] Options");
        option = getch();

    }while(option != 'W' && option != 'w' && option != 'S' && option !='s' && option !='O' && option !='o');

    if(option == 'W' || option == 'w'){
            system("cls");
            printf("[Wallet]");
            printf("\nAvaible: $%.2f", wallet);
            printf("\nAccount: $%.2f\n", bankBalance);
            printf("\n[D] (+) Deposit");
            printf("\n[W] (-) Withdraw\n");
            printf("\n\n[Coins]");
            printf("\nC-Coins: %.2f ($%.2f)", coins, coinsValue*coins);
            printf("\n\n\n\n\t[O] Options");
            bankAction = getch();

            if(bankAction == 'D' || bankAction == 'd'){
                system("cls");
                printf("[Deposit]\n");
                printf("Type the amount: $");
                scanf("%lf", &transfer);

                if(transfer > wallet){
                    printf("\nTransaction failed: Check your wallet.");
                }

                if(transfer <= wallet){
                    double taxes;
                    taxes = transfer * 0.0025;
                    printf("\n\nTransaction complete: \n[+] $%.2f\n[-] $%.2f\n", transfer - taxes, taxes);

                    wallet = wallet - transfer;
                    bankBalance = bankBalance + (transfer - taxes);

                        matrix = matrix + taxes;

                    printf("\nBalance: $%.2f\n", bankBalance);
                    printf(" Wallet: $%.2f\n", wallet);
                }
            }

            if(bankAction == 'W' || bankAction == 'w'){
                system("cls");
                printf("[Withdraw]\n");
                printf("Type the amount: $");
                scanf("%lf", &transfer);

                if(transfer > bankBalance){
                    printf("\nTransaction failed: Check your balance.");
                }

                if(transfer <= bankBalance){
                    double taxes;
                    taxes = transfer * 0.0025;
                    printf("\n\nTransaction complete: \n[+] $%.2f\n[-] $%.2f\n", transfer - taxes, taxes);

                    wallet = wallet + (transfer - taxes);
                    bankBalance = bankBalance - transfer;

                        matrix = matrix + taxes;

                    printf("\nBalance: $%.2f\n", bankBalance);
                    printf(" Wallet: $%.2f\n", wallet);
                    
                }
            }
        
    }

    if(option == 'S' || option == 's'){
        coinsAmount = 0;
        coinsCheckout = 0;

        do{
            system("cls");
            printf("[Coins]");
            printf("\nC-Coins: %.2f ($%.2f)", coins, coinsValue*coins);

            printf("\n\n[Shop]");
            printf("\n[B] (+) Buy");
            printf("\n[S] (-) Sell");

            srand(time(0));
            randomValueMultiplier = (rand() % 3) + 1;
            randomValueChanger = (rand() % 10) + 1;      
            valueAdd = randomValueMultiplier * randomValueChanger;
            randomValueDecreaseMultiplier = (rand() % 3) + 1;
            randomValueDecrease = (rand() % 10) + 1;
            valueDecrease = randomValueDecreaseMultiplier * randomValueDecrease;
            coinsValue = coinsValue + (valueAdd * 1.025) - (valueDecrease * 0.875);

            sleep(1);
            printf("\n\n[R] Refresh");
            printf("\nLast Value Change: $%.2f", valueAdd-valueDecrease);
            printf("\nC-Coins Live Value: $%.2f", coinsValue);
                if((valueAdd-valueDecrease) < 0){printf(" ");}
                if((valueAdd-valueDecrease) > 0){printf(" ");}
                if((valueAdd-valueDecrease) == 0){printf(" ");}
            printf("\n\nLast Coin Purchase: $%.2f", LastPurchase);

            if(LastPurchase > coinsValue){
                printf("\nYou're losing money.");
                printf("\nLost: -$%.2f", LastPurchase - coinsValue);
            }

            if(LastPurchase < coinsValue){
                printf("\nYou're earning money.");
                printf("\nEarn: $%.2f", coinsValue - LastPurchase);
            }

            printf("\n\n\n\n\t[O] Options");
            shop = getch();

        }while(shop != 'B' && shop != 'b' && shop != 'S' && shop != 's' && shop != 'O' && shop != 'o');

        if(shop == 'B' || shop == 'b'){
            system("cls");
            printf("[Buying C-Coins]\n");
            printf("type the amount to buy: ");
            scanf("%lf", &coinsAmount);
                coinsCheckout = coinsAmount * coinsValue;

            if(coinsCheckout > wallet){
                printf("\nsorry, you can't afford this amount of C-Coins.");
                printf("\nGo back into 'Home' and check your wallet!");
                coinsValue = coinsValue + (0.0010 * coinsCheckout);
            }

            if(coinsCheckout <= wallet){
                coins = coins + coinsAmount;
                wallet = wallet - coinsCheckout;
                LastPurchase = coinsCheckout / coinsAmount;
                printf("\n\nTransaction complete: \n[+] %.2f coins\n[-] $%.2f\n", coinsAmount, coinsCheckout);                
                coinsValue = coinsValue + (0.0010 * coinsCheckout);

                printf("\nC-Coins: %.2f\n", coins);
                printf(" Wallet: $%.2f\n", wallet);   
            }
        }

        if(shop == 'S' || shop == 's'){
            system("cls");
            printf("[Selling C-Coins]\n");
            printf("type the amount to sell: ");
            scanf("%lf", &coinsAmount);

            if(coinsAmount > coins){
                printf("\nsorry, you've not this amount of C-Coins.");
                printf("\nGo back into 'Home' and check your wallet!");
                coinsValue = coinsValue - (0.0010 * coinsCheckout);             
            }

            if(coinsAmount <= coins){
                coinsCheckout = coinsAmount * coinsValue;
                wallet = wallet + coinsCheckout;
                coins = coins - coinsAmount;
                printf("\n\nTransaction complete: \n[-] %.2f coins\n[+] $%.2f\n", coinsAmount, coinsCheckout);
                coinsValue = coinsValue - (0.0010 * coinsCheckout);

                printf("\nC-Coins: %.2f\n", coins);
                printf(" Wallet: $%.2f\n", wallet);
            }
        }
    }   

    FILE * fPointer;
    fPointer = fopen("wallet.txt", "w");
    fprintf(fPointer, "%lf", wallet);
    fclose(fPointer);

    fPointer = fopen("coins.txt", "w");
    fprintf(fPointer, "%lf", coins);
    fclose(fPointer);

    fPointer = fopen("value.txt", "w");
    fprintf(fPointer, "%lf", coinsValue);
    fclose(fPointer);

    fPointer = fopen("bank.txt", "w");
    fprintf(fPointer, "%lf", bankBalance);
    fclose(fPointer);

    fPointer = fopen("matrix.txt", "w");
    fprintf(fPointer, "%lf", matrix);
    fclose(fPointer);

    fPointer = fopen("purchase.txt", "w");
    fprintf(fPointer, "%lf", LastPurchase);
    fclose(fPointer);

        printf("\n\n\n");
    printf("\t[M] Main Menu'");
        printf("\n");
    printf("\t[/] Save and Exit");
        exit = getch();


}while(exit == 'M' || exit == 'm');

printf("\n\nYou're leaving!\nSee you next time!");

getch();
return 0;
}