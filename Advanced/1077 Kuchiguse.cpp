#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strs;
string res;

int main(int argc, char const *argv[])
{
	int n, len = 257;
	string s;
	cin >> n;
	getchar();
	for(int i = 0; i < n; i++)
	{
		getline(cin, s);
		strs.push_back(s);
		if(s.length() < len)
			len = s.length();
	}
	int i, j;
	for(i = 0; i < len; i++)
	{
		char c = strs[0][strs[0].size() - 1 - i];
		for(j = 1; j < strs.size(); j++)
		{
			if(strs[j][strs[j].size() - 1 - i] != c)
				break;
		}
		if(j != strs.size())
			break;
		else
			res.insert(0, 1, c);
	}
	if(res.size() == 0)
		cout << "nai" << endl;
	else
		cout << res << endl;
	return 0;
}