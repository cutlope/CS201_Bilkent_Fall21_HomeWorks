//Abdullah Riaz
//Section 1
//22001296

#include "Stack.h"
#include <string>
using namespace std;

// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp);
// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp);
// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp);
// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp);
// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp);
// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp);
//It evaluates an infix expression.
double evaluateInfix(const string exp);
//It evaluates a prefix expression.
double evaluatePrefix(const string exp);
//It evaluates a postfix expression.
double evaluatePostfix(const string exp);

//Additional Methods

//Calculates the precedence of an operator.
int precedence(char op);

//It reverses the string while making sure the brackets are maintained.
string reverse(const string str);

//check if the char is an digit
bool isNumber(char c);

//Evaluate the expression
string evaluate(const string operand1, const string operand2, const char op);

string toString(char c);
