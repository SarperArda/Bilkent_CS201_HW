//
// Created by Sarper Arda BAKIR on 29.06.2022.
//
#include "Book.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor
Book::Book(int bookId,std::string name,std::string authors,int year) {
    this->bookId = bookId;
    this->name = name;
    this->authors = authors;
    this->year = year;
    checked = false;
    studentId = 0;
}

//getter setter
bool Book::getChecked(){
    return checked;

}
int Book::getYear(){
    return year;
}
std::string Book::getName(){
    return name;
}
std::string Book::getAuthors(){
    return authors;
}
void Book::setChecked(bool current){
    checked = current;
}
int Book::getStudent(){
    return studentId;
}
void Book::setStudent(int currentId){
    studentId = currentId;
}
int Book::getBookId(){
    return bookId;
}
/**
 *
 * This method is to show information about book.
 * parameter is used to showing info about where it needs. In student class, there is no room for status.
 * @param show
 */
void Book::toString(bool show){
    cout << left << setw(10)<< bookId << setw(30)<< name <<setw(30)<< authors <<setw(10)<< year;
    if(show) {
        if (getChecked()) {
            cout << "Checked out by student " << studentId << endl;
        } else {
            cout << "Not checked out" << endl;
        }
    }else {
        cout << endl;
    }

}

Book::Book() {

}