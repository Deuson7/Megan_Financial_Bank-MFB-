#ifndef ACC_TYPE_1_H
#define ACC_TYPE_1_H
#include "Account.h"

class Savings_Acc : public Account {
    private:
        const double INTEREST_RATE = 2.4;
    public:
        Savings_Acc() {
            interestRate = INTEREST_RATE;
        }

        //Function to get interest-rate
        double getInterest_Rate() {
            return INTEREST_RATE;
        }

        void save(Savings_Acc& ACC);
  


};


#endif