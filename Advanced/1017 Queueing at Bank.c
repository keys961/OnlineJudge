#include <stdio.h>
#include <stdlib.h>

#define INFINITY 1<<30

struct TouristInfo
{
	long arrivingTime;//In Second
	long waitingTime; //In Second
};

void input(struct TouristInfo* tourists ,int N);
void initialize(int* queue, int K);
double calcTime(struct TouristInfo* tourists, int N, int* queue, int K);
int getQueuePtr(int* queue, int K);
int cmp(const void* a, const void* b);

int main()
{
	struct TouristInfo* tourists = NULL;
	int queue[101]; //Using windows to record the finish time
	int N, K;
	scanf("%d %d", &N, &K);
	tourists = (struct TouristInfo*)malloc(sizeof(struct TouristInfo) * N);
    initialize(queue, K);
	input(tourists ,N);
    qsort(tourists, N, sizeof(struct TouristInfo), cmp);

    printf("%.1f\n", calcTime(tourists, N, queue, K));


	return 0;
}

void input(struct TouristInfo* tourists, int N)
{
    //int realN = N;
	int hour, minute, second, waitingMinite;
	for(int i = 0; i < N; i++)
	{
		scanf("%d:%d:%d %d", &hour, &minute, &second, &waitingMinite);
		tourists[i].arrivingTime = 3600 * hour + 60 * minute + second;
		tourists[i].waitingTime = 60 * waitingMinite;
	}
}

void initialize(int *queue, int K)
{
    //queue.finishTime = (int*)malloc(sizeof(int) * K);
    for(int i = 0; i < K; i++)
        queue[i] = 8 * 3600;
}

int cmp(const void* a, const void* b)
{
    if((*(struct TouristInfo*)a).arrivingTime - (*(struct TouristInfo*)b).arrivingTime > 0)
        return 1;
    else
        return -1;
}

double calcTime(struct TouristInfo* tourists, int N, int* queue, int K)
{
    int queuePtr = 0;
    double totalTime = 0.0;
    double waitingTime;
    int realN = 0;

    for(int i = 0; i < N; i++)
    {
        if(tourists[i].arrivingTime > 17 * 3600)
            break;

        queuePtr = getQueuePtr(queue, K);

        (realN)++;
        waitingTime = queue[queuePtr] - tourists[i].arrivingTime <= 0 ? 0 :
            (queue[queuePtr] - tourists[i].arrivingTime);
        totalTime += waitingTime * 1.0 / 60.0;
        if(waitingTime == 0)
            queue[queuePtr] = tourists[i].arrivingTime + tourists[i].waitingTime;
        else
            queue[queuePtr] += tourists[i].waitingTime;

    }
    return totalTime / (realN);
}

int getQueuePtr(int* queue, int K)
{
    long minTime = INFINITY;
    int minPtr = 0;
    for(int i = 0; i < K; i++)
    {
        if(queue[i] < minTime)
        {
            minPtr = i;
            minTime = queue[i];
        }
    }
    return minPtr;
}
