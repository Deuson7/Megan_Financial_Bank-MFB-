#ifndef OTHERFUNCTIONS_H
#define OTHERFUNCTIONS_H
#include "AccType_1.h"
#include <iostream>
#include <string>
#include <thread>


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

    ///////////////////////////Threaded Function/////////////////////////
    /////////////////////////////////////////////////////////////////////
    /* The Interest-Rate function */
    /*
    void interestRATE(Savings_Acc& ACC) {
        long double interest = 0;
        for (int count = 0; count < 10000; count++) {

            //Calculate the interest
            interest = (ACC.getBalance()
                        + ((ACC.getBalance() * ACC.getInterest_Rate()) / 100 ));

            //Deposit the interest to a savings account
            ACC.deposit(interest);

            //Simulate months by sleeping the thread for 4 seconds
            this_thread::sleep_for(chrono::seconds(4));
        }
        
    }
    */

#endif