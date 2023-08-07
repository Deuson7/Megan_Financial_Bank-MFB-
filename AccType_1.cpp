#include "AccType_1.h"
#include <fstream>


//Implementing the save function
void Savings_Acc::save(Savings_Acc& ACC) {
    fstream saveAcc;
    saveAcc.open("Data\\data file_1.bin", ios::out | ios::app | ios::binary);
    saveAcc.write(reinterpret_cast<char*> (&ACC) , sizeof(ACC));
    saveAcc.close();
}
