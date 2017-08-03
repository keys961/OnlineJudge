#include <stdio.h>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct student
{
	char name[5];
}Student;

vector<Student> table[2501];
vector<Student> v;

bool compare(Student s1, Student s2)
{
	return strcmp(s1.name, s2.name) < 0;
}

void input(int stuN, int courseN);
void output(int courseN);

int main(int argc, char const *argv[])
{
	int stuN, courseN;
	scanf("%d %d", &stuN, &courseN);
	input(stuN, courseN);
	output(courseN);
	return 0;
}

void input(int stuN, int courseN)
{
	Student s;
	int n, id;
	for(int i = 0; i < stuN; i++)
	{
		cin >> s.name >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> id;
			table[id].push_back(s);
		}
	}
}

void output(int courseN)
{
	for(int i = 1; i <= courseN; i++)
	{
		v = table[i];
		int size = v.size();
		sort(v.begin(), v.end(), compare);
		printf("%d %d\n", i, size);
		for(int j = 0; j < size; j++)
			printf("%s\n", v[j].name);;
	}
}