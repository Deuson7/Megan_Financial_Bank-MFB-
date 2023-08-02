#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <iostream>
#include <limits>
#include <string>
using namespace std;

//classes for invalid user inputs
class invalid_input {
    public:
    void invalid_input_message() {
        cout << "\t\t\t\tinvalid input" << endl;

        spacer(1); // Create 1 blank lines
        
    }
};


class dataType_mismatch {
    public:
        void dataType_mismatch_message() {
            cout << "\t\t\t\tError! characters are not allowed" << endl;

            spacer(1); // Create 1 blank lines

        }
};

class invalidPassword {
    public:
        void invalidPassword_message() {
            cout << "\t\t\t\tInvalid Password!" << endl;

            spacer(1); //Create 3 blank lines
        }
};

class no_matchingName {
    public:
        void invalidName_message(string ACC_NAME) {
            cout << "\t\t\t\tNo " << ACC_NAME << " matches with the provided name!" << endl;
            
            spacer(1); // Create 1 blank lines
            
        }
};

class pin_mismatch {
    public:
        void pinMismatch() {
            cout << "\t\t\t\tThe pin doesn't match with your first pin!" << endl;

            spacer(1); // Create 1 blank lines

        }
};



////////////////////////////////////////////////////////////////////////////////////
/* The function template scanUser_input() is used to check the validity of the 
user's numeric inputs. It checks if the user's input in the required range
(valid_range_1 - valid_range_2) and is not a character and then returns an integer
as the user's input */
template<class T>
T scanUser_input(T valid_range_1 , T valid_range_2 , string INPUT_PROMPT) {
    bool proceed = false;
    int option;

    //Error handling mechanism for wrong user inputs
    cout << INPUT_PROMPT;
    while (!proceed) {
        try {
            cin >> option;

            if (cin.fail()) {
                throw dataType_mismatch();
            }

            if (option >= valid_range_1 && option <= valid_range_2) {
                proceed = true;
            }

            else {
                throw invalid_input();
            }
        } catch(invalid_input e) {
            e.invalid_input_message();
            cout << INPUT_PROMPT;
        } catch(dataType_mismatch e) {
            e.dataType_mismatch_message();
            //clear the error state flags of the input stream
            cin.clear();
            //remove all the remaining characters from the input buffer
            cin.ignore(numeric_limits<streamsize>::max() , '\n');
            cout << INPUT_PROMPT;
        }
    }

    return option;
}
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
#endif