#include "functions.h"
#include <iostream>

using namespace std;

int main()
{
    RationalNumber x, y;
    cout<<"Enter the first rational number"<<endl;
    cout<<"   Sign of the number (+ or -): ";
    cin>>x.sign;
    cout<<"   Integer part: ";
    cin>>x.intpart;
    cout<<"   Numerator: ";
    cin>>x.num;
    cout<<"   Denominator (not 0): ";
    cin>>x.den;
    outputNumber (simplification(x));

    cout<<endl<<"Enter the second rational number"<<endl;
    cout<<"   Sign of the number (+ or -): ";
    cin>>y.sign;
    cout<<"   Integer part: ";
    cin>>y.intpart;
    cout<<"   Numerator: ";
    cin>>y.num;
    cout<<"   Denominator (not 0): ";
    cin>>y.den;
    outputNumber (simplification(y));

    sumAndDifference (x, y);

    cout<<endl<<"Product of rational numbers: ";
    outputNumber (simplification(multiplication(x,y)));

    cout<<endl<<"Quotient of rational numbers: ";
    if (!(y.num+y.intpart))
    {
        cout<<"   Division by zero!"<<endl;
    }
    else
    {
        outputNumber (simplification(devision(x,y)));
        cout<<endl;
    }
    return 0;
}
