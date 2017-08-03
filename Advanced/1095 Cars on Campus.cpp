#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*MAXTIME is the total seconds of one day.*/
#define MAXTIME 3600 * 24

typedef struct record
{
	char plateNumber[8];
	int time;
	int status;
}Record;

/*timeStatus array is used to store the number of parking cars in one day.*/
int timeStatus[MAXTIME];

char bestAnswer[10000][8]; //Store best answers
int bestPtr = -1; //The pointer

int bestDuration = 0; //Store the longest time

/*---------------------------------------------------------------------------------------------------*/
/*cmp function is used to help with qsort function which is a library function. */

int cmp(const void* a, const void* b)
{
	Record ta = *(Record*)a;
	Record tb = *(Record*)b;
	int c = strcmp(ta.plateNumber, tb.plateNumber); //First the alphabetical
	if(c < 0)
		return -1;
	else if(c > 0)
		return 1;
	else //Next is time
		return ta.time - tb.time;
}

/*Following five functions will be used in main function to be helpful.*/

void query(int K);
void getRealCarNum();
void findBest(Record* records, int N);
int getInRecord(Record* records, int* i, int m); //Get last in, if not, return true
int getOutRecord(Record* records, int* i, int m); //Get first out, if not, return false

/*---------------------------------------------------------------------------------------------------*/
/*main function is used to deal with the relationship of other functions ,input and output.*/

int main()
{
	/*N is the number of records and K is the number of queries.*/
	int N, K;
	/*status[4] is used to store the status(in or out) temporarily.*/
	char status[4];
	int hour, minute, second;
	Record* records = (Record*)malloc(sizeof(Record) * 10000);
	scanf("%d %d", &N, &K);
	/*It is easier to transform hour,minute and second into seconds.*/
	for(int i = 0; i < N; i++)
	{
		scanf("%s %d:%d:%d %s", records[i].plateNumber, &hour,
			&minute, &second, status);
		records[i].time = 3600 * hour + 60 * minute + second;
		records[i].status = (status[0] == 'i') ? 1 : 0; //in:1 out:0;
	}
	/*qsort function is used to making a quick sorting in an alphabetical and time order.*/
	qsort(records, N, sizeof(Record), cmp);
	findBest(records, N);//Find best record
	getRealCarNum();
	query(K);

	/*After that,output all of their plate numbers in a line and the longest time period.*/
	for(int i = 0; i <= bestPtr; i++)
		printf("%s ", bestAnswer[i]);
	/*It is also important to output in a correct format.*/
	printf("%02d:%02d:%02d\n", bestDuration / 3600, bestDuration % 3600 / 60, bestDuration % 60);

	return 0;
}

/*---------------------------------------------------------------------------------------------------*/
/*findBest function is used to find the longest duration in records.*/

void findBest(Record* records, int N)
{
	int i = 0, j = 0;//outTime, inTime INDEX(VALID)
	int maxIndex; //Same ID last index
	char plateNum[8];
	int duration;
	while(i < N)
	{
	    strcpy(plateNum, records[i].plateNumber);
        duration = 0;
		for(maxIndex = i; (maxIndex < N) && (strcmp(records[i].plateNumber
			, records[maxIndex].plateNumber) == 0); maxIndex++ ); //Get max index
		/*It is necessary to know which record is wrong and which is right,
		  it is needed to call other two functions to help judging the record.*/
		while(1)
		{

			if(!getInRecord(records, &i, maxIndex))
				break;
			j = i;
			if(!getOutRecord(records, &i, maxIndex))
				break;
			/*It is by the way to achieve the timeStatus array in order to help next searching.*/
			/*If it is out,the number-1,and else the number+1.*/
			timeStatus[records[j].time]++;
			timeStatus[records[i].time]--;
			duration += records[i].time - records[j].time;
		}
		if(duration > bestDuration)//Get the best
		{
			bestDuration = duration;
			bestPtr = 0;
			strcpy(bestAnswer[bestPtr], plateNum);
		}
		else if(duration == bestDuration) //Add another record
			strcpy(bestAnswer[++bestPtr], plateNum);
        //i = maxIndex + 1;
	}
}

/*---------------------------------------------------------------------------------------------------*/
/*query function is used to search the number of parking cars before the time pointed chosen.*/
/*It can save much time because the number is one-to-one correspondenced in the array.*/

void query(int K)
{
	int hour, minute, second;
	for(int i = 0; i < K; i++)
	{
		scanf("%d:%d:%d", &hour, &minute, &second);
		printf("%d\n", timeStatus[hour * 3600 + minute * 60 + second]);//Use index to query
	}
}

/*---------------------------------------------------------------------------------------------------*/
/*getInRecord function is used to judge whether this record is available and an in is paired with an out.*/

int getInRecord(Record* records, int* i, int m) //Find last in
{
	while((*i < m) && (records[*i].status == 0)) //When meet out first
		(*i)++;	//Leave it out
	if((*i) >= m) //The situation that cannot find IN
		return 0;
	else
    {
		while((*i < m) && (records[*i].status == 1))//Just find last in
			(*i)++;
		(*i)--;
    }
	return 1;
}

/*---------------------------------------------------------------------------------------------------*/
/*getOutRecord function is used to help judging.*/

int getOutRecord(Record* records, int* i, int m) //Find first out
{
	while(*i < m && (records[*i].status == 1)) //When meet out, stop
		(*i)++;
	return (*i) < m;
}

/*---------------------------------------------------------------------------------------------------*/
/*getRealCarNum function make use of cyclic increasing to put cars number into the time point array.*/

void getRealCarNum()
{
	for(int i = 1; i < MAXTIME; i++)
		timeStatus[i] += timeStatus[i-1];
}