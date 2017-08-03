#include <cstdio>
#include <string>
#include <vector>

using namespace std;

vector<string> spell;
string number[10] = {"ling", "yi", "er", "san",
                     "si", "wu", "liu", "qi", "ba", "jiu"};
string unit[4] = {"", "Shi", "Bai", "Qian"};
int status = 0;
void read(int num);
void deal(int num);//4 digits

int main(int argc, char const *argv[])
{
    int number;
    scanf("%d", &number);
    read(number);
    for(int i = 0; i < spell.size() - 1; i++)
        printf("%s ", spell[i].c_str());
    printf("%s\n", spell[spell.size() - 1].c_str());
    return 0;
}

void read(int num)
{
    if(num == 0)
    {
        spell.push_back("ling");
        return;
    }
    if(num < 0)
    {
        spell.push_back("Fu");
        num = -num;
    }

    int temp;
    int flag = 0;
    //1*10^9
    temp = num / 100000000;
    num %= 100000000;
    if(temp)
    {
        spell.push_back(number[temp]);
        status = 1;
        spell.push_back("Yi");
    }
    while(num)
    {
        if(flag == 0)
        {
            temp = num / 10000;
            flag++;
            deal(temp);
            if(temp == 0)
            {
                if((spell.size() >= 2))
                    spell.push_back("ling");
            }
            else
                spell.push_back("Wan");
            num %= 10000;
        }
        else
        {
            deal(num);
            break;
        }
    }
}

void deal(int num)
{
    int digits[4] = {0};
    if(num == 0)
    {
        //spell.push_back("ling");
        return;
    }
    else
    {
        int flag = 0;
        for(int i = 0; i < 4; i++)
        {
            digits[i] = num % 10;
            num /= 10;
        }
        for(int i = 3; i >= 0; i--)
        {
            if(digits[i] == 0)
                flag = 1;
            else
            {
                if(flag == 1 && status == 1)
                {
                    spell.push_back("ling");
                    flag = 0;
                }
                spell.push_back(number[digits[i]]);
                status = 1;
                if(i != 0)
                    spell.push_back(unit[i]);
            }
        }
    }
}