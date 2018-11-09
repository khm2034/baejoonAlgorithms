#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll N, M, cnt, num, arr[21], t[21], p[21];
bool visit[21];
void func1(ll n, ll k) {
	if (n == 1) {
		for (int i = 1; i <= N; i++)
			if (!visit[i]) cout << i << " ";
		return;
	}
	for (int i = 1;  i <= N; i++) {
		if (visit[i]) continue;
		if (k <= p[n-1]) {
			cout << i << " ";
			visit[i] = 1;
			func1(n - 1, k);
			return;
		}
		else k -= p[n-1];
	}
}
void func2(ll n, ll k) {
	if (n == N) {
		cout << k+1 << "\n";
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		if (i == t[n]) {
			visit[i] = 1;
			func2(n + 1, k);
			return;
		}
		else
			k += p[N-n-1];
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	p[0] = 1LL;
	for (ll i = 1; i <= 20; i++) p[i] = p[i - 1] * i;
	for (ll i = 0; i < N; i++) arr[i] = i + 1;
	if (M & 1) {
		cin >> num;
		func1(N, num);
	}
	else{
		for (ll i = 0; i < N; i++) cin >> t[i];
		func2(0, 0);
	}
	return 0;
}