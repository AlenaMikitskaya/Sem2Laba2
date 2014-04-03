#include "functions.h"
#include <iostream>

using namespace std;

int main()
{
    RationalNumber x, y;
    x=inputNumber ();
    outputNumber (x);
    cout<<endl<<endl;
    y=inputNumber ();
    outputNumber (y);

    cout<<endl<<endl<<"Sum of rational numbers: ";
    outputNumber (sum(x,y));

    cout<<endl<<endl<<"Difference of rational numbers: ";
    outputNumber (difference(x,y));

    cout<<endl<<endl<<"Product of rational numbers: ";
    outputNumber (multiplication(x,y));

    cout<<endl<<endl<<"Quotient of rational numbers: ";
    if (!(y.num+y.intpart))
    {
        cout<<"   Division by zero!"<<endl;
    }
    else
    {
        outputNumber (devision(x,y));
        cout<<endl;
    }
    return 0;
}
