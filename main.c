#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>


void displayMenu();
int playroulet(int amount);
int roller();

// ill fix some text formatting issues and polish others(done?)
// ill add true last rolls (later)
// might add true spinning wheel with so-called animation (done)
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
    int money=1923;
    int transaction=0;
    char enter[2];
    while (choice !=0) {
        system("cls");

        printf("     >>>>> Roul.exe <<<<<\nType what you want to do\n-----------------------------\n");
        printf("1) Play Roulette\n2) Access Your RoulWallet\n0) Quit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            money = playroulet(money);
        }
        else if(choice ==2)
        {
            while(choice !=9) {
                system("cls");//windows specific function used in here!
                printf(">>>>> Roul.exe <<<<<\n1)Deposit\n2)Withdraw\n3)Past Transactions\n9)Back\n");
                printf("You've: $%d in your RoulWallet\n", money);



                scanf("%d", &choice);
                system("cls");
                printf("You've: $%d in your RoulWallet\n", money);
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
                        printf("$%d\n",pastactions[i]);
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
    char red[4]="RED";char black[6]="BLACK";char green[6]="GREEN";
    int result;
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
        printf("please enter your bet amount\n$");
        scanf("%d",&betamount);}
    else if(color == 2)
    { printf("your choice is red\n");
        printf("please enter your bet amount\n$");
        scanf("%d",&betamount);}
    else if(color == 3)
    { printf("your choice is green\n");
        printf("please enter your bet amount\n$");
        scanf("%d",&betamount);}
    else if(color ==4)
    { printf("you're heading back to choosing color menu\n");
        }
    if (color != 4)
    {
        money = money - betamount;
        roll = roller();
        if (roll==0)
        {
            result = 3;
            if(color==3)
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
                    result = 1;
                }
                else
                {
                    printf("you lose!\n");
                    result = 2;
                }
            }

            else{
                if (roll % 2 ==0)
                {
                    printf("congrats you hit red!\n");
                    money= money +(betamount *2);
                    result = 2;
                }
                else
                {
                    printf("you lose!\n");
                    result = 1;
                }
            }
        }
        if (result ==1)
        {printf("ROLL WAS: %s\n",black);}
        else if(result==2)
        {printf("ROLL WAS: %s\n",red);}
        else if(result==3)
        { printf("ROLL WAS: %s\n",green);}

        printf("your current money is: $%d\n",money);
        printf("press enter to continue...");
        fflush(stdin);


        fgets(enter,2,stdin);
    }

    return money;







}

int roller()
{
    int flag=0;
    int wheel[38]={0,1,2,36,3,35,4,
                   34,5,33,6,32,7,31,8,30,9,29,10,28,11,27
    ,12,26,13,25,14,24,15,23,16,22,17,21,18,20,19,0};
    system("cls");
    int answer= (rand() % 37) + 37;

    while (0 < answer/37) {
        for (int i = 0; i <= 35; ++i) {
            printf("      >>>> |Rollin| <<<<");
            printf("\n      |----------------|");
            printf("\n      | %3d < %2d > %2d  |", wheel[i], wheel[i + 1], wheel[i + 2]);
            printf("\n      |----------------|");
            Sleep(130);
            system("cls");
        }

        answer -= 37;
    }

    for (int i = 0; i <= answer - 1; ++i) {
        printf("      >>>> |Rollin| <<<<");
        printf("\n      |----------------|");
        printf("\n      | %3d < %2d > %2d  |", wheel[i], wheel[i + 1], wheel[i + 2]);
        printf("\n      |----------------|");
        Sleep(220);
        system("cls");
    }

    return answer;
}


