//
// Created by Sarper Arda BAKIR on 29.06.2022.
//

#ifndef UNTITLED3_BOOK_H
#define UNTITLED3_BOOK_H
#include <string>
#include <iostream>
class Book{
public:
    Book();

    Book(int , std::string , std::string , int );
    void toString(bool);
    bool getChecked();
    void setChecked(bool);
    int getStudent();
    void setStudent(int );
    bool checked;
    int getBookId();
    std::string getName();
    std::string getAuthors();
    int getYear();
private:
    int bookId;
    std::string name;
    std::string authors;
    int year;
    int studentId;
};
#endif //UNTITLED3_BOOK_H
