#ifndef CREATE_ACCOUNTS_H
#define CREATE_ACCOUNTS_H
#include "AccType_1.h"
#include "OtherFunctions.h"
#include "display_Accs.h"
#include "Exceptions.h"
#include "Authentication.h"
#include <iostream>
using namespace std;

//multiple
//A function for creating a savings account
/////////////////////////////////////////////////////
void create_SavingsAcc(Savings_Acc& ACCOUNT) {
    bool confirmation;
    string name;
    string pin_1;
    string pin_2;
    long double init_deposit;

    spacer(4); //Create 4 blank spaces

    cout << tabs("\t" , 4 ) << "Enter Account Name(Your Name)" << endl;
    cout << tabs("\t" , 4 ) << ">> ";
    getline(cin , name);
    ACCOUNT.setName(name);

    spacer(1); //Create 1 blank space

    cout << tabs("\t" , 4 ) << "Set Your Account Pin" << endl;
    cout << tabs("\t" , 4) << "Tip: Make sure you can easily remember it" << endl;
    cout << tabs("\t" , 4 ) << ">> ";
    getline(cin , pin_1);
    
    spacer(1); //Create 1 blank space

    cout << tabs("\t" , 4) << "Confirm Your Pin(Re-enter Pin)" << endl;
    cout << tabs("\t" , 4 ) << ">> ";
    getline(cin , pin_2);

    //Password Confirmation function
    confirmation = pin_Verification(pin_1 , pin_2);

    if(confirmation) {
        ACCOUNT.setPin(pin_1);
    }

    spacer(1); //Create 1 blank space

    cout << "\t\t\t\tWould You Want To Make An Initial Deposit" << endl;
    cout << "\t\t\t\t1) Yes" << endl;
    cout << "\t\t\t\t2) No" << endl;

    spacer(1); //Create 1 blank space 

    int choice;
    choice = scanUser_input(1 , 2 , "\t\t\t\tOPTION >> ");

    if (choice == 1) {
        spacer(1); //Create 1 blank space 
        init_deposit = scanUser_input(1.0 , 1000000000000.0 , "\t\t\t\tEnter Amount: ");
        
        ACCOUNT.deposit(init_deposit);

    }

    ACCOUNT.save(ACCOUNT);
    saveAcc(name , "Savings Account");
}





#endif