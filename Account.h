#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;


//Defining The Account Interface
class Account {
    private:
        char pin[100];
    protected:
        char accountName[100];
        long double accBalance = 0.00;
        double interestRate;
        int countDeposits = 0;
        long double loan = 0.00;
    public:

        //The withdraw & deposit functions
        void withdraw(long double AMOUNT);
        void deposit(long double AMOUNT);

        //An inline function for setting an account pin
        void setPin(string PIN) {    
            strcpy(pin , PIN.c_str());
        }
        const char* getPin() const {
            return pin;
        }
        //An inline function for setting an account name
        void setName(string NAME) {
            strcpy(accountName , NAME.c_str());
        }

        const char* getName() {
            return accountName;
        }

        //An inline function for displaying the acc balance
        long double getBalance() const {
            return accBalance;
        }

        //loaning functions;
        void setLoan(long double LOAN);

        void resetLoan() {
            loan = 0.00;
        }

        long double getLoan() const {
            return loan;
        }

        void payLOAN(long double PAYMENT);

        void addCountDeposits() {
            countDeposits++;
        }
        ////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////
        void dispSUMMARY() {
            cout << "\t\t\t\tAccount Name: " << getName() << endl;
            cout << "\t\t\t\tAccount Pin: " << getPin() << endl;
            cout << "\t\t\t\tAccount Balance: Ugx " << getBalance() << endl;
            cout << "\t\t\t\tOutstanding Loan: Ugx -" << getLoan() << endl;
        }
 
};

//Exception Classes
class InsufficientBalance {
    public:
        void notify() {
            cout << "\t\t\t\t\t\t   Dear Customer, you have an insufficient balance." << endl;
            cout << endl;
        }
};

class payLoan {
    public:
        void notify() {
            cout << "\t\t\t\t\t\t   Dear Customer, please first pay the outstanding loan" << endl;
            cout << endl;
        }
};

class loanUneligible {
    public:
        void notify() {
            cout << "\t\t\t\t\t\t   Dear Customer, deposit atleast 4 times in order to ";
            cout << "qualify for a loan"  << endl;
            cout << endl;
        }
};


#endif








