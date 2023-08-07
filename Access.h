#ifndef ACCESS_H
#define ACCESS_H
#include "AccType_1.h"
#include "Exceptions.h"
#include "AccType_1.h"
#include "stdlib.h"
#include "OtherFunctions.h"
#include <limits>
#include <iostream>
#include <fstream>
using namespace std;


///////////////////////SAVINGS ACCESS FUNCTION////////////////////
//////////////////////////////////////////////////////////////////
/* Once account acccess has been granted(After user-name & pin input)
this function displays an account's lobby, and account number.
It also displays some of the actions that can be performed on an account(such
as deposit, withdraw, loan and so on) and each option can be selected 
through the use of a switch statement which switches between different options*/
void S_Account(int fileIndex , int num) {
    Savings_Acc temp_acc;
    Savings_Acc& temp_acc_ref = temp_acc;

    fstream update;
    update.open("Data\\data file_1.bin" , ios::out | ios::in | ios::binary);
    update.seekg(fileIndex , ios::beg);
    update.read(reinterpret_cast<char*> (&temp_acc) , sizeof(temp_acc));


    int choice;
    string new_pin;
    long double deposit_amount;
    long double withdraw_amount;
    long double debt_amount;
    long double pay_amount;

   spacer(10);// Create 6 blank spaces

    cout << "----------------------------------------";
    cout << "--------------------" << (num + 1) << "-------------------";
    cout << "----------------------------------------" << endl;
    cout << "\t\t\t\t/////////////////////";
    cout << "SAVINGS ACCOUNT";
    cout << "/////////////////////" << endl;
    temp_acc.dispSUMMARY();
    cout << "\t\t\t\t///////////////////////////";
    cout << "//////////////////////////////" << endl;

    cout << endl;
    cout << "\t\t\t\t\t\t   Account Options" << endl;
    cout << "\t\t\t\t\t\t   ________________" << endl;

    spacer(1); //Create 1 blank space

    cout << "\t\t\t\t\t\t   1---------Make Deposit" << endl;
    cout << "\t\t\t\t\t\t   2---------Make Withdraw" << endl;
    cout << "\t\t\t\t\t\t   3---------Take A Loan" << endl;
    cout << "\t\t\t\t\t\t   4---------Pay Loan" << endl;
    cout << "\t\t\t\t\t\t   5---------Change Pin" << endl;
    cout << "\t\t\t\t\t\t   6---------My Bank Statement" << endl;

    cout << endl;
    cout << "\t\t\t\t\t\t   0------Exit" << endl;
    cout << endl;
    choice = scanUser_input(0 , 6 , "\t\t\t\t\t\t   OPTION >> ");

    switch (choice) {
        case 0:
            exit(0);
            break;
        case 1:

            spacer(1); //Create 1 blank spaces

            cout << "\t\t\t\t\t\t   Enter Amount Of Deposit: ";
            cin >> deposit_amount;
            temp_acc.deposit(deposit_amount);
            //Function to count the number of deposits made.
            temp_acc.addCountDeposits();

            spacer(3); //Create 3 blank spaces

            cout << "\t\t\t\t\t\t   You have deposited Shs." << deposit_amount << " to your account" << endl;
            break;
        case 2:

            spacer(1); //Create 1 blank spaces

            cout << "\t\t\t\t\t\t   Enter Amount You Want To Withdraw: ";
            cin >> withdraw_amount;
            temp_acc.withdraw(withdraw_amount);

            spacer(4); // Create 4 blank lines
            
            cout << "\t\t\t\t\t\t   Dear " << temp_acc.getName();
            cout << " you have withdrawn Shs." << withdraw_amount << endl;
            cout << "\t\t\t\t\t\t   Your total balance is now Shs." << temp_acc.getBalance() << endl;
            break;
        case 3:

            spacer(1); //Create 1 blank spaces
        
            cout << "\t\t\t\t\t\t   Enter Amount Of Debt: ";
            cin >> debt_amount;
            temp_acc.setLoan(debt_amount);
            
            spacer(3); //Create 3 blank spaces

            cout << "\t\t\t\t\t\t   You have been credited Shs." << temp_acc.getLoan() << endl;
            break;
        case 4:
            //Loan payment

            spacer(1); //Create 1 blank spaces

            cout << "\t\t\t\t\t\t   Enter Amount To Be Cleared From Your Outstanding Debt: ";
            cin >> pay_amount;
            temp_acc.payLOAN(pay_amount);
            
            spacer(3); //Create 3 blank spac3es

            if (pay_amount > temp_acc.getLoan()) {
                cout << "\t\t\t\t\t\t   You have payed Ugx." << temp_acc.getLoan() << endl;
                temp_acc.resetLoan();
            }
            else {
                cout << "\t\t\t\t\t\t   You have payed Ugx." << debt_amount << endl;
            }
            cout << "\t\t\t\t\t\t   Your current debt is Shs.-" << temp_acc.getLoan() << endl;
            cout << "\t\t\t\t\t\t   Your current account balance is Shs." << temp_acc.getBalance() << endl; 
            break;
        case 5:

            spacer(1); //Create 1 blank spaces
            
            cout << "\t\t\t\t\t\t   Enter New Pin: ";
            cin >> new_pin;
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            temp_acc.setPin(new_pin);
            break;
        case 6:
            return_B_statement(temp_acc.getName() , "Savings account" , (num + 1));
            break;
    }

    bank_Statement(deposit_amount , withdraw_amount , debt_amount , temp_acc.getName() , temp_acc.getBalance());

    update.seekg(fileIndex , ios::beg);
    update.write(reinterpret_cast<char*> (&temp_acc) , sizeof(temp_acc));

    //Close the output buffer
    update.close();
}



#endif