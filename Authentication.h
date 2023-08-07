#ifndef AUTHENTICATION
#define AUTHENTICATION
#include <fstream>
#include "AccType_1.h"
#include "Exceptions.h"
#include <cstring>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

bool MATCH = false;

//multiple
/////////////////////////////////////////////////////////////////
///////////////PASSWORD SCANNER FOR SAVINGS ACCOUNT//////////////
/////////////////////////////////////////////////////////////////
bool password_Scanner(Savings_Acc& Acc) {
    int count = 3;
    bool found = false;
    bool invalid = false;

    string providedPin;
    
    //Prompt user for password
    cout << "\t\t\t\tPlease Enter Your Account Pin: ";

    while (!found) {
        try {
            cin >> providedPin;
            if (providedPin == Acc.getPin()) {
                found = true;
            }
            else {
                throw invalidPassword();
            }
        } catch(invalidPassword e) {
            count--;
            if (count == 0) {

                spacer(3); // Create 3 blank lines

                cout << "\t\t\t\t\t     !ACCESS DENIED!" << endl;

                spacer(3); // Create 3 blank lines

                //Terminate program
                exit(0);
            }
            e.invalidPassword_message();
            cout << "\t\t\t\tEnter Correct Account pin(";
            cout << count << " attempts): ";
        }
    }

    return found;
}

//multiple
long int byteNum(Savings_Acc& Acc , int fileNum) {
    return sizeof(Acc) * fileNum;
}

//multiple
int searching_sys(Savings_Acc& Acc , string ACC_NAME) {
    bool& MATCH_ref = MATCH;
    int fileIndex = 0;

    fstream search;
    search.open("Data\\data file_1.bin" , ios::in | ios::binary);
    search.read(reinterpret_cast<char*> (&Acc) , sizeof(Acc));
   
    while (search.eof() != true) {
        if (ACC_NAME == Acc.getName()) {
            MATCH_ref = true;
            break;
        }
        fileIndex++;
        search.read(reinterpret_cast<char*> (&Acc) , sizeof(Acc));
        
    }

    if (MATCH_ref == false) {
        throw no_matchingName();
    }
    

    return fileIndex;
}

/////////////////////////////////////////////////////////////////////
///////////////////////Pin Confirmation function/////////////////////
bool pin_Verification(string PIN_1 , string PIN_2) {
    int attempts = 3;

    bool matching_pin = false;
    string& PIN_2_ref = PIN_2;

    while(!matching_pin) {
        try {
            if (PIN_1 == PIN_2) {
                matching_pin = true;
            }
            else {
                throw pin_mismatch();
            }
        } catch (pin_mismatch e) {
            e.pinMismatch();
            attempts--;
            if (attempts == 0) {
                cout << "\t\t\t\t\t     !YOUR ACCOUNT CREATION HAS BEEN TERMINATED!" << endl;
                exit(0);
            }
            cout << "\t\t\t\tTry again(" << attempts << " attempt(s))\n";
            cout << "\t\t\t\t>> ";
            getline(cin , PIN_2_ref);
        }
    }

    return matching_pin;
}


#endif