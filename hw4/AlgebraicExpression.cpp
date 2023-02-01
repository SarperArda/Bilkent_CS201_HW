//
// Created by Sarper Arda BAKIR on 26.07.2022.
//
#include "AlgebraicExpression.h"
using namespace std;
#include <sstream>
/**
 * This method converts infix to postfix
 * This method's pseudocode is taken by slides.
 * @param exp
 * @return
 */
string infix2postfix( const string exp ){

    //variables
    string postFixExp = "";
    Stack s;
    string ch;

    //checking infix is null or not.
    if(exp.empty()){
        return postFixExp;
    }

    for (int i = 0; i<exp.length(); i++){
        ch = exp[i];

        //operand
        if(!isOperator(ch) && ch != "(" && ch != ")" ){
            postFixExp += ch;
        }

        //parentheses
        if(ch == "(" ){
            s.push(ch);
        }
        if(ch == ")") {
            while (s.getTop() != "(") {
                postFixExp += s.getTop();
                s.pop();
            }
            s.pop();
        }

        //operator
        if(isOperator(ch)){
            while(!s.isEmpty() && precedence(ch) <= precedence(s.getTop()) && s.getTop() != "("){
                postFixExp += s.getTop();
                s.pop();
            }
            s.push(ch);
        }

    }

    //adding last operators
    while(!s.isEmpty()){
        postFixExp += s.getTop();
        s.pop();
    }

    return postFixExp;
}
/**
 * This method calculates postfix
 * This method's pseudocode is taken by slides.
 * @param exp
 * @return
 */
double evaluatePostfix( const string exp ){

    //variables
    Stack s;
    string operand1,operand2;
    int index = 0;
    string temp;
    temp = exp[0];

    //checking postfix is null or not
    if(exp.empty()){
        return 0;
    }

    for(int i = 0; i < exp.length(); i++){
        //operand is pushed
        if(!isOperator(temp) ){
            s.push(temp);
        }

        //operator part
        else{
            //taking last two operand and convert them to double
            s.pop(operand1);
            s.pop(operand2);
            double op1 = 0;
            convert(operand1,op1);
            double op2 = 0;
            convert(operand2,op2);
            double result = 0;

            //calculating
            if( temp == "+") {result = op1 + op2;}
            if( temp == "-") {result = op2 - op1;}
            if( temp == "*") {result = op1 * op2;}
            if( temp == "/") {result = op2 / op1;}

            //pushing result to stack
            string re;
            convert(re,result);
            s.push(re);
        }
        index++;
        temp = exp[index];
    }
    string sum;
    s.pop(sum);
    double m = 0;
    convert(sum,m);
    return m;
}
/**
 * This method checks whether string is operator or not.
 * @param ch
 * @return
 */
bool isOperator(string ch){
    return ch == "+"|| ch == "-" || ch == "*" || ch == "/";
}
/**
 * This method converts double to string and string to double which is needed checking by which one is not 0;
 * @param s
 * @param d
 */
void convert(string& s, double& d){

    if(d){
        ostringstream m;
        m << d;
        s = m.str();
        return;
    }
    else{
        istringstream(s) >> d;
        return;
    }
}
/**
 * This method checks precedence.
 * @param ope
 * @return
 */
int precedence(string ope){
    if(ope == "*" || ope == "/"){
        return 2;
    }
    if(ope == "+" || ope == "-"){
        return 1;
    }
    return 0;
}
