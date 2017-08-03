#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <memory>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <set>

using namespace std;

int getExponent(string num)
{
    int exponent;
    int index = num.find('E');
    string exp = num.substr((unsigned int)(index + 1),
                            num.size() - index - 1);
    stringstream s;
    s << exp;
    s >> exponent;
    return exponent;
}

int main(int argc, char const *argv[])
{
    string scientificNum;
    string answer, coefficient;
    int exponent;
    cin >> scientificNum;
    if(scientificNum[0] == '-')
        answer += '-';
    coefficient = scientificNum.substr(1, scientificNum.find('E') - 1);
    exponent = getExponent(scientificNum);
    if(exponent == 0)
        cout << answer << coefficient << endl;
    else if(exponent > 0)
    {
        string fraction = coefficient.substr(2, coefficient.size() - 2);
        if(exponent >= fraction.size())
        {
            answer += coefficient[0] + fraction;
            exponent -= fraction.size();
            while(exponent)
            {
                answer += '0';
                exponent--;
            }
            cout << answer << endl;
        }
        else
        {
            string intPart = coefficient[0] + fraction.substr(0, exponent);
            string fracPart = fraction.substr(exponent, fraction.size() - exponent);
            cout << answer << intPart << "." <<  fracPart << endl;
        }
    }
    else
    {
        exponent = -exponent - 1;
        string fracPart = coefficient[0] + coefficient.substr(2, coefficient.size() - 2);
        while(exponent)
        {
            fracPart = "0" + fracPart;
            exponent--;
        }
        cout << answer + "0." << fracPart << endl;
    }
    return 0;
}