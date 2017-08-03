#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

char str[1001];
vector<char> result;
map<char, bool> isStucked;

void detect(int k);
void insert(char c);

int main(int argc, char const *argv[])
{
	int k, len;
	scanf("%d %s", &k, str);
	len = strlen(str);
	detect(k);
	for(int i = 0; i < result.size(); i++)
		printf("%c", result[i]);
	printf("\n");
	for(int i = 0; i < len; i++)
	{
		if(str[i] != 1)
			printf("%c", str[i]);
	}
	printf("\n");
	return 0;
}

void detect(int k)
{
	int len = strlen(str);
	int ptr1 = 0, ptr2 = 0;
	while(ptr2 < len)
	{
		if(++ptr2 < len && str[ptr2] == str[ptr1] )
		{
			if(ptr2 - ptr1 == k - 1)
			{
//				for(int i = ptr1 + 1; i <= ptr2; i++)
//					str[i] = 1;
//				insert(str[ptr1]);
				ptr2++;
				ptr1 = ptr2;
			}
		}
		else
		{
			isStucked[str[ptr1]] = false;
			ptr1 = ptr2;
		}
	}
	ptr1 = ptr2 = 0;
	while(ptr2 < len)
	{
		if(++ptr2 < len && str[ptr2] == str[ptr1] )
		{
			if(ptr2 - ptr1 == k - 1)
			{
				if(isStucked.find(str[ptr1]) == isStucked.end())
				{
					for (int i = ptr1 + 1; i <= ptr2; i++)
						str[i] = 1;
					insert(str[ptr1]);
				}
				ptr2++;
				ptr1 = ptr2;
			}
		}
		else
		{
			//isStucked[str[ptr1]] = false;
			ptr1 = ptr2;
		}
	}
}

void insert(char c)
{
	for(int i = 0; i < result.size(); i++)
		if(result[i] == c)
			return;
	result.push_back(c);
}