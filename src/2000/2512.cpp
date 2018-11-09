#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[10001], M, sum;
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	scanf("%d", &M);
	sort(arr, arr + N);
	if (sum < M) printf("%d\n", arr[N - 1]);
	else
	{
		int le = 0, ri = arr[N - 1], mid, ret = 0;
		while (le <= ri)
		{
			mid = (le + ri) / 2;
			sum = 0;
			for (int i = 0; i < N; i++)
				if (arr[i] <= mid) sum += arr[i];
				else sum += mid;

			if (sum < M) le = mid + 1;
			else if (sum > M) ri = mid - 1;
			else {
				ret = mid;
				break;
			}
		}
		if (!ret) ret = ri;
		printf("%d\n", ret);
	}
	return 0;
}