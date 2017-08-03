#include <cstdio>
#include <cstring>

using namespace std;

char lowDigit[13][5] = {"tret", "jan", "feb", "mar", "apr", "may",
                        "jun", "jly", "aug", "sep","oct", "nov", "dec"};
char upDigit[13][4] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei",
                       "elo", "syy", "lok", "mer", "jou"};

void printNum(char* num);

int main(int argc, char const *argv[])
{
    int n;
    char num[10];
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        gets(num);
        printNum(num);
    }
    return 0;
}

void printNum(char* num)
{
    if(num[0] >= '0' && num[0] <= '9')//Num
    {
        int n = 0;
        for(int i = 0; i < strlen(num); i++)
            n = n * 10 + num[i] - '0';
        int temp = n;
        if(n >= 13)
        {
            printf("%s", upDigit[n / 13]);
            n %= 13;
        }
        if(n != 0 && temp >= 13)
            printf(" %s", lowDigit[n]);
        else if(temp < 13)
            printf("%s", lowDigit[n]);
        printf("\n");
    }
    else
    {
        int len = strlen(num);
        int n = 0;
        char* digit1 = num;
        char* digit2 = nullptr;
        for(int i = 0; i < len; i++)
            if(num[i] == ' ')
            {
                digit2 = &num[i + 1];
                num[i] = 0;
                break;
            }
        if(digit2 != nullptr)//2 digit
        {
            for(int i = 0; i < 13; i++)
            {
                if(strcmp(digit1, upDigit[i]) == 0)
                {
                    n += 13 * i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++)
            {
                if(strcmp(digit2, lowDigit[i]) == 0)
                {
                    n += i;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < 13; i++)
            {
                if(strcmp(digit1, upDigit[i]) == 0)
                {
                    n += 13 * i;
                    break;
                }
            }
            for(int i = 0; i < 13; i++)
            {
                if(strcmp(digit1, lowDigit[i]) == 0)
                {
                    n += i;
                    break;
                }
            }
        }
        printf("%d\n", n);
    }

}