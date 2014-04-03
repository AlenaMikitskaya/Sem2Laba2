#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct RationalNumber
{
    int intpart, num, den;
    char sign;
};

RationalNumber inputNumber ();
void outputNumber (struct RationalNumber x);

RationalNumber sum (struct RationalNumber x, struct RationalNumber y);
RationalNumber difference (struct RationalNumber x, struct RationalNumber y);
RationalNumber multiplication (struct RationalNumber x, struct RationalNumber y);
RationalNumber devision (struct RationalNumber x, struct RationalNumber y);

#endif // FUNCTIONS_H
