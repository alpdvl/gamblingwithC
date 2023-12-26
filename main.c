#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void displayMenu();
int playroulet(int amount);
int roller();

// ill fix some text formatting issues and polish others
// ill add true last rolls
// might add true spinning wheel with so-called animation
// might add account/login system





int main() {

    printf("Hello, World!\n");
    srand(time(NULL)); // seeding rand func with time
    displayMenu();


    return 0;
}


void displayMenu()
{
    int transcount=-1;
    int pastactions[100]={0};
    int choice=1;
    int money=3210;
    int transaction=0;
    char enter[2];
    while (choice !=0) {
        system("cls");

        printf("type what you want to do_\n");
        printf("1)roulett.\n2)banking\n0)Quit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            money = playroulet(money);
        }
        else if(choice ==2)
        {
            while(choice !=9) {
                system("cls");//windows specific function used in here!
                printf("type what you want to do...\n1)Deposit\n2)Withdraw\n3)Past Transactions\n9)Back\n");
                printf("You've: %d$ in your RoulWallet\n", money);



                scanf("%d", &choice);
                system("cls");
                printf("You've: %d$ in your RoulWallet\n", money);
                if (choice == 1) {
                    printf("type the amount which you want to deposit:\n");
                    scanf("%d",&transaction);

                    if (transaction >0)
                    {
                        printf("transaction was succesful!\n");
                        money = money + transaction;
                        pastactions[transcount+1]= transaction;
                        transcount += 1;
                        printf("press enter to continue...");
                        fflush(stdin);
                        fgets(enter,2,stdin);
                        if(enter[0]=='\n')
                        { }
                    }
                    else
                    {
                        printf("there was a mistake pls try again\n");
                        printf("press enter to continue...");
                        fflush(stdin);
                        fgets(enter,2,stdin);
                        if(enter[0]=='\n')
                        { }
                    }

                } else if (choice == 2) {
                    printf("type the amount which you want to withdraw:\n");
                    scanf("%d",&transaction);

                    if (transaction <= money)
                    {
                        printf("transaction was succesful!\n");
                        money = money - transaction;
                        pastactions[transcount+1]= -transaction;
                        transcount += 1;
                        printf("press enter to continue...");
                        fflush(stdin);
                        fgets(enter,2,stdin);
                        if(enter[0]=='\n')
                        { }
                    }
                    else
                    {
                        printf("there was a mistake pls try again\n");
                        printf("press enter to continue...");
                        fflush(stdin);
                        fgets(enter,2,stdin);
                        if(enter[0]=='\n')
                        { }
                    }

                } else if (choice == 3) {
                    system("cls");
                    printf("past transactions..\n");
                    int i=0;


                    while (pastactions[i]!= 0)
                    {
                        printf("%d$\n",pastactions[i]);
                        i = i + 1;



                    }
                    printf("press enter to continue...");
                    fflush(stdin);
                    fgets(enter,2,stdin);
                    if(enter[0]=='\n')
                    { }
                } else if (choice == 9) {
                    // gate for back
                } else {
                    printf("enter something proper pls\n");
                }
            }

        }
    }

}

int playroulet(int amount)
{
    char enter[2];
    int roll;
    int color;
    int betamount=0;
    int money = amount;
    system("cls");
    printf("last rolls were: 5(b) 12(r) 17(b) 28(r) 31(b)\n"); // ill fix this later
    printf("you're playing roulette please enter your bet color\n"
           "\n1)Black\n2)Red\n3)Green\n4)Cancel the action...");
    scanf("%d",&color);
    if(color==1)
    { printf("your choice is Black\n");
        printf("please enter your bet amount\n");
        scanf("%d",&betamount);}
    else if(color == 2)
    { printf("your choice is red\n");
        printf("please enter your bet amount\n");
        scanf("%d",&betamount);}
    else if(color == 3)
    { printf("your choice is green\n");
        printf("please enter your bet amount\n");
        scanf("%d",&betamount);}
    else if(color ==4)
    { printf("you're heading back to choosing color menu\n");
        }
    money = money - betamount;
    roll = roller();
    if (roll==0)
    {
        if(color==0)
        {
            printf("congrats you hit the green!\n");
            money= money + (betamount *14);

        }
        else  { printf("you missed the green fortune...");}
    }
    else {
        if (color == 1) {
            if (roll % 2 == 1)
            {
                printf("congrats you hit black!\n");
                money= money + (betamount * 2);
            }
            else
            {
                printf("you lose!\n");
            }
        }

        else{
            if (roll % 2 ==0)
            {
                printf("congrats you hit red!\n");
                money= money +(betamount *2);
            }
            else
            {
                printf("you lose!\n");
            }
        }
    }

    printf("your current money is: %d\n",money);
    printf("press enter to continue...");
    fflush(stdin);
    fgets(enter,2,stdin);
    return money;







}

int roller()
{
    int answer= rand() % 37;
    return answer;
}


