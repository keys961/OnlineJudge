#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <map>
#include <cstring>
#include <string>

using namespace std;

typedef struct Person
{
    char name[9];
    int age;
    int netWorth;
}Person;

vector<Person> people;

void input(int n);
bool compare(Person a, Person b)
{
    if(a.netWorth != b.netWorth)
        return a.netWorth > b.netWorth;
    if(a.age != b.age)
        return a.age < b.age;
    return strcmp(a.name, b.name) < 0;
}
void query(int k);

int main(int argc, char** argv)
{
    int n, k;
    scanf("%d %d", &n, &k);
    input(n);
    sort(people.begin(), people.end(), compare);
    query(k);
    return 0;
}

void input(int n)
{
    Person p;
    for(int i = 0; i < n; i++)
    {
        cin >> p.name >> p.age >> p.netWorth;
        people.push_back(p);
    }
}

void query(int k)
{
    int m, amin, amax, temp;
    vector<Person>::iterator it;
    for(int i = 1; i <= k; i++)
    {
        printf("Case #%d:\n", i);
        scanf("%d %d %d", &m, &amin, &amax);
        temp = m;
        it = people.begin();
        for(; it != people.end(); it++)
        {
            if(it->age >= amin && it->age <= amax)
            {
                cout << it->name << " "<< it->age
                     << " "<< it->netWorth << endl;
                if(--temp == 0)
                    break;
            }

        }
        if(temp == m)
            printf("None\n");
    }
}