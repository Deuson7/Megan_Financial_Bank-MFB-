#ifndef LOBBY_H
#define LOBBY_H
#include "OtherFunctions.h"
#include <iostream>
#include <string>
#include <limits>
#include "Exceptions.h"
#include <stdlib.h>
using namespace std;

////////////////////////////////////////////////////////////////
////////////////////MAIN LOBBY FUNCTION/////////////////////////
////////////////////////////////////////////////////////////////
int lobby_0() {
    bool pass = false;
    int option;
    
    spacer(3); //Create 3 blank spaces

    cout << "\t\t\t\t---------------";
    cout << "MEGAN FINANCIAL BANK(MFB)";
    cout << "---------------" << endl;
    spacer(4); //Create 2 blank lines
    cout << "\t1)     Create An Account" << endl;
    cout << "\t2)     Access Your Account" << endl;
    cout << "\t3)     Display Available Accounts" << endl;
    cout << endl;
    cout << "\t0)     Exit Program" << endl;

    spacer(3); //Create 3 blank lines

    option = scanUser_input(0 , 3 , "\tOPTION >> ");

    if (option == 0) {
        exit(0);
    } 
    return option;
}
/////////////////////////////////////////////////////////////




////////////////////////////////////////////////////////////
//////////////////////ACC CREATION LOBBY////////////////////
int lobby_1() {
    int option;

    spacer(2); //Create 2 blank lines

    cout <<"\t\t\t\t*CREATE A NEW MFB BANK ACCOUNT*" << endl;
    cout << "\t\t\t\t--------------------------------" << endl;
    spacer(1); //Create 1 blank lines
    cout << "\t\t\t\t1........Create savings account" << endl;
    cout << "\t\t\t\t0........Exit Program" << endl;
   
    spacer(1); //Create 3 blank lines

    option = scanUser_input(0 , 1 , "\t\t\t\tOPTION >> ");
    cin.ignore();
   
    if (option == 0) {
        exit(0);
    }
   
    
    return option;
   
}
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//////////////////////ACC ACCESS LOBBY//////////////////////
int lobby_2() {
    int option;

    spacer(2); //Create 2 blank lines

    cout <<"\t\t\t\t*ACCESS AN MFB BANK ACCOUNT*" << endl;
    cout << "\t\t\t\t----------------------------" << endl;
    spacer(1); //Create 1 blank line
    cout << "\t\t\t\t1........Savings Account" << endl;
    cout << "\t\t\t\t0........Exit Program" << endl;
   
    spacer(1); //Create 3 blank lines

    option = scanUser_input(0 , 1 , "\t\t\t\tOPTION >> ");
    cin.ignore();
   
    if (option == 0) {
        exit(0);
    }
   
    return option;
   
}







#endif