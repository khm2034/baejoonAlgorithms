#include <cstdio>
using namespace std;
typedef long long ll;

ll A, B, V;
int main()
{
	scanf("%lld%lld%lld", &A, &B, &V);
	ll t = V - A;
	ll diff = A - B;
	if (V <= diff)
		printf("1\n");
	else
	{
		ll tmp = t % diff;
		if (tmp == 0)
			printf("%lld\n", t/diff+1);
		else
			printf("%lld\n", t / diff + 2);
	}
	return 0;
}