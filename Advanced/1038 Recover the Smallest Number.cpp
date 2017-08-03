#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

char numbers[10000][9];

int compare(const void *a, const void *b);

int main(int argc, char const *argv[])
{
	int N;
	int flag = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%s", numbers[i]);
	qsort(numbers, N, sizeof(char) * 9, compare);

	for(int i = 0; i < N; i++)
	{
		if(i == 0)
		{
			int j;
			for(j = 0; numbers[0][j]; j++)
			{
				if(numbers[0][j] != '0')
                {
                    flag = 1;
					break;
                }
			}
			for(; numbers[0][j]; j++)
				printf("%c", numbers[0][j]);
		}
		else
        {
            int j;
            for(j = 0; numbers[i][j]; j++)
			{
				if(numbers[i][j] != '0')
                {
                    flag = 1;
					break;
                }
			}
            if(flag == 1)
                printf("%s", numbers[i]);
        }
	}
	if(flag == 0)
        printf("0");
	printf("\n");

	return 0;
}

int compare(const void *a, const void *b)
{
	char* num1 = (char*)malloc(sizeof(char) * 20);
	char* num2 = (char*)malloc(sizeof(char) * 20);
	strcpy(num1, (char*)a);
	strcpy(num2, (char*)b);

	strcat(num1, (char*)b);
	strcat(num2, (char*)a);

	int i = strcmp(num1, num2);
	free(num1); free(num2);
	return i;
}
