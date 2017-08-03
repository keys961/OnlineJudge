#include <stdio.h>
#include <string.h>
void ToLower(char *string)
{
    int i;
    for(i=0;string[i]!='\0';i++)
    {
        if(string[i]>='A'&&string[i]<='Z')
        {
            string[i] = string[i]+'a'-'A';
        }
    }
}
int main()
{
    char string[1001];
    int alphabet[26]={0,};
    int i,max=0;
    int index = 0;
    gets(string);
    ToLower(string);
    for(i=0;string[i]!=0;i++)
    {
        alphabet[string[i]-'a']++;
    }
    for(i=0;i<26;i++)
    {
        if(alphabet[i]>max){
            max=alphabet[i];
            index = i;
        }
    }
    printf("%c %d",index+'a',max);
    return 0;
}