#include <cstdio>
#include <vector>

using namespace std;

long long findMedian(vector<long long> &seq1, vector<long long> &seq2, int count);

int main()
{
	vector<long long> seq1, seq2;
	long long m, n;
	int count;
	scanf("%lld", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &n);
		seq1.push_back(n);
	}
	count = m;
	scanf("%lld", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &n);
		seq2.push_back(n);
	}
	count += m;

	printf("%ld\n", findMedian(seq1, seq2, count));
	return 0;
}

long long findMedian(vector<long long> &seq1, vector<long long> &seq2, int count)
{
	long long median1, median2;
	int cnt = count / 2 + count % 2;
	
	auto it1 = seq1.begin();
	auto it2 = seq2.begin();

	while (it1 != seq1.end() && it2 != seq2.end() && cnt)
	{
		if (*it1 < *it2)
			median1 = *(it1++);
		else
			median1 = *(it2++);
		cnt--;
	}

	while (cnt && it1 != seq1.end())
	{
		median1 = *(it1++);
		cnt--;
	}

	while (cnt && it2 != seq2.end())
	{
		median1 = *(it2++);
		cnt--;
	}

	//if (count % 2)
		return median1;
}