#include "functions.h"
#include <iostream>
#include <cassert>
#include <math.h>

using namespace std;

RationalNumber simplification (struct RationalNumber x);
RationalNumber improperFraction (struct RationalNumber x);

RationalNumber inputNumber ()
{
    RationalNumber x;
    cout<<"Enter the first rational number"<<endl;
    cout<<"   Sign of the number (+ or -): ";
    cin>>x.sign;
    cout<<"   Integer part: ";
    cin>>x.intpart;
    cout<<"   Numerator: ";
    cin>>x.num;
    cout<<"   Denominator (not 0): ";
    cin>>x.den;
    assert(x.den!=0);
    return x;
}

void outputNumber (struct RationalNumber x)
{
    x=simplification(x);
    if ((!x.intpart)||(!x.num))
    {
        if ((!x.intpart)&&(!x.num))
        {
            cout<<"   0";
        }
        else
        {
            if (x.sign=='-')
            {
                cout<<"   "<<x.sign<<" ";
            }
            else
            {
                cout<<"   ";
            }
            if (!x.intpart)
            {
                cout<<x.num<<" / "<<x.den;
            }
            if (!x.num)
            {
                cout<<x.intpart;
            }
        }
    }
    else
    {
        if (x.sign=='-')
        {
            cout<<"   "<<x.sign<<" ";
        }
        else
        {
                cout<<"   ";
        }
        cout<<x.intpart<<" : "<<x.num<<" / "<<x.den;
    }
}

RationalNumber simplification (struct RationalNumber x)
{
    if (x.num>=x.den)//выделение целой части
    {
        x.intpart+=x.num/x.den;
        x.num-=x.den*(x.num/x.den);
    }

    int a=x.num;
    int b=x.den;
    int c;
    while (a%b)
    {
        c=a%b;
        a=b;
        b=c;
    }
    if (c!=1)//сокращение
    {
        x.num/=c;
        x.den/=c;
    }
    return x;
}

RationalNumber improperFraction (struct RationalNumber x)//неправильная дробь
{
    if (x.intpart)
    {
        x.num+=x.den*x.intpart;
        x.intpart=0;
    }
    return x;
}

RationalNumber sum(struct RationalNumber x, struct RationalNumber y)
 {
     RationalNumber res;
     x=improperFraction(x);
     y=improperFraction(y);
     if (x.sign=='-')
     {
         x.num=-x.num;
     }
     if (y.sign=='-')
     {
         y.num=-y.num;
     }
     res.num=(x.num)*(y.den)+(y.num)*(x.den);
     res.den=x.den*y.den;
     res.intpart=0;
     if (res.num<0)
     {
         res.sign='-';
         res.num=fabs(res.num);
     }
     else
     {
         res.sign='+';
     }
     return simplification (res);
 }

RationalNumber difference (struct RationalNumber x, struct RationalNumber y)
{
     RationalNumber res;
     x=improperFraction(x);
     y=improperFraction(y);
     if (x.sign=='-')
     {
         x.num=-x.num;
     }
     if (y.sign=='-')
     {
         y.num=-y.num;
     }
     res.num=(x.num)*(y.den)-(y.num)*(x.den);
     res.den=x.den*y.den;
     res.intpart=0;
     if (res.num<0)
     {
         res.sign='-';
         res.num=fabs(res.num);
     }
     else
     {
         res.sign='+';
     }
     return simplification (res);
}

RationalNumber multiplication (struct RationalNumber x, struct RationalNumber y)
{
    RationalNumber res;
    x=improperFraction(x);
    y=improperFraction(y);
    res.num=(x.num)*(y.num);
    res.den=(x.den)*(y.den);
    res.intpart=0;
    if ((x.sign=='-' && y.sign=='-')||(x.sign=='+' && y.sign=='+'))
    {
        res.sign='+';
    }
    else
    {
        res.sign='-';
    }
    return simplification (res);
}

RationalNumber devision (struct RationalNumber x, struct RationalNumber y)
 {
    RationalNumber res;
    x=improperFraction(x);
    y=improperFraction(y);
    res.num=(x.num)*(y.den);
    res.den=(x.den)*(y.num);
    res.intpart=0;
    if (((x.sign=='-') && (y.sign=='-'))||((x.sign=='+') && (y.sign=='+')))
    {
        res.sign='+';
    }
    else
    {
        res.sign='-';
    }
    return simplification (res);
}





