//
// Created by Sarper Arda BAKIR on 27.06.2022.
// There are memory leak which ı couldn't solve.
//
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor
Student::Student(int studentId, std::string name) {
    this->name=name;
    this->studentId = studentId;
    curr = 0;
    arr = NULL;
}

/**
 * This method is used to add book object from arr.
 * @param b
 */
void Student::addBook(Book b){
    //if the first time this method is used, directly adding book object.
    if(curr == 0){
        Book* temp = new Book[1];
        temp[0] = b;
        temp[curr].setChecked(true);
        temp[curr].setStudent(studentId);
        delete[] arr;
        arr = temp;
        curr++;
        return;
    }
    //Creating new sized array, adding desired book object, and coping to arr.
    Book* temp = new Book[curr + 1];
    int m = 0;
    for(int i = 0; i < curr; i++){
        temp[m] = arr[i] ;
        m++;
    }

    temp[curr] =  b;
    temp[curr].setChecked(true);
    temp[curr].setStudent(studentId);
    delete[] arr;
    arr = temp;
    curr++;
}
/**
 * This method is used to delete book object from arr.
 * @param b
 */
void Student::deleteBook(Book b) {
    //Creating new sized array, deleting desired book object, and coping to arr.
    Book* temp = new Book[curr-1];
    int m = 0;
    for(int i = 0; i < curr; i++){
        if(arr[i].getBookId() != b.getBookId()){
            temp[m] = arr[i] ;
            m++;
        }
    }
    delete[] arr;
    arr = temp;
    curr--;

}
//getter
int Student::getStudent(){
    return studentId;
}
/**
 * This method is to show information about student.
 */
void Student::toString(){
    cout << "Student id: " << studentId << " student name " << name << endl;
    if(curr){
        cout << "Student " << studentId <<" has checked out the following books:" << endl;
        cout << left <<setw(10)<< "Book Id" <<setw(30)<< "Book Name"<<setw(30)<< "Authors"<<setw(30)<< "Year" << endl;
        for(int i = 0; i < curr; i ++){
            arr[i].toString(false);
        }
    }
    else{
        cout << "Student " << studentId<<  " has no books"<< endl;
    }

}

Student::Student() {}