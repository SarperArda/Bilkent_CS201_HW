//
// Created by Sarper Arda BAKIR on 29.06.2022.
//

#ifndef UNTITLED3_STUDENT_H
#define UNTITLED3_STUDENT_H
#include <string>
#include <iostream>
#include "Book.h"

class Student{
public:
    Student(int studentId,std::string name);
    Student();
    void toString();
    void addBook(Book);
    int getStudent();
    void deleteBook(Book);

private:
    int studentId;
    std::string name;
    int curr;
    Book* arr;

};
#endif //UNTITLED3_STUDENT_H
