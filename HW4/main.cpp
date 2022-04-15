/** Ayşe Kelleci
 *  21902532 CS201-3 
 *  HW4 main class
 *  5 January 2022
 */

#include "AlgebraicExpression.h"

int main() {
cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;
cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;
cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;
cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;
cout << evaluatePrefix("* + * 100 2 4 - 12 4") << endl;
cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;
cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << endl;
return 0;
}


/*int main()
{
    Stack s;
    string postfix = "100 12 2 - 8 * + 4 /";

    cout << postfix2prefix( postfix) << endl;
    cout << postfix2infix( postfix) << endl;
    string prefix = "+ a b";
    string prefix2 = "+ + a * b c * + * d e f g";
    cout << prefix2postfix( prefix) << endl;
    cout << prefix2postfix( prefix2) << endl;

    string prefix3 = "+ - * A B / C D E";
    cout<< prefix2infix( prefix3) << endl;

    string infix = "a + b * c + ( d * e + f ) * g";

    cout << infix2postfix( infix) << endl;
    cout << infix2prefix(infix) << endl;

    cout <<evaluatePostfix( postfix) << endl;

    return 0;
}*/