//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Header class for Account
 * @SarperArdaBakır
 * @24July2022
 */
#ifndef HW3_ACCOUNT_H
#define HW3_ACCOUNT_H
class Account{
public:
    Account(int nId, double nAmount);
    int getId();
    double getAmount();
    void show();
private:
    double amount;
    int id;
};
#endif //HW3_ACCOUNT_H
