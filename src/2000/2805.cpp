#include<iostream>
#include<algorithm>
using namespace std;

void inputData();
void solution();
long long treeSum(long long c);

long long num;
long long getTree;
long long result=0;
long long *treeArr;
long long maxValue = 0;

int main()
{
	inputData();
	solution();
	cout << result << endl;
	return 0;
}

void inputData()
{
	cin >> num >> getTree;
	treeArr = new long long[num];
	for (int i = 0; i < num; i++)
	{
		cin >> treeArr[i];
		if (maxValue < treeArr[i])
			maxValue = treeArr[i];
	}
}

void solution()
{
	long long hi = maxValue;
	long long lo = 0;
	long long cut;
	long long tmp;
	while (hi >= lo)
	{
		cut = (hi + lo) / 2;
		tmp = treeSum(cut);
		if (tmp >= getTree)
		{
			if (result < cut)
				result = cut;
			lo = cut+1;
		}
		else
		{
			hi = cut-1;
		}
	}
}

long long treeSum(long long c)
{
	long long sum = 0;
	for (int i = 0; i < num; i++)
	{
		if(treeArr[i] > c)
			sum += (treeArr[i] - c);
	}
	
	return sum;
}