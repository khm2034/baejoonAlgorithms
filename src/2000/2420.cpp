#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll N, M;
int main()
{
	scanf("%lld%lld", &N, &M);
	N > M ? printf("%lld\n", N - M) : printf("%lld\n", M - N);
	return 0;
}