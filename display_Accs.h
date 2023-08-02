#ifndef DISPLAY_ACCS
#define DISPLAY_ACCS
#include <fstream>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

//////////////////////////////////////////////////////////////////////
void saveAcc(string ACC_NAME , string ACC_TYPE) {
    struct AccInfo {
        char AccName[100];
        char AccType[100];
    };
    
    AccInfo info;
    
    //Copy strings to character arrays.
    strcpy(info.AccName , ACC_NAME.c_str());
    strcpy(info.AccType , ACC_TYPE.c_str());


    fstream save;
    save.open("Data\\data.bin" , ios::out | ios::app | ios::binary);
    save.write(reinterpret_cast<char *> (&info) , sizeof(info));

    save.close();
}

//////////////////////////////////////////////////////////////////////////
void dispAcc() {
    int count_accounts = 0;

    struct AccInfo {
        char AccName[100];
        char AccType[100];
    };
    
    AccInfo info;

    ifstream read_data;
    read_data.open("Data\\data.bin" , ios::in | ios::binary);
    read_data.read(reinterpret_cast<char *> (&info) , sizeof(info));

    //loop through the Available acc bin file while displaying
    //All the available accounts until the reader has reached
    //At the end of the file
    while (read_data.eof() != true ) {
        count_accounts++;
        cout << "\t\t\t\tAcc.Number: " << count_accounts << endl;
        cout << "\t\t\t\t************************************" << endl;
        cout << "\t\t\t\tACC NAME: " << info.AccName << endl;
        cout << "\t\t\t\tACC TYPE: " << info.AccType << endl; 
        cout << "\t\t\t\t************************************" << endl;
        cout << endl;

        read_data.read(reinterpret_cast<char *> (&info) , sizeof(info));
    }

    spacer(1); // Create 1 blank lines
   
    cout << "\t\t\t\tThere are currently " << count_accounts << " available account(s)";
    cout << " in the bank." << endl;
    read_data.close();

    spacer(3); // Create 3 blank lines

}
////////////////////////////////////////////////////////////////////////////







#endif