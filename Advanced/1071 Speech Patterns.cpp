#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> frequency;

bool check(char c)
{
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z');
}

void getFrequency(string& text);

int main(int argc, char const *argv[])
{
    string text;
    getline(cin, text);
    getFrequency(text);
    map<string, int>::iterator it = frequency.begin();
    string maxWord;
    int maxCount = 0;
    for(; it != frequency.end(); it++)
    {
        if(it->second > maxCount)
        {
            maxWord = it->first;
            maxCount = it->second;
        }
    }
    printf("%s %d\n", maxWord.c_str(), maxCount);
    return 0;
}

void getFrequency(string& text)
{
    int ptr1 = 0, ptr2 = 0;
    int size = text.size();
    while(ptr1 < size && ptr2 < size)
    {
        if(text[ptr2] >= 'A' && text[ptr2] <= 'Z')
            text[ptr2] = text[ptr2] - 'A' + 'a';
        if(check(text[ptr2]))
        {
            ptr2++;
            if(ptr2 == size)
                frequency[text.substr(ptr1, ptr2 - ptr1)]++;
        }
        else
        {
            if(ptr1 == ptr2)
            {
                ptr1++; ptr2++;
            }
            else
            {
                frequency[text.substr(ptr1, ptr2 - ptr1)]++;
                ptr2++;
                ptr1 = ptr2;
            }
        }
    }
}