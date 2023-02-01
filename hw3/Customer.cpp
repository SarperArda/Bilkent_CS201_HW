//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Source code for Customer
 * @SarperArdaBakır
 * @24July2022
 */
#include "Customer.h"
#include <iostream>
using namespace std;
//Constructor
Customer::Customer(int ID, string firstName, string lastName){
    fName = firstName;
    lName = lastName;
    id = ID;
    accCount = 0;
    headAcc = NULL;

}
//Destructor
Customer::~Customer(){
    AccNode* curr = headAcc;
    while(curr){
        AccNode* temp = curr;
        curr = curr->next;
        delete temp;
        headAcc = curr;
    }
}
//getter methods
const int Customer::getId() const {
    return id;
}

const string &Customer::getFName() const {
    return fName;
}

const string &Customer::getLName() const {
    return lName;
}
/**
 * This method adds Account to Customer
 * @param id
 * @param amount
 */
void Customer::addAccount(int id, double amount){

    AccNode* curr = headAcc;
    AccNode* added = new AccNode;
    added->acc = new Account(id,amount);
    added->next = NULL;

    //headAcc is Null
    if(curr == NULL){
        headAcc = added;
        accCount++;
        return;
    }

    //adding account by sorted
    while(curr != NULL){
        if(curr->next == NULL && curr->acc->getId() < id){
            curr->next = added;
            accCount++;
            return;
        }
        curr = curr->next;
    }
    delete added;

}
/**
 * This method deletes accounts from customer and return bool.
 * @param id
 * @return
 */
bool Customer::deleteAccount(int id){
    AccNode* curr = headAcc;
    AccNode* prev = NULL;

    // there is no account to delete
    if(accCount == 0){
        return false;
    }

    //deleting headacc and headacc is only account
    if(accCount == 1 && curr->acc->getId() == id){
        headAcc = NULL;
        accCount = 0;
        cout << "Account "<< id << " has been deleted" << endl;
        return true;
    }

    //deleting headacc and headacc is not only account
    if( curr->acc->getId() == id){
        headAcc = headAcc->next;
        accCount--;
        cout << "Account "<< id << " has been deleted" << endl;
        return true;
    }

    prev = headAcc;
    curr = headAcc->next;

    // deleting account from index 2
    while (curr != NULL){

        if(curr->acc->getId() == id){
            prev->next = curr->next;
            accCount--;
            cout << "Account "<< id << " has been deleted" << endl;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;

}
/**
 * This method deletes all accounts from linked account list
 */
void Customer::deleteAllAccounts() {
    AccNode* curr = headAcc;
    while(curr){
        AccNode* temp = curr;
        curr = curr->next;
        delete temp;
        headAcc = curr;
    }

}
/**
 * This method shows all accounts from customer
 */
void Customer::showAccounts(){
        if(accCount == 0){
            return;
        }
        AccNode *curr = headAcc;
        while (curr != NULL) {
            cout<<left<<setw(15) << curr->acc->getId() << setw(15) << getId()  << getFName() << " " <<  getLName()  <<  setw(24 - fName.length() - lName.length()) << "" << curr->acc->getAmount()<< endl;
            curr = curr->next;
        }

}
/**
 * This method shows customer information
 */
void Customer::showCustomer(){

    cout << left << "Customer id: " << setw(15) << id << "Customer name: " << fName << " " << lName << setw(18 - fName.length() - lName.length()) << "" <<
          "Number of accounts: " << accCount << endl;
    if (accCount) {
        cout << "Accounts of this customer:" << endl;
        AccNode *curr = headAcc;
        cout << left << setw(15) << "Account id  "  << "Balance" << endl;
        while (curr != NULL) {
            curr->acc->show();
            curr = curr->next;
        }

    }
}
/**
 * This method checks new customer info is same with current customer or less or high to sort customers.
 * @param ID
 * @param firstName
 * @param lastName
 * @return
 */
int Customer::checkCustomer(const int ID,const string firstName , const string lastName){
    if(id == ID) {
        return 10;
    }
    if(fName == firstName && lName == lastName){
        return 11;
    }
    if(lName > lastName){
        return 1;
    }
    if (lName < lastName){
        return -1;
    }
    if(lName == lastName && fName > firstName){
        return 1;
    }
    if(lName == lastName && fName < firstName){
        return -1;
    }
    return 0;
}