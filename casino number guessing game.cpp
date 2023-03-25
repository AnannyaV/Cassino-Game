#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

void rules();
int main()
{
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    srand(time(0));
    cout<<"\n\t\t =======WELCOME TO CASINO WORLD=======\n\n"; 
    cout<<"\n\n what's your Name : ";
    getline(cin,playerName);
    cout<<"\n Enter the starting balance to play game : $ ";
    cin>>balance;
    do
    {
        
        rules();
        cout<<"\n\n Your current balance is $ "<<balance<<"\n";
        do
        {
           cout<<"Hey!, "<<playerName<<", enter amount to bet : $";
           cin>>bettingAmount;
           if(bettingAmount>balance)
                cout<<"Betting balance can't be more than current balance\n"<<"\n Re-enter balance\n";
        } while (bettingAmount>balance);
        

        do
        {
            cout<<"\n Guess any betting number between 1 to 10 :";
            cin>>guess;
            if(guess <=0 || guess >10)
                cout<<"\n Number should be between 1 to 10\n"<<"Re-enter Number:\n";
        } while (guess<=0 || guess>10);
        dice = rand()%10 +1;
        if(dice == guess)
        {
            cout<<"\n\n You are in luck!! You have won Rs."<< bettingAmount*10;
            balance = balance + bettingAmount*10;
        }
        else
        {
            cout<<"Oops, better luck next time !! You lost $"<<bettingAmount<<"\n";
            balance = balance - bettingAmount;
        }
        cout<<"\n The winning  number was:"<<dice<<"\n";
        cout<<"\n"<<playerName<<", You have balance of $"<<balance<<"\n";
        if(balance == 0)
        {
            cout<<" You have no money to play";
            break;
        }
        cout<<"\n\n-->Do you want to play again (y/n)?";
        cin>>choice;
    } while (choice == 'Y' || choice == 'y');

    cout<<"\n\n\n";
    cout<< "\n\n Thanks for playing the game. Your balance is $"<<balance<<"\n\n";

    
    return 0;
}

void rules()
{
    
    cout<<"\t\t ========CASINO NUMBER GUESSING RULES!!========\n";
    cout<<"\t1. Choose a number between 1 to 10\n";
    cout<<"\t2. Winner get 10 times of the money bet\n";
    cout<<"\t3. Wrong bet, and you will lose the amount you bet\n";
}