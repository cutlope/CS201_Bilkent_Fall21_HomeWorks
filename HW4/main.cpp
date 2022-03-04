#include "AlgebraicExpression.h"
#include <iostream>

int main()
{
    cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;

    cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
    cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;

    cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
    cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;

    cout << evaluatePrefix("* + * 100 2 4 - 12 4") << endl;
    cout << evaluatePrefix("- / * 20 * 50 + 3 6 300 2") << endl;

    cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << evaluateInfix("5 / ( 5 * ( 2 + 1 ) ) * 2 - 10") << endl;

    cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << endl;

    return 0;
}
