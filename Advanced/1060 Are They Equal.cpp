#include <iostream>
#include <string>

using namespace std;

int getExponent(string num);
string getBase(string num, int n, int e);

int main()
{
	int n;
	string num1, num2;
	cin >> n >> num1 >> num2;
	int exp1 = getExponent(num1);
	int exp2 = getExponent(num2);
	string base1 = getBase(num1, n, exp1);
	string base2 = getBase(num2, n, exp2);
	if (n == 0)
		printf("YES 0.*10^0\n");
	else if (exp1 == exp2 && base1 == base2)
		printf("YES 0.%s*10^%d\n", base1.c_str(), exp1);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n", base1.c_str(), exp1, base2.c_str(), exp2);
	
	return 0;
}

int getExponent(string num)
{
	int exponent = 0;
	while (num[0] == '0')
		num.erase(0, 1);
	if (num.size() == 0)
		return 0;
	if (num[0] != '.')
	{
		for (int i = 0; num[i] && num[i] != '.'; i++)
			exponent++;
		return exponent;
	}
	else
	{
		bool flag = false;
		for (int i = 1; num[i]; i++)
		{
			if(num[i] == '0')
				exponent--;
			else
			{
				flag = true;
				break;
			}
		}
		if(flag)
			return exponent;
		return  0;
	}
}

string getBase(string num, int n, int e)
{
	string res = "";
	int index = 0;
	if (e > 0)
	{
		int i = 0;
		while (num[i] == '0')
			i++;
		for (; num[i] && index < n; i++)
		{
			if (num[i] == '.')
				continue;
			res += num[i];
			index++;
		}
	}
	else
	{
		int i = 0;
		if (num[i + 1] == 0)
		{
			res = "0";
			while (res.size() < n)
				res += '0';
			return res;
		}
		while (num[i] != '.')
			i++;
		i++;
		while (num[i] == '0')
			i++;
		for (; num[i] && index < n; i++)
		{
			res += num[i];
			index++;
		}
	}

	while (res.size() < n)
		res += '0';
	return res;
}