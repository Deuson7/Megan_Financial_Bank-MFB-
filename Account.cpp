#include "Account.h"
#include <stdlib.h>
#include <iostream>

//The Withdrawing Mechanism
void Account::withdraw(long double AMOUNT) {
    long double& accBalance_ref = accBalance;
    try {
        if (AMOUNT < accBalance ) {
            accBalance_ref = accBalance_ref - AMOUNT;
        }
        else {
            throw InsufficientBalance();
        }
    } catch(InsufficientBalance e) {
        e.notify();
    }
}

void Account::deposit(long double AMOUNT) {
    accBalance += AMOUNT;
}

void Account::setLoan(long double LOAN) {
    long double& accBalance_ref = accBalance;
    try {
        if (countDeposits > 3 && loan == 0) {
            loan = LOAN;
            accBalance_ref += LOAN;
        }
        else if (loan > 0){
            throw payLoan();
        }
        else if (countDeposits < 4) {
            throw loanUneligible();
        }
    } catch(payLoan e) {
        e.notify();
        exit(0);
    } catch(loanUneligible e) {
        e.notify();
        exit(0);
    }
}

void Account::payLOAN(long double PAYMENT) {
    try {
        if (PAYMENT < accBalance) {
            if (PAYMENT > loan) {
                accBalance = accBalance - loan;
            }
            else {
                accBalance = accBalance - PAYMENT;
                loan = loan - PAYMENT;
            }
        }
        
        else {
            throw InsufficientBalance();
        }
    } catch(InsufficientBalance e) {
        e.notify();
        exit(0); 
    }
}



