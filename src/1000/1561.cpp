#include<iostream>
using namespace std;
typedef long long ll;

ll N, M;
int time[10001];
int main()
{
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < M; i++)
		scanf("%d", &time[i]);
	if (N < M) printf("%lld", N);
	else
	{
		ll le = 0, ri = 2e13, mid, cnt;
		while (le <= ri)
		{
			cnt = 0, mid = (le + ri) / 2;
			for (int i = 0; i < M; i++)
				cnt += mid / time[i] +1;
			if (cnt < N)
				le = mid + 1;
			else if (cnt >= N)
				ri = mid - 1;
		}
		if (N == cnt)
		{
			for (int i = M - 1; i >= 0; i--)
				if (!(mid%time[i]))
				{
					printf("%d\n", i + 1);
					break;
				}
		}
		else if (N < cnt)
		{
			for (int i = M - 1; i >= 0; i--)
				if (!(mid%time[i]))
					if (N == cnt--)
					{
						printf("%d\n", i+1);
						break;
					}
		}
		else
		{
			for (int i = 0; i < M; i++)
				if (!((mid+1)%time[i]))
					if (N == ++cnt)
					{
						printf("%d\n", i + 1);
						break;
					}
		}
	}
	return 0;
}