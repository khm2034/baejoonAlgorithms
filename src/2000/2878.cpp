#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull M, N;
ull arr[100001] = { 0, };
ull result = 0;
ull tmpSum = 0;

void inputData()
{
	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		tmpSum += arr[i];
	}
	sort(arr, arr + N);
}

void solution()
{
	tmpSum -= M;
	ull tmpIdx = 0;
	while (1)
	{
		ull avg = tmpSum / N;
		ull mod = tmpSum % N;
		if (avg <= arr[tmpIdx])
		{
			while (mod != 0)
			{
				result += ((avg + 1) * (avg + 1)) % ((1ull << 64) - 1);
				--mod;
				--N;
			}
			while (N != 0)
			{
				result += (avg * avg) % ((1ull << 64) - 1);
				--N;
			}
			return;
		}
		else
		{
			tmpSum = avg*(N - 1) + (avg - arr[tmpIdx]) + mod;
			result += (arr[tmpIdx] * arr[tmpIdx ]) % ((1ull << 64) - 1);
			--N;
			++tmpIdx;
		}
	}

}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	cout << result << "\n";
	return 0;
}