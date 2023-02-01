//
// Created by Sarper Arda BAKIR on 26.07.2022.
//
/**
 * This class is AlgebraicExpression header
 */
#ifndef HW4_ALGEBRAICEXPRESSION_H
#define HW4_ALGEBRAICEXPRESSION_H
//#include "Stack.h"
#include <string>
#include "Stack.h"
// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix( const string exp );
// It evaluates a postfix expression.
double evaluatePostfix( const string exp );
int precedence(string ope);
bool isOperator(string ch);
void convert(string& s, double& d);

#endif //HW4_ALGEBRAICEXPRESSION_H
