#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//If peak is i
int increaseLen[10001] = {0,}; //Increase[i] = max len of increase seq from 1 to i
int decreaseLen[10001] = {0,}; //Decrease[i] = max len of decrease seq from i to N
//Seq
int seq[10001] = {0,};

int maxLen = 0; //Max lengths
int index = 0; //Peak index
int difference = 0x7fffffff;//Get difference of left and right

void input(int n);
void getIncrease(int n);
void getDecrease(int n);
void solve(int n);

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	input(n);//Input sequence
	getIncrease(n);//Get left length, if len = 1, no left/right side
	getDecrease(n);//Get right length
	solve(n);//Find maxlen with min diff
	if(index == 0)//If the index is not the peak
		printf("No peak shape\n");
	else
		printf("%d %d %d\n", maxLen, index, seq[index]);

	return 0;
}

void input(int n)
{
	for(int i = 1; i <= n; i++)
		scanf("%d", &seq[i]);
}

void getIncrease(int n)
{
	//Base case:
	increaseLen[1] = 1;//Assume len of single element is 1
	if(seq[1] < seq[2]) //Initial 2 element
		increaseLen[2] = 2;
    else
        increaseLen[2] = 1;
	//Iterative
	int peak = 3, peakNum, maxNum;//peak index, peak element
								//maxNum is to as the length of the
								//increasing sequence
	for(; peak <= n - 1; peak++)//from 3 to n - 1
	{	//Get each peak left length(including peak)
		//If no left part len = 0 + 1 = 1
		peakNum = seq[peak];
		maxNum = 0;
		for(int i = 1; i < peak; i++)//Function:
			if(seq[i] < seq[peak])//increlen[peak] = max{increlen[i]}
				if(maxNum < increaseLen[i])//i from 1 to peak - 1
					maxNum = increaseLen[i];//and seq[i] < seq[peak]
		increaseLen[peak] = maxNum + 1;//Add own node
	}
}

void getDecrease(int n)
{	//Base case:
	decreaseLen[n] = 1;
	if(seq[n - 1] > seq[n])
		decreaseLen[n - 1] = 2;
    else
        decreaseLen[n - 1] = 1;
	//Iterative
	int peak = n - 2, peakNum, maxNum;//peak index, peak element
								//maxNum is to as the length of the
								//decreasing sequence
	for(; peak >= 1; peak--)//from n-1 to 2
	{//Get each peak left length(including peak)
		//If no right part len = 0 + 1 = 1
		peakNum = seq[peak];
		maxNum = 0;
		for(int i = n; i > peak; i--)//Function:
			if(seq[i] < seq[peak])//decreLen[peak] = max{decreLen[i]}
				if(maxNum < decreaseLen[i])//i from n to peak + 1
					maxNum = decreaseLen[i];//and seq[peak] > seq[i]
		decreaseLen[peak] = maxNum + 1;
	}
}

void solve(int n)
{
	int tempLen, tempDiff;
	for(int i = 2; i < n; i++)
	{
		if(increaseLen[i] == 1 || decreaseLen[i] == 1)
			continue;
		tempLen = increaseLen[i] + decreaseLen[i] - 1;//The sequence length of peak i
		tempDiff = abs(increaseLen[i] - decreaseLen[i]); //Diff of left and right
		if(tempLen > maxLen || (tempLen == maxLen
			&& tempDiff < difference))//If length is bigger or diff is smaller
		{
			difference = tempDiff;//Update info
			maxLen = tempLen;
			index = i;
		}
	}
}
