#include<map>
#include<cmath>
#include<cstdio>
using namespace std;
struct monomial {
	int coefficient;
};
struct Polynomial {
	map<int, monomial> body;
};

int ArrayToInt(int num[], int n, bool sign) //int型数组转成int值
{
    if (sign) //带有符号的系数
    {
        int result = 0;
        int i = 1;
        while (n >= 1)
        {
            result += num[i] * (int)pow(10, n - 1);
            ++i;
            --n;
        }
        if (num[0] == 0)
        {
            return result;
        }
        else
            return result * -1;
    }
    else //不需要辨别符号的次数
    {
        int result = 0;
        int i = 0;
        while (n >= 0)
        {
            result += num[i] * pow(10, n);
            ++i;
            --n;
        }
        return result;
    }
}

void PrintPolynomial(const Polynomial& poly)
{
    for (auto iter = poly.body.rbegin(); iter != poly.body.rend(); iter++) {
        if (iter->second.coefficient != 0) {
            printf("%+dx^%d", iter->second.coefficient, iter->first);
        }
    }
    printf("\n");
}

Polynomial InitPolynomial(const char* str)
{
    Polynomial poly;
    int bytes = 0;
    while (str[bytes] != '\0')
    {
        monomial nomial;
        nomial.coefficient = 0;
        int i = 0;
        int coe[11] = { 0 };
        int len_of_coe = 0;
        int exp[11] = { 0 };
        int len_of_exp = 0;
        bool before = true;
        if (str[bytes + i] == '+') //确定系数的符号
        {
            coe[i] = 0;
        }
        else
        {
            coe[i] = 1;
        }
        ++i;
        ++len_of_coe;
        for (; (str[bytes + i] != '+') && (str[bytes + i] != '-') && (str[bytes + i] != '\0'); ++i)
        {
            if (before && str[bytes + i] != 'x') 
            {
                coe[len_of_coe] = str[bytes + i] - '0';
                len_of_coe += 1;
            }
            else if (!before && str[bytes + i] != 'x') 
            {
                exp[len_of_exp] = str[bytes + i] - '0';
                len_of_exp += 1;
            }
            else if (str[bytes + i] == 'x')
            {
                before = false;
                i += 1;
            }
        } 
        nomial.coefficient = ArrayToInt(coe, len_of_coe - 1, true);
        int degree = ArrayToInt(exp, len_of_exp - 1, false);
        auto search = poly.body.find(degree);
        if (search != poly.body.end()) 
        {
            nomial.coefficient = nomial.coefficient + search->second.coefficient;
            poly.body[degree] = nomial;
        }
        else {
            poly.body.insert(pair<int, monomial>(degree, nomial));
        }
        bytes += i;
    }
    return poly;
}

Polynomial Add(const Polynomial& lhs, const Polynomial& rhs)
{
    Polynomial poly;
    poly = lhs;
    for(auto iter = rhs.body.begin(); iter != rhs.body.end(); iter++){
        monomial nomial;
        nomial.coefficient = iter->second.coefficient;
        int degree = iter->first;
        auto search = poly.body.find(degree);
        if (search != poly.body.end())
        {
            nomial.coefficient = nomial.coefficient + search->second.coefficient;
            poly.body[degree] = nomial;
        }
        else {
            poly.body.insert(pair<int, monomial>(degree, nomial));
        }

    }
    return poly;
}

Polynomial Minus(const Polynomial& lhs, const Polynomial& rhs)
{Polynomial poly;
    poly = lhs;
    for(auto iter = rhs.body.begin(); iter != rhs.body.end(); iter++){
        monomial nomial;
        nomial.coefficient = iter->second.coefficient * -1;
        int degree = iter->first;
        auto search = poly.body.find(degree);
        if (search != poly.body.end())
        {
            nomial.coefficient = nomial.coefficient + search->second.coefficient;
            poly.body[degree] = nomial;
        }
        else {
            poly.body.insert(pair<int, monomial>(degree, nomial));
        }

    }
    return poly;
}

Polynomial Multiply(const Polynomial& lhs, const Polynomial& rhs)
{
    Polynomial product;
    for (auto iter1 = lhs.body.begin(); iter1 != lhs.body.end(); iter1++) {
        int exp = iter1->first;
        int coe1 = iter1->second.coefficient;
        for (auto iter2 = rhs.body.begin(); iter2 != rhs.body.end(); iter2++) {
            int expstronger = exp + iter2->first;
            int coestronger = coe1 * iter2->second.coefficient;
            monomial nomial;
            nomial.coefficient = coestronger;
            auto search = product.body.find(expstronger);
            if (search != product.body.end()) {
                nomial.coefficient = nomial.coefficient + search->second.coefficient;
                product.body[expstronger] = nomial;
            }
            else {
                product.body.insert(pair<int, monomial>(expstronger, nomial));
            }
        }
    }
    return product;
}

Polynomial Power(const Polynomial& base, int exp)
{
    Polynomial multiplyproduct = base;
    while (exp > 1) {
        multiplyproduct = Multiply(multiplyproduct, base);
        exp--;
    }
    return multiplyproduct;
}

// ATTENTION: DO NOT MODIFY THE CODE BELOW

//#include "test.hpp"

int main()
{
  //  test();
    return 0;
}