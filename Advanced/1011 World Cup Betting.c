#include <stdio.h>

double getProfit(double betting[][3]);

int main()
{
	double betting[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			scanf("%lf", &betting[i][j]);
	printf("%.2f\n", getProfit(betting));
	return 0;
}

double getProfit(double betting[][3])
{
	double profit = 1.0;
	int maxIndex = 0;
	for(int i = 0; i < 3; i++)
	{
		maxIndex = 0;
		for(int j = 0; j < 3; j++)
			if(betting[i][j] > betting[i][maxIndex])
				maxIndex = j;

		profit *= betting[i][maxIndex];
		switch(maxIndex)
		{
			case 0: printf("W "); break;
			case 1: printf("T "); break;
			case 2: printf("L "); break;
		}
	}
	profit = (profit * 0.65 - 1) * 2;
	return profit;
}
