//
// Created by Sarper Arda BAKIR on 18.07.2022.
//
/**
 * Source code for Banking System
 * @SarperArdaBakır
 * @24July2022
 */
using namespace std;
#include <string>
#include "BankingSystem.h"

//Constructor
BankingSystem::BankingSystem() {
    headCust = NULL;
    custNum = 0;
    accID = 1;
}
//Destructor
BankingSystem::~BankingSystem() {
    CustNode* curr = headCust;
    while(curr){
        CustNode* temp = curr;
        curr = curr->next;
        delete temp;
        headCust = curr;
    }
}
/**
 * This method creates Customer and adds sorted customer linked list.
 * @param customerId
 * @param firstName
 * @param lastName
 */
void BankingSystem::addCustomer( const int customerId ,const string firstName , const string lastName ){

    //first adding
   if(custNum == 0){
       CustNode* temp = new CustNode;
       temp->cust = new Customer(customerId,firstName,lastName);
       temp->next = NULL;
       headCust = temp;
       custNum++;
       cout << "Customer " <<customerId << " has been added" << endl;
       return;
   }
   CustNode* curr = headCust;

   //Checking whether customer info is same with previous customers
   while(curr != NULL){
       if(curr->cust->checkCustomer(customerId,firstName,lastName) > 9){
           if(curr->cust->checkCustomer(customerId,firstName,lastName) == 11) {
               cout << "Customer " << firstName << " " << lastName << " already exists" << endl;

           }
           if(curr->cust->checkCustomer(customerId,firstName,lastName) == 10) {
               cout << "Customer " << customerId << " already exists" << endl;

           }
           return;
       }
       curr = curr->next;
   }
    curr = headCust;

    //adding customer
    while(curr != NULL){

        //adding customer med of sorted linked list
        if(curr->cust->checkCustomer(customerId,firstName,lastName) == -1 && (curr->next != NULL) && curr->next->cust->checkCustomer(customerId,firstName,lastName) == 1 ){
            CustNode* temp = new CustNode;
            temp->cust = new Customer(customerId,firstName,lastName);;
            temp->next = curr->next;
            curr->next = temp;
            custNum++;
            cout << "Customer " <<customerId << " has been added" << endl;
            return;
        }

        //adding customer end of sorted linked list
        if(curr->cust->checkCustomer(customerId,firstName,lastName) == -1 && curr->next == NULL){
            CustNode* temp = new CustNode;
            temp->cust = new Customer(customerId,firstName,lastName);;
            curr->next = temp;
            temp->next = NULL;
            custNum++;
            cout << "Customer " <<customerId << " has been added" << endl;
            return;
        }

        //adding customer beginning of sorted linked list
        if(curr == headCust && curr->cust->checkCustomer(customerId,firstName,lastName) == 1){
            CustNode* temp = new CustNode;
            temp->cust = new Customer(customerId,firstName,lastName);;
            temp->next = headCust;
            headCust = temp;
            custNum++;
            cout << "Customer " <<customerId << " has been added" << endl;
            return;
        }
        curr = curr->next;
    }

}
/**
 * This method deletes Customer from sorted customer linked list.
 * @param customerId
 */
void BankingSystem::deleteCustomer( const int customerId ){
    CustNode* curr = headCust;
    CustNode* prev = NULL;

    // if there is no customer
    if(curr == NULL){
        cout<< "Customer " << customerId << " does not exist" << endl;
        return;
    }

    //deleting first and only customer
    if(custNum == 1 && curr->cust->getId() == customerId) {
        curr->cust->deleteAllAccounts();
        headCust = NULL;
        custNum--;
        delete curr;
        cout << "Customer " << customerId<< " has been deleted "<< endl;
        return;
    }

    // deleting first customer but not only
    if(curr->cust->getId() == customerId){
        curr->cust->deleteAllAccounts();
        headCust = headCust->next;
        custNum--;
        delete curr;
        cout << "Customer " << customerId<< " has been deleted "<< endl;
        return;
    }

    prev = curr;
    curr = curr->next;

    //deleting customer from index 2
    while(curr != NULL){
        if(curr->cust->getId() == customerId){
            prev->next = curr->next;
            curr->cust->deleteAllAccounts();
            delete curr;
            custNum--;
            cout << "Customer " << customerId<< " has been deleted "<< endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    //if code comes here , customer does not exist.
    cout<< "Customer " << customerId << " does not exist" << endl;
}
/**
 * This method adds account to related customer and return account id.
 * @param customerId
 * @param amount
 * @return
 */
int BankingSystem::addAccount( const int customerId, const double amount ){

    CustNode* curr = headCust;
    while(curr != NULL){
        if(curr->cust->getId() == customerId){
            curr->cust->addAccount(accID,amount);
            cout<< "Account " << accID <<" added for customer " << customerId << endl;
            accID++;
            return (accID - 1);
        }
        curr = curr->next;
    }
    cout<< "Customer " << customerId << " does not exist" << endl;
    return -1;

}
/**
 * This method deletes account from related customer
 * @param accountId
 */
void BankingSystem::deleteAccount( const int accountId ){

    CustNode* curr = headCust;
    bool check = false;
    while(curr != NULL && !check){
        check = curr->cust->deleteAccount(accountId);
        curr = curr->next;
    }
    if(!check){
        cout<< "Account " << accountId  << " does not exist" << endl;
    }
}
/**
 * This method shows all accounts
 */
void BankingSystem::showAllAccounts(){
    if(custNum == 0){
        cout << "There is no customer" << endl;
        return;
    }
    cout << left << setw(15) << "Account id" <<setw(15)  << "Customer id" <<setw(25) << "Customer name"  << "Balance" << endl;
    CustNode* curr = headCust;
    while(curr != NULL){
        curr->cust->showAccounts();
        curr = curr->next;
    }

}
/**
 * This method shows all customer
 */
void BankingSystem::showAllCustomers(){

    if(custNum == 0){
        cout << "There is no customer" << endl;
        return;
    }

    cout << left << setw(15) << "Customer id" << "Customer name" << endl;
    CustNode* curr = headCust;
    while(curr != NULL){
        cout<<left << setw(15)<< curr->cust->getId() << curr->cust->getFName() << " " << curr->cust->getLName() << endl;
        curr = curr->next;
    }

}
/**
 * This method shows customer information
 * @param customerId
 */
void BankingSystem::showCustomer( const int customerId ){
    CustNode* curr = headCust;
    while(curr != NULL){
        if(curr->cust->getId() == customerId){
            curr->cust->showCustomer();
            return;
        }
        curr = curr->next;
    }
    cout<< "Customer " << customerId << " does not exist" << endl;
}

