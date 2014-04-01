#include "functions.h"
#include <iostream>

using namespace std;

void outputNumber (struct RationalNumber x)
{
    if ((!x.intpart)||(!x.num))
    {
        if ((!x.intpart)&(!x.num))
        {
            cout<<"   0"<<endl;
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
                cout<<x.num<<" / "<<x.den<<endl;
            }
            if (!x.num)
            {
                cout<<x.intpart<<endl;
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
        cout<<x.intpart<<" : "<<x.num<<" / "<<x.den<<endl;
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
    x.num+=x.den*x.intpart;
    x.intpart=0;
    return x;
}

RationalNumber sum(struct RationalNumber x, struct RationalNumber y, char sign)
 {
     RationalNumber res;
     if (x.intpart)
     {
        x=improperFraction(x);
     }
     if (y.intpart)
     {
        y=improperFraction(y);
     }
     res.num=(x.num)*(y.den)+(y.num)*(x.den);
     res.den=(x.den)*(y.den);
     res.intpart=0;
     res.sign=sign;
     return res;
 }

RationalNumber difference (struct RationalNumber x, struct RationalNumber y, char sign)
{
     RationalNumber res;
     if (x.intpart)
     {
        x=improperFraction(x);
     }
     if (y.intpart)
     {
        y=improperFraction(y);
     }
     res.num=(x.num)*(y.den)-(y.num)*(x.den);
     res.den=(x.den)*(y.den);
     res.intpart=0;
     res.sign=sign;
     return res;
}

RationalNumber multiplication (struct RationalNumber x, struct RationalNumber y)
{
    RationalNumber res;
     if (x.intpart)
     {
        x=improperFraction(x);
     }
     if (y.intpart)
     {
        y=improperFraction(y);
     }
    res.num=x.num*y.num;
    res.den=x.den*y.den;
    res.intpart=0;
    if (((x.sign=='-') & (y.sign=='-'))||((x.sign=='+') & (y.sign=='+')))
    {
       res.sign='+';
    }
    else
    {
        res.sign='-';
    }
    return res;
}

RationalNumber devision (struct RationalNumber x, struct RationalNumber y)
 {
    RationalNumber res;
    if (x.intpart)
     {
        x=improperFraction(x);
     }
     if (y.intpart)
     {
        y=improperFraction(y);
     }
    res.num=x.num*y.den;
    res.den=x.den*y.num;
    res.intpart=0;
    if (((x.sign=='-') & (y.sign=='-'))||((x.sign=='+') & (y.sign=='+')))
    {
       res.sign='+';
    }
    else
    {
        res.sign='-';
    }
    return res;
}

void sumAndDifference (struct RationalNumber x, struct RationalNumber y)
{
    RationalNumber s, d;
    if ((x.sign=='+') & (y.sign=='+'))
    {
        s=sum(x,y,'+');
        if ((x.num*y.den)>(y.num*x.den))
        {
            d=difference(x,y,'+');
        }
        else
        {
            d=difference(y,x,'-');
        }
    }
    if ((x.sign=='+') & (y.sign=='-'))
    {
        d=sum(x,y,'+');
        if ((x.num*y.den)>(y.num*x.den))
        {
            s=difference(x,y,'+');
        }
        else
        {
            s=difference(y,x,'-');
        }
    }
    if ((x.sign=='-') & (y.sign=='+'))
    {
        d=sum(x,y,'-');
        if ((x.num*y.den)>(y.num*x.den))
        {
            s=difference(x,y,'-');
        }
        else
        {
            s=difference(y,x,'+');
        }
    }
    if ((x.sign=='-') & (y.sign=='-'))
    {
        s=sum(x,y,'-');
        if ((x.num*y.den)>(y.num*x.den))
        {
            d=difference(x,y,'-');
        }
        else
        {
            d=difference(y,x,'+');
        }
    }

    cout<<endl<<"Sum of rational numbers: ";
    outputNumber (simplification(s));

    cout<<endl<<"Difference of rational numbers: ";
    outputNumber (simplification(d));
}




