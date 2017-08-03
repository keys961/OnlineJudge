#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

typedef struct user
{
	string username;
	string password;
}User;

vector<User> users;
vector<User> res;

void input(int n);
int modify(int n);

int main(int argc, char const *argv[])
{
	int n, count;
	cin >> n;
	input(n);
	count = modify(n);
	if(count == 0)
	{
		if(n > 1)
			printf("There are %d accounts and no account is modified\n", n);
		else
			printf("There is %d account and no account is modified\n", n);
	}
	else
	{
		printf("%d\n", count);
		for(int i = 0; i < res.size(); i++)
			cout << res[i].username << " " << res[i].password << endl;
	}
	return 0;
}

void input(int n)
{
	User newUser;
	for(int i = 0; i < n; i++)
	{
		cin >> newUser.username >> newUser.password;
		users.push_back(newUser);
	}
}

int modify(int n)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		int flag = 0;
		for(int j = 0; j < users[i].password.size(); j++)
		{
			if(users[i].password[j] == '1')
			{
				users[i].password[j] = '@';
				flag = 1;
			}
			else if(users[i].password[j] == '0')
			{
				users[i].password[j] = '%';
				flag = 1;
			}
			else if(users[i].password[j] == 'l')
			{
				users[i].password[j] = 'L';
				flag = 1;
			}
			else if(users[i].password[j] == 'O')
			{
				users[i].password[j] = 'o';
				flag = 1;
			}
		}
		if(flag)
		{
			count++;
			res.push_back(users[i]);
		}
	}
	return count;
}