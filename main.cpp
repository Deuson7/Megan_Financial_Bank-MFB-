//Created by Muhumuza Deus Mugenyi, muhumuzadeus7@gmail.com
#include <iostream>
#include <iomanip>
#include <limits>
#include "Account.h"
#include "AccType_1.h"
#include "Create_Accounts.h"
#include "Authentication.h"
#include "Lobbys.h"
#include "Access.h"
#include "OtherFunctions.h"
using namespace std;

//A Console Application

/* NOTE: Functions and Classes below the label "multiple" 
indicate that the same function is to be re-written to facilitate
that function's functionality for a different type of bank account
through tiny modifications(such as function name , prompt strings etc ) 
on the duplicated function to match the bank account type's functionality*/

int main() {
    ////////Important variables
    ///////////////////////////
    int trials = 3;
    string user_pin;
    bool found = false;
    bool ACCESS = false;
    int option;
    ///////////////////////////
    cout << setprecision(2) << fixed << showpoint << endl;
    ///////////////////////////

    option = lobby_0();

    switch (option) {
        case 1:
            cout << endl;
            int option_newAcc;
            option_newAcc = lobby_1();

            if (option_newAcc == 1) {
                Savings_Acc newAcc;
                create_SavingsAcc(newAcc);
            }
            break;
        
        case 2:
            int option;
            option = lobby_2();
            if (option == 1) {
                fstream accData;
                //Open the data file_1.bin file in binary and input mode
                accData.open("Data\\data file_1.bin" , ios::in | ios::binary);

                //Stores the position of the matching account
                int acc_position;

                Savings_Acc myaccount; //Create a Savings_Acc object
                string acc_Name; //store provided account name

                spacer(1); //Create 3 blank lines

                cout << "\t\t\t\tEnter Your Savings Account Name(";
                cout << trials << " attempts)" << endl;
                cout << "\t\t\t\tTip: It should exactly match with the set";
                cout << " acc. name during your acc. creation" << endl; 
                cout << "\t\t\t\t>> ";
                //Expect no matching account name exception
                //to be thrown in some cases
                int num = 0;
                while (!found) {
                    try {
                        getline(cin , acc_Name);
                        num = searching_sys(myaccount , acc_Name); 
                        acc_position = byteNum(myaccount , num);

                        found = true;
                    } catch(no_matchingName e) {
                        int& trial_ref = trials;
                        trial_ref--;
                        if (trial_ref == 0) {
                            cout << "\t\t\t\t\t     !ACCESS DENIED!" << endl;
                            //Terminate program
                            exit(0);
                        }
                        e.invalidName_message("savings account");

                        spacer(1); //Create 3 blank lines
                        
                        cout << "\t\t\t\tTry Again(" << trial_ref << " attempts)" << endl;
                        cout << "\t\t\t\t>> ";
                    }
                }
                //Jump to the specific set of data in the binary file which
                //matches the account name
                accData.seekg(acc_position , ios::beg);
                //Read the contents of in that data
                accData.read(reinterpret_cast<char*> (&myaccount) , sizeof(myaccount));

                spacer(1); //Create 3 blank lines

                ACCESS = password_Scanner(myaccount);

                //Access Personal Account Information
                if (ACCESS) {
                    /////////////////////////////
                    S_Account(acc_position , num);
                    /////////////////////////////
                }
                accData.close();
         
            }

            break;

        case 3:
            cout << endl;
            dispAcc();
            break;
            
    }

    
    return 0;
}













//Created by Muhumuza Deus Mugenyi, muhumuzadeus7@gmail.com