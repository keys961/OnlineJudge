#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef struct book
{
	int id;
	string title;
	string author;
	string keywords;
	string publisher;
	int year;
}Book;

vector<Book> books;

void input(int n);
void query(int m);
vector<int> find(string info, int type);

int main(int argc, char const *argv[])
{
    //char c;
	int N, M;
	cin >> N;
	input(N);
	scanf("%d", &M);
	getchar();
	query(M);
	return 0;
}

void input(int n)
{
    Book book;
    //char c;
	for(int i = 0; i < n; i++)
	{
		cin >> book.id;
		getchar();
		getline(cin, book.title);
		getline(cin, book.author);
		getline(cin, book.keywords);
		getline(cin, book.publisher);
		cin >> book.year;
		books.push_back(book);
	}
}

void query(int m)
{
	vector<int> v;
	int type;
	string info;
	for(int i = 0; i < m; i++)
	{
		getline(cin, info);
		type = info[0] - '0';
		info.erase(0, 3);
		v = find(info, type);
		cout << type << ": " << info << endl;
		if(v.size() == 0)
		{
            cout << "Not Found" << endl;
            continue;
		}
		for(int j = 0; j < v.size(); j++)
        {
            cout.width(7); cout.fill('0');
            cout << v[j] << endl;
        }
	}
}

vector<int> find(string info, int type)
{
	vector<int> v;
	int size = books.size();
	if(type == 1 || type == 2 || type == 4)
	{
		for(int i = 0; i < size; i++)
		{
			if(type == 1)
            {
				if(info == books[i].title)
					v.push_back(books[i].id);
            }
			else if(type == 2)
            {
				if(info == books[i].author)
					v.push_back(books[i].id);
            }
			else
            {
				if(info == books[i].publisher)
					v.push_back(books[i].id);
            }
		}
	}
	else if(type == 3)
	{
		for(int i = 0; i < size; i++)
		{
			if(books[i].keywords.find(info) != string::npos)
				v.push_back(books[i].id);
		}
	}
	else
	{
		int year = atoi(info.c_str());
		for(int i = 0; i < size; i++)
		{
			if(books[i].year == year)
				v.push_back(books[i].id);
		}
	}
	sort(v.begin(), v.end());
	return v;
}
