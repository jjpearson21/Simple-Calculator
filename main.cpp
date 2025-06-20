#include <iostream>
#include <cmath>
#include <string>

using namespace std;

void showMenu()
{
    system("cls");
    cout << "\n            ===== SIMPLE CALCULATOR ===== " << endl;
    cout << "Operations available:" << endl;
    cout << "  1   Addition (+)" << "            |    10   sin(x) - Radians" << endl;
    cout << "  2   Subtraction (-)" << "         |    11   cos(x) - Radians" << endl;
    cout << "  3   Multiplication (*)" << "      |    12   tan(x) - Radians" << endl;
    cout << "  4   Division (/)" << "            |    13   arcsin(x) - Radians" << endl;
    cout << "  5   Modulus Operator (%)" << "    |    14   arccos(x) - Radians" << endl;
    cout << "  6   Raise to Power (^)" << "      |    15   arctan(x) - Radians" << endl;
    cout << "  7   nth Root (x^(1/n))" << "      |    16   Pythagorean Theorem [sqrt(x^2 + y^2)]" << endl;
    cout << "  8   Absolute Value (|x|)" << "    |    17   Natural Log (ln(x))" << endl;
    cout << "  9   Log Base 10 (log(x))" << "    |    18   Exponential Function (e^x)" << endl;
    cout << "==========================================================================" << endl;
}

double getNumber()
{
    double num;
    while (true)
    {
        cout << "Enter a number (if 8-15, 17, 18 - second number does't matter): ";
        cin >> num;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a numeric value.\n";
        }
        else
        {
            return num;
        }
    }
}

int getOperator()
{
    int op;
    cout << "Enter Operator (1, 2, 3, 4, ...): ";
    cin >> op;
    while (op < 0 || op > 18)
    {
        cout << "Please enter a valid operator: ";
        cin >> op;
    }
    return op;
}

double calculate(double a, double b, int op)
{
    switch (op)
    {
    case 1:
        return a + b;
    case 2:
        return a - b;
    case 3:
        return a * b;
    case 4:
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return a / b;
    case 5:
        if (b == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return fmod(a, b);
    case 6:
        return pow(a, b);
    case 7:
        if (a < 0)
        {
            cout << "Error: Cannot take square root of a negative number." << endl;
            return 0;
        }
        else
        {
            return pow(a, 1.0 / b);
        }
    case 8:
        return fabs(a);
    case 9:
        return log10(a);
    case 10:
        return sin(a);
    case 11:
        return cos(a);
    case 12:
        return tan(a);
    case 13:
        return asin(a);
    case 14:
        return acos(a);
    case 15:
        return atan(a);
    case 16:
        return hypot(a, b);
    case 17:
        return log(a);
    case 18:
        return exp(a);
    default:
        cout << "Invalid operator." << endl;
        return 0;
    }
}

void printResult(double a, double b, int op)
{
    switch (op)
    {
    case 1:
        cout << "Result: " << a << " + " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 2:
        cout << "Result: " << a << " - " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 3:
        cout << "Result: " << a << " * " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 4:
        cout << "Result: " << a << " / " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 5:
        cout << "Result: " << a << " % " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 6:
        cout << "Result: " << a << " ^ " << b << " = " << calculate(a, b, op) << endl;
        break;
    case 7:
        cout << "Result: " << b << "th root of " << a << " = " << calculate(a, b, op) << endl;
        break;
    case 8:
        cout << "Result: Absolute value of " << a << " is " << calculate(a, b, op) << endl;
        break;
    case 9:
        cout << "Result: log(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 10:
        cout << "Result: sin(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 11:
        cout << "Result: cos(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 12:
        cout << "Result: tan(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 13:
        cout << "Result: arcsin(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 14:
        cout << "Result: arccos(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 15:
        cout << "Result: arctan(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 16:
        cout << "Result: sqrt(" << a << "^2 + " << b << "^2)" << " = " << calculate(a, b, op) << endl;
        break;
    case 17:
        cout << "Result: ln(" << a << ")" << " = " << calculate(a, b, op) << endl;
        break;
    case 18:
        cout << "Result: e^" << a << " = " << calculate(a, b, op) << endl;
        break;
    default:
        cout << "Invalid operator." << endl;
    }
}

bool anotherCalc()
{
    char choice;
    cout << "Would you like to calculate again? (y/n): ";
    cin >> choice;
    while (choice != 'y' && choice != 'n')
    {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 'y')
    {
        return true;
    }
    else if (choice == 'n')
    {
        cout << "Thank you for using the Simple Calculator!" << endl;
        return false;
    }

    return false;
}

int main()
{
    do
    {
        showMenu();
        double num1 = getNumber();
        int op = getOperator();
        double num2 = getNumber();
        printResult(num1, num2, op);
    } while (anotherCalc() != false);

    return 0;
}