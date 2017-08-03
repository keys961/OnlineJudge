#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int N, currentFloor = 0, totalTime = 0;
	int request[100];

	scanf("%d", &N);
	for(int i  = 0; i < N; i++)
		scanf("%d", &request[i]);

	for(int i = 0; i < N; i++)
	{
		int diff = request[i] - currentFloor;
		if(diff > 0)
			totalTime += diff * 6 + 5;
		else
			totalTime += (-1) * diff * 4 + 5;
		currentFloor = request[i];
	}

	printf("%d\n", totalTime);

	return 0;
}