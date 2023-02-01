//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Header class for Customer
 * @SarperArdaBakır
 * @24July2022
 */
#ifndef HW3_CUSTOMER_H
#define HW3_CUSTOMER_H
#include "Account.h"
using namespace std;
#include <string>
#include <iomanip>
class Customer{
public:
    Customer(int id, string fName, string lName);
    ~Customer();
    //Customer(const Customer& c);
    void addAccount(int id, double amount);
    bool deleteAccount(int id);
    void deleteAllAccounts();
    int checkCustomer(const int id, const string firstName , const string lastName);
    void showAccounts();
    void showCustomer();
    const int getId() const;
    const string &getFName() const;
    const string &getLName() const;

private:
    int id;
    string fName;
    string lName;
    int accCount;
    struct AccNode{
        Account* acc;
        AccNode* next;
    };
    AccNode* headAcc;

};
#endif //HW3_CUSTOMER_H
