//
// Created by Sarper Arda BAKIR on 29.06.2022.
//

#ifndef UNTITLED3_LIBRARYSYSTEM_H
#define UNTITLED3_LIBRARYSYSTEM_H

#include "Student.h"
#include "Book.h"

class LibrarySystem {

public: LibrarySystem();
    ~LibrarySystem();
    void addBook(const int bookId, const std::string name, const std::string authors, const int year);
    void deleteBook(const int bookId);
    void addStudent(const int studentId, const std::string name);
    void deleteStudent(const int studentId);
    void checkoutBook(const int bookId, const int studentId);
    void returnBook(const int bookId);
    void showAllBooks();
    void showBook(const int bookId);
    void showStudent(const int studentId);
private:
    Book* arr;
    Student* arr2;
    int numberOfBooks;
    int numberOfStudents;

};
#endif //UNTITLED3_LIBRARYSYSTEM_H
