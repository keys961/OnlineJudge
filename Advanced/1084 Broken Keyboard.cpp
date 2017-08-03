#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

map<char, bool> frequency;
vector<char> characters;

int main(int argc, char const *argv[])
{
	string line1, line2;
	cin >> line1 >> line2;
	for(int i = 0; i < line2.size(); i++)
	{
		if(line2[i] >= 'a' && line2[i] <= 'z')
			frequency[line2[i] - 'a' + 'A'] = true;
		else
			frequency[line2[i]] = true;
	}
	for(int i = 0; i < line1.size(); i++)
	{
		if(line1[i] >= 'a' && line1[i] <= 'z')
			line1[i] = line1[i] - 'a' + 'A';
		if(frequency.find(line1[i]) == frequency.end())
		{
			int flag = 0;
			for(int j = 0; j < characters.size(); j++)
				if(characters[j] == line1[i])
				{
					flag = 1;
					break;
				}
			if(!flag)
				characters.push_back(line1[i]);
		}
	}
	for(int i = 0; i < characters.size(); i++)
		printf("%c", characters[i]);
	printf("\n");
	return 0;
}