#include <iostream>
using namespace std;

typedef long long ll;

ll N, K, Q;

void swap(ll& a, ll& b)
{
	ll tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void solution()
{
	ll a, b;
	ll aD, bD;
	for (int i = 0; i < Q; ++i)
	{
		ll result = 0;
		scanf("%lld%lld", &a, &b);
		if (K == 1)
		{
			if (a > b)
				printf("%lld\n", a - b);
			else
				printf("%lld\n", b-a);
			continue;
		}
		while (a != b)
		{
			if (a > b)
				swap(a, b);
			b = (b + K - 2) / K;
			++result;
		}
		printf("%lld\n", result);
	}
}

void init()
{
	N = K = Q = 0;

}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	cin >> N >> K >> Q;
	solution();
	return 0;
}

//#include <iostream>
//using namespace std;
//
//typedef long long ll;
//
//ll N, K, Q;
//
//ll dp[100];
//int dpIdx = 0;
//ll pow(ll a, ll b)
//{
//	if (dp[b] != 0)
//		return dp[b];
//	return dp[b] = dp[b - 1] * a;
//}
//
//ll getDepth(ll a)
//{
//	register int le = 0;
//	register int ri = dpIdx - 1;
//	register int mid;
//	while (le <= ri)
//	{
//		mid = (le + ri) / 2;
//		if (mid == 0)
//			return 0;
//
//		if (dp[mid] >= a && dp[mid - 1] < a)
//			return mid;
//		else if (dp[mid] < a)
//			le = mid + 1;
//		else
//			ri = mid - 1;
//	}
//}
//void setDepth()
//{
//	register int dep = 0;
//	register int num = 1;
//	register ll j = 0;
//	dp[0] = 1;
//	for (dep = 0, j = 1; dep < 1001; dep++, j++)
//	{
//		if (N <= num)
//		{
//			dpIdx = dep + 1;
//			return;
//		}
//		num += pow(K, j);
//	}
//}
//
//void solution()
//{
//	setDepth();
//	register ll a, b;
//	register ll aD, bD;
//	for (register int i = 0; i < Q; i++)
//	{
//		ll result = 0;
//		cin >> a >> b;
//		if (K == 1)
//		{
//			if (a > b)
//				printf("%lld", a - b);
//			else
//				printf("%lld", b-a);
//			continue;
//		}
//		aD = getDepth(a);
//		bD = getDepth(b);
//
//		if (aD > bD)
//		{
//			register ll tmp = a;
//			a = b;
//			b = tmp;
//			tmp = aD;
//			aD = bD;
//			bD = tmp;
//		}
//
//		while (aD != bD)
//		{
//			bD--;
//			++result;
//			b = (b + K - 2) / K;
//		}
//
//		while (a != b)
//		{
//			result += 2;
//			a = (a + K - 2) / K;
//			b = (b + K - 2) / K;
//		}
//		printf("%lld\n", result);
//	}
//}
//
//void init()
//{
//	N = K = Q = dpIdx = 0;
//
//	for (int i = 0; i<100; i++)
//		dp[i] = 0;
//}
//
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	init();
//	cin >> N >> K >> Q;
//	solution();
//	return 0;
//}