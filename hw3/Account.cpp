//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Source code for Account
 * @SarperArdaBakır
 * @24July2022
 */
#include "Account.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor
Account::Account(int nId, double nAmount) {
    id = nId;
    amount = nAmount;
}
//getter methods
double Account::getAmount() {
    return amount;
}
int Account::getId() {
    return id;
}
//toString method
void Account::show() {
    cout<< left << setw(15) << getId() << getAmount() << endl;
}