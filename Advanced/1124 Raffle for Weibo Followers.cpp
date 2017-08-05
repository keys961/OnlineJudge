#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

set<string> visited;
vector<string> forwards;

void getWinner(int m, int skipNum, int startIndex);

int main(int argc, char const *argv[])
{
    int m, n, s; //~, skip number, start index
    string p;
    cin >> m >> n >> s;
    for(int i = 0; i < m; i++)
    {
        cin >> p;
        forwards.push_back(p);
    }
    getWinner(m, n, s);
    return 0;
}

void getWinner(int m, int skipNum, int startIndex)
{
    if(startIndex > forwards.size())
    {
        cout << "Keep going..." << endl;
        return;
    }
    int index = startIndex - 1;
    while(index < m)
    {
        if(visited.find(forwards[index]) == visited.end())
        {
            cout << forwards[index] << endl;
            visited.insert(forwards[index]);
            index += skipNum;
        }
        else
            index++;
    }
}