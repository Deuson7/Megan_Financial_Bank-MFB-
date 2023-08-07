#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H
#include "AccType_1.h"
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
using namespace std;

///////////////////////////////////////////////////////////////////
/* This function creates a specified number of spaces */
void spacer(int NUM_OF_SPACES) {
    for (int x = 0; x < NUM_OF_SPACES; x++) {
        std::cout << std::endl;
    }
}
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
/* This function creates a specified number of tabs */
std::string tabs(std::string TAB , int NUM_OF_TABS) {
    std::string tab;
    for (int x = 0; x < NUM_OF_TABS; x++) {
        tab += TAB;
    }
    return tab;
}

//////////////////////Bank Statement Functions///////////////////////
/* bank_Statement() & return_B_statement() are responsible for the
recording transaction details and retriving their details whenever needed */
void bank_Statement(long double DEPOSIT, long double WITHDRAW, long double LOAN, string NAME, long double BAL) {
    fstream file;
    string fileName = ("\\" + NAME + ".bin");
    file.open("Data\\Statement files\\" + fileName , ios::out | ios::app);
    
    struct statement {
        long double deposit;
        long double withdraw;
        long double loan;
        long double balance;

        char date_time[50];
    };

    statement user_statements;
    user_statements.deposit = DEPOSIT;
    user_statements.withdraw = WITHDRAW;
    user_statements.loan = LOAN;
    user_statements.balance = BAL;

    //Recording the current date_time and storing it into a variable
    chrono::system_clock::time_point NOW = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(NOW);

    char dt[50];
    strftime(dt, sizeof(dt), "DATE: %d-%m-%Y TIME: %H:%M:%S", localtime(&currentTime));
    //Copy the current time and date to date_time variable
    strcpy(user_statements.date_time , dt);
    //Store the data into a bin file
    file.write(reinterpret_cast<char*>(&user_statements) , sizeof(user_statements));

    file.close();
}

void return_B_statement(string ACC_NAME , string ACC_TYPE , int ACC_No) {
    string fileName = ("\\" + ACC_NAME + ".bin");

    struct statement {
        long double deposit;
        long double withdraw;
        long double loan;
        long double balance;

        char date_time[50];
    };

    
    spacer(5); //Create 5 blank spaces
    cout << "\t\t\t\tMEGAN FINANCIAL BANK(MFB)" << endl;
    spacer(2); //Create 2 blank spaces
    cout << "\t\t\t\t=====ACCOUNT INFO=====" << endl;
    cout << endl;
    cout << "\t\t\t\tAcc. Name: " << ACC_NAME << endl;
    cout << "\t\t\t\tAcc. Type: " << ACC_TYPE << endl;
    cout << "\t\t\t\tAcc. Number: " << ACC_No << endl;
    spacer(4);
    //Create a structure instance called my
    statement my;

    fstream file;
    file.open("Data\\Statement files\\" + fileName , ios::in);
    file.read(reinterpret_cast<char*>(&my) , sizeof(my));


    cout << "\t\t\t\tTRANSACTION DETAILS(MFB STATEMENTS)" << endl;
    //loop through the file
    while(!file.eof()) {

        cout << endl;
        cout << "\t\t\t\t" << my.date_time << ", DEPOSIT: Shs." << my.deposit;
        cout << ", WITHDRAWAL: Shs." << my.withdraw << ", LOAN: Shs." << my.loan;
        cout << ", ACC.BALANCE Shs." << my.balance << endl;
        cout << endl;

        file.read(reinterpret_cast<char*>(&my) , sizeof(my));
    }


    
}

#endif