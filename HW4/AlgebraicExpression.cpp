//Abdullah Riaz
//Section 1
//22001296

#include "AlgebraicExpression.h"
#include <sstream>
#include <iostream>

string infix2prefix(const string exp)
{
    string prefix = infix2postfix(reverse(exp));
    return reverse(prefix);
}

string infix2postfix(const string exp)
{
    string postfix;
    Stack operatorStack;
    string temp;
    string temp4;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            operatorStack.push("(");
        }
        else if (exp[i] == ')')
        {
            while (operatorStack.getTop(temp) && temp != "(")
            {
                postfix += temp;
                postfix = postfix + ' ';
                operatorStack.pop();
            }
            operatorStack.pop();
        }
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            while (operatorStack.getTop(temp) && temp != "(" && (precedence(temp[0]) >= precedence(exp[i])))
            {
                postfix += temp;
                postfix = postfix + ' ';
                operatorStack.pop();
            }
            operatorStack.push(toString(exp[i]));
        }
        else if (exp[i] == ' ')
        {
            continue;
        }

        else
        {
            while (exp[i] != ' ' && i < exp.length())
            {
                temp4 += exp[i];
                i++;
            }
            postfix += temp4 + " ";
            temp4 = "";
        }
    }

    while (operatorStack.getTop(temp))
    {
        postfix += temp;
        postfix = postfix + ' ';
        operatorStack.pop();
    }

    return postfix;
}

string prefix2infix(const string exp)
{
    string prefix = postfix2infix(reverse(exp));
    return reverse(prefix);
}

string prefix2postfix(const string exp)
{
    string prefix = prefix2infix(exp);
    prefix = infix2postfix(prefix);
    return prefix;
}

string postfix2infix(const string exp)
{
    string infix;
    Stack operatorStack;
    string temp;
    string temp2;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            operatorStack.getTop(temp);
            operatorStack.pop();
            operatorStack.getTop(temp2);
            operatorStack.pop();
            operatorStack.push("( " + temp2 + " " + exp[i] + " " + temp + " )");
        }

        else
        {
            while (exp[i] != ' ')
            {
                infix += exp[i];
                i++;
            }
            if (infix != "")
            {
                operatorStack.push(infix);
            }
            infix = "";
        }
    }

    while (operatorStack.getTop(temp))
    {
        infix += temp;
        operatorStack.pop();
    }

    return infix;
}

string postfix2prefix(const string exp)
{
    string prefix = postfix2infix(exp);
    prefix = infix2prefix(prefix);
    return prefix;
}

double evaluateInfix(const string exp)
{
    string prefix = infix2prefix(exp);
    return evaluatePrefix(prefix);
}

double evaluatePrefix(const string exp)
{
    Stack operendStack;
    string temp;
    string temp2;
    string temp4;
    string ans;
    double ansD;

    for (int i = exp.length() - 1; i >= 0; i--)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            operendStack.getTop(temp);
            operendStack.pop();
            operendStack.getTop(temp2);
            operendStack.pop();
            operendStack.push(evaluate(temp, temp2, exp[i]));
        }

        else if (exp[i] == ' ')
        {
            continue;
        }

        else
        {
            while (exp[i] != ' ')
            {

                temp4 += exp[i];
                i--;
            }
            operendStack.push(reverse(temp4));
            temp4 = "";
        }
    }

    operendStack.getTop(ans);
    stringstream sstream(ans);
    sstream >> ansD;

    return ansD;
}

double evaluatePostfix(const string exp)
{
    string prefix = postfix2prefix(exp);
    return evaluatePrefix(prefix);
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

bool isNumber(char c)
{
    return (c >= '0' && c <= '9');
}

string reverse(const string str)
{
    string temp = "";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == '(')
        {
            temp += ')';
        }
        else if (str[i] == ')')
        {
            temp += '(';
        }
        else
        {
            temp += str[i];
        }
    }

    return temp;
}

string evaluate(const string operand1, const string operand2, const char op)
{
    double result;
    double dig1;
    double dig2;
    stringstream sstream(operand1);
    stringstream sstream2(operand2);

    sstream >> dig1;
    sstream2 >> dig2;

    if (op == '+')
    {
        result = dig1 + dig2;
    }
    else if (op == '-')
    {
        result = dig1 - dig2;
    }
    else if (op == '*')
    {
        result = dig1 * dig2;
    }
    else if (op == '/')
    {
        result = dig1 / dig2;
    }
    else
    {
        result = 0;
    }

    ostringstream sstream3;
    sstream3 << result;
    string varAsString = sstream3.str();

    return varAsString;
}

string toString(char c)
{
    string temp = "";
    temp += c;
    return temp;
}
