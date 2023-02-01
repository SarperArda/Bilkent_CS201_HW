//
// Created by Sarper Arda BAKIR on 26.07.2022.
//
#include "Stack.h"
#include <iostream>
//constructor
Stack::Stack() {
    topItem = NULL;
}
//destructor
Stack::~Stack() {
    while(!isEmpty()){
        pop();
    }

}
//taken by Stack slides.
Stack::Stack(const Stack& aStack){

    if (aStack.topItem == NULL)
        topItem = NULL;  // original stack is empty

    else {
        // copy first node
        topItem = new StackNode;
        topItem->curr = aStack.topItem->curr;

        // copy rest of stack
        StackNode *newPtr = topItem;
        for (StackNode *origPtr = aStack.topItem->next;
             origPtr != NULL;
             origPtr = origPtr->next){
            newPtr->next = new StackNode;
            newPtr = newPtr->next;
            newPtr->curr = origPtr->curr;
        }
        newPtr->next = NULL;
    }
}
/**
 * This method checks whether stack is null or not.
 * @return
 */
bool Stack::isEmpty(){
    return topItem == NULL;
}
/**
 * This method pushes new item.
 * @param newItem
 * @return
 */
bool Stack::push(string newItem){
    StackNode* temp = new StackNode;
    temp->curr = newItem;
    temp->next = topItem;
    topItem = temp;
    return true;
}
/**
 * This method deletes the item.
 * @return
 */
bool Stack::pop(){
    if(isEmpty()){
        return false;
    }
    else{
        StackNode* temp = topItem;
        topItem = topItem->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}
/**
 * This method deletes item and returns it.
 * @param item
 * @return
 */
bool Stack::pop(string& item){
    if(isEmpty()){
        return false;
    }
    else{
        item = topItem->curr;
        StackNode* temp = topItem;
        topItem = topItem->next;
        temp->next = NULL;
        delete temp;
        return true;
    }
}
/**
 * This method returns top item.
 * @return
 */
string Stack::getTop(){
    return topItem->curr;
}
