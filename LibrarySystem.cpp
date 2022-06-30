//
// Created by Sarper Arda BAKIR on 27.06.2022.
//

#include "LibrarySystem.h"
#include "Book.h"
#include "Student.h"
#include <iostream>
#include <iomanip>
using namespace std;
//Constructor
LibrarySystem::LibrarySystem(){

    arr = NULL;
    arr2 = NULL;

    numberOfBooks = 0;
    numberOfStudents = 0;
}

LibrarySystem::~LibrarySystem(){

    if(arr){
        delete[] arr;
    }
    if(arr2){
        delete[] arr2;
    }

}
/**
 * This method works for adding Book object to arr.
 * @param bookId
 * @param name
 * @param authors
 * @param year
 */
void LibrarySystem::addBook(const int bookId, const string name, const string authors, const int year){
    //Book objects are added before, in this block bookId is checked.
    if(numberOfBooks) {
        for (int i = 0; i <= numberOfBooks; i++) {
            if (arr[i].getBookId() == bookId) {
                cout << "Book " << bookId << " already exists" << endl;
                return;
            }

        }
    }
    //Book object adding
    // Firstly sized new array is created, added, then copied to arr.
    Book* temp = new Book[numberOfBooks+1];
    Book b1 = Book(bookId, name, authors, year);
    int m = 0;
    for(int i = 0; i < numberOfBooks; i++){
        temp[m] = arr[i] ;
        m++;
    }
    temp[numberOfBooks] = b1;
    numberOfBooks++;
    delete[] arr;
    arr = temp;
    cout << "Book " << bookId << " has been added" << endl;

}
/**
 * This method works for deleting Book object from arr.
 * @param bookId
 */
void LibrarySystem::deleteBook(const int bookId){
    // This block checking bookId's existence.
    int y = 0;
    if(numberOfBooks) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (arr[i].getBookId() != bookId) {
                y++;
            }
        }
    }
    if(y == numberOfBooks){
        cout << "Book " << bookId << " does not exist" << endl;
        return;
    }

    //Book object deleting
    // Firstly sized new array is created,deleted, then copied to arr.
    Book* temp = new Book[numberOfBooks-1];
    int m = 0;
    int i;
    for( i= 0; i < numberOfBooks; i++){
        if(arr[i].getBookId() != bookId){
            temp[m] = arr[i] ;
            m++;
        }
    }
    //This block is to delete Book object from related Student.
    for (int i = 0; i < numberOfBooks; i++) {
            if (arr[i].getBookId() == bookId && arr[i].getChecked()) {
                for (int m = 0; m < numberOfStudents; m++) {
                    if (arr2[m].getStudent() == arr[i].getStudent()) {
                        cout << "Book " << bookId << " has been returned" << endl;
                        arr2[m].deleteBook(arr[i]);
                    }

                }
            }
    }

    delete[] arr;
    arr = temp;
    numberOfBooks--;
    cout << "Book " << bookId << " has been deleted" << endl;

}
/**
 * This method works for adding Student object to arr2.
 * @param studentId
 * @param name
 */
void LibrarySystem::addStudent(const int studentId, const string name){
    //Student objects are added before, in this block studentId is checked.
    if(numberOfStudents) {
        for (int i = 0; i <= numberOfStudents; i++) {
            if (arr2[i].getStudent() == studentId) {
                cout << "Student " << studentId << " already exists" << endl;
                return;
            }

        }
    }
    //Student object adding
    // Firstly sized new array is created, added, then copied to arr.
    Student* temp = new Student[numberOfStudents+1];
    Student s1 = Student(studentId, name);
    int m = 0;
    for(int i = 0; i < numberOfStudents; i++){
        temp[m] = arr2[i] ;
        m++;
    }
    temp[numberOfStudents] = s1;
    numberOfStudents++;
    delete[] arr2;
    arr2 = temp;
    cout << "Student " << studentId << " has been added" << endl;
}
/**
 * This method works for deleting Student object from arr2.
 * @param studentId
 */
void LibrarySystem::deleteStudent(const int studentId){
    // This block checking bookId's existence.
    int y = 0;
    if(numberOfStudents) {
        for (int i = 0; i < numberOfStudents; i++) {
            if (arr2[i].getStudent() != studentId) {
                y++;
            }

        }
    }
    if(y == numberOfStudents){
        cout << "Student " << studentId << " does not exist" << endl;
        return;
    }
    //Book object deleting
    // Firstly sized new array is created,deleted, then copied to arr.
    Student* temp = new Student[numberOfStudents-1];
    int m = 0;
    int i;
    for( i= 0; i < numberOfStudents; i++){
        if(arr2[i].getStudent() != studentId){
            temp[m] = arr2[i] ;
            m++;
        }
    }
    delete[] arr2;
    arr2 = temp;
    numberOfStudents--;
    cout << "Student " << studentId << " has been deleted" << endl;

}
/**
 * This method creates relation between book and student object.
 * @param bookId
 * @param studentId
 */
void LibrarySystem::checkoutBook(const int bookId, const int studentId){

    int v = 1; // this variable is to boolean. I didn't know I can use return instead of this variable before writing method.
    // These two using is working efficient; thus I decided staying int variable just like other methods.

    // Checking are there book for checkout
    if(numberOfBooks) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (arr[i].getBookId() == bookId) {
                v = 0;
                //Checking is desired book checked before
                if(arr[i].checked){
                    cout << "Book " << bookId << " has been already checked out by another student" << endl;
                }
                else{
                    //Checking are there student for checkout
                    if(numberOfStudents) {

                        //relating book and student
                        int m = 1;
                        for (int y = 0; y < numberOfStudents; y++) {
                            if (arr2[y].getStudent() == studentId) {
                                m = 0;

                                arr[i].setChecked(true);
                                arr2[y].addBook(arr[i]);
                                arr[i].setStudent(arr2[y].getStudent());

                                cout << "Book "<< bookId << " has been checked out by student " << studentId << endl;

                            }

                        }
                        if(m){
                            cout << "Student " << studentId << " does not exist for checkout" << endl;
                        }
                    }
                }
            }

        }
        if(v){
            cout << "Book " << bookId << " does not exist for checkout" << endl;
        }
    }
}
/**
 * This method returns book object from related student object.
 * @param bookId
 */
void LibrarySystem::returnBook(const int bookId){

    int x = 1; // this variable is to boolean

    // Checking are there book for return
    if(numberOfBooks) {
        for (int i = 0; i < numberOfBooks; i++) {

            // returning book from student object
            if (arr[i].getBookId() == bookId) {
                if(arr[i].checked) {
                    x = 0;
                    arr[i].setChecked(false);

                    for (int m = 0; m < numberOfStudents; m++) {
                        if (arr2[m].getStudent() == arr[i].getStudent()) {
                            arr2[m].deleteBook(arr[i]);
                        }

                    }
                    cout << "Book " << bookId << " has been returned" << endl;

                }

            }

        }
        if(x){
            cout <<"Book "<< bookId << " has not been checked out" << endl;
        }
    }

}
/**
 * This method is to show all books.
 */
void LibrarySystem::showAllBooks(){
    cout << left <<setw(10)<< "Book Id" <<setw(30)<< "Book Name"<<setw(30)<< "Authors"<<setw(10)<< "Year"  << "Status" << endl;
    for (int i = 0; i < numberOfBooks; i++) {
        arr[i].toString(true);
    }
}
/**
 * This method is to show specific book.
 * @param bookId
 */
void LibrarySystem::showBook(const int bookId){
    if(numberOfBooks) {
        for (int i = 0; i < numberOfBooks; i++) {
            if (arr[i].getBookId() == bookId) {
                arr[i].toString(true);
            }

        }
    }
}
/**
 * This method is to show specific student.
 * @param studentId
 */
void LibrarySystem::showStudent(const int studentId){
    int x = 1; // this variable is to boolean
    if(numberOfStudents) {
        for (int i = 0; i < numberOfStudents; i++) {
            if (arr2[i].getStudent() == studentId) {
                arr2[i].toString();
                x = 0;
            }
        }
    }
    if(x){
        cout<<"Student "<<studentId<<" does not exist"<<endl;
    }
}