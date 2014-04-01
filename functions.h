#ifndef FUNCTIONS_H
#define FUNCTIONS_H

struct RationalNumber
{
    int intpart, num, den;
    char sign;
};

void outputNumber (struct RationalNumber x);

RationalNumber simplification (struct RationalNumber x);
RationalNumber improperFraction (struct RationalNumber x);

RationalNumber sum (struct RationalNumber x, struct RationalNumber y, char sign);
RationalNumber difference (struct RationalNumber x, struct RationalNumber y, char sign);
RationalNumber multiplication (struct RationalNumber x, struct RationalNumber y);
RationalNumber devision (struct RationalNumber x, struct RationalNumber y);

void sumAndDifference (struct RationalNumber x, struct RationalNumber y);

#endif // FUNCTIONS_H
