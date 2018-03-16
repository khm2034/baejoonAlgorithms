#include <iostream>
#define MOD 1000000007
using namespace std;
typedef long long ll;

ll fact[4000001];
ll inv[4000001];
ll ret;
int N, K;

ll p(ll x, ll n)
{
	ll tmp;
	if (n == 1)
		return x;
	if (n == 0)
		return 1;

	tmp = p(x, n/2)%MOD;

	if(n&1)
		return (x*((tmp*tmp)% MOD))%MOD;
	else
		return (tmp*tmp) % MOD;
}

int main()
{
	fact[0] = fact[1] = 1;
	for (int i = 2; i < 4000001; i++)
	{
		fact[i] = (fact[i - 1] * i) % MOD;
	}
	inv[4000000] = p(fact[4000000], MOD - 2) % MOD;
	for (int i = 3999999; i >= 1; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % MOD;

	cin >> N >> K;
	if (K == 1)
		cout << N << "\n";
	else if (K == 0)
		cout << "1\n";
	else
		cout << ((fact[N] * inv[K])%MOD * inv[N - K])%MOD << "\n";

	return 0;
}