#include <cstdio>
#include <vector>

using namespace std;

vector<int> initArray;
vector<int> cmpArray;

bool isInsertion(vector<int> array);
void mergeSort(vector<int> array);
// Merge 1-2-4-...2^n element-sublist, without recursion
// Guess the length of merged sublist
void merge(vector<int>& array, int temp[], int leftStart, int rightStart, int rightEnd);
void mergePass(vector<int>& array, int temp[], int n, int length);

int main()
{
	int n, val;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &val);
		initArray.push_back(val);
	}
	for (int i = 0; i < n; i++) 
	{
		scanf("%d", &val);
		cmpArray.push_back(val);
	}
	if (!isInsertion(initArray))
	{
		printf("Merge Sort\n");
		mergeSort(initArray);
	}
	return 0;
}

bool isInsertion(vector<int> array)
{
	int i, j;
	bool flag = false;
	for (i = 1; i < array.size(); i++)
	{
		int temp = array[i];
		for (j = i; j > 0; j--)
		{
			if (temp < array[j - 1])
				array[j] = array[j - 1];
			else
				break;
		}
		array[j] = temp;
		if (array == cmpArray)
		{
			flag = true;
			printf("Insertion Sort\n");
			break;
		}
	}
	i++;
	if (flag)
	{
		int temp = array[i];
		for (j = i; j > 0; j--)
		{
			if (temp < array[j - 1])
				array[j] = array[j - 1];
			else
				break;
		}
		array[j] = temp;
		for (int i = 0; i < array.size() - 1; i++)
			printf("%d ", array[i]);
		printf("%d\n", array.back());
	}
	return flag;
}

void mergeSort(vector<int> array)
{
	int len = 1;
	int* tempArray = new int[array.size()];
	while (len < array.size())
	{
		mergePass(array, tempArray, array.size(), len);
		len *= 2;
		if (array == cmpArray)
		{
			if(len < array.size())
				mergePass(array, tempArray, array.size(), len);
			for (int i = 0; i < array.size() - 1; i++)
				printf("%d ", array[i]);
			printf("%d\n", array.back());
		}
	}
}

void mergePass(vector<int>& array, int temp[], int n, int length)
{
	int i, j;
	for (i = 0; i <= n - 2 * length; i += 2 * length)
		merge(array, temp, i, i + length, i + 2 * length - 1);
	if (i + length < n)
		merge(array, temp, i, i + length, n - 1);
	else
	{
		for (j = i; j < n; j++)
			temp[j] = array[j];
	}
}

void merge(vector<int>& array, int temp[], int leftStart, int rightStart, int rightEnd)
{
	int leftEnd, numElement, tempPtr;
	int i;
	leftEnd = rightStart - 1;
	numElement = rightEnd - leftStart + 1;
	tempPtr = leftStart;

	while (leftStart <= leftEnd && rightStart <= rightEnd)
	{
		if (array[leftStart] < array[rightStart])
			temp[tempPtr++] = array[leftStart++];
		else
			temp[tempPtr++] = array[rightStart++];
	}

	while (leftStart <= leftEnd)
		temp[tempPtr++] = array[leftStart++];
	while (rightStart <= rightEnd)
		temp[tempPtr++] = array[rightStart++];

	for (i = 0; i < numElement; i++, rightEnd--)
		array[rightEnd] = temp[rightEnd];
}