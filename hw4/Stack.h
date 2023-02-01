//
// Created by Sarper Arda BAKIR on 26.07.2022.
//
/**
 * This class is Stack header
 */
#include <iostream>
using namespace std;
#include <string>
#ifndef HW4_STACK_H
#define HW4_STACK_H
class Stack{
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty();
    bool push(string newItem);
    bool pop();
    bool pop(string& item);
    string getTop();

private:
    struct StackNode{
        string curr;
        StackNode* next;
    };
    StackNode* topItem;

};
#endif //HW4_STACK_H
