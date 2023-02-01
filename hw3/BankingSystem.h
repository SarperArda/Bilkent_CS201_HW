//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Header class for Banking System
 * @SarperArdaBakır
 * @24July2022
 */
#ifndef HW3_BANKINGSYSTEM_H
#define HW3_BANKINGSYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Customer.h"
class BankingSystem {
public: BankingSystem();
    ~BankingSystem();
    void addCustomer( const int customerId ,const string firstName , const string lastName );
    void deleteCustomer( const int customerId );
    int addAccount( const int customerId, const double amount );
    void deleteAccount( const int accountId );
    void showAllAccounts();
    void showAllCustomers();
    void showCustomer( const int customerId );
private:
    struct CustNode{
        Customer* cust;
        CustNode* next;
    };
    CustNode* headCust;
    int custNum;
    int accID;
};

#endif //HW3_BANKINGSYSTEM_H
