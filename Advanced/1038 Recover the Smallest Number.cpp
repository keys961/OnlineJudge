#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	string num1 = a + b;
	string num2 = b + a;
	return num1 < num2;
}

int main()
{
	int n;
	vector<string> numList;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		numList.push_back(s);
	}
	sort(numList.begin(), numList.end(), compare);
	string res;
	for (int i = 0; i < n; i++)
		res += numList[i];
	while (res[0] == '0' && res.size() > 1)
		res.erase(0, 1);
	cout << res << endl;
	return 0;
}