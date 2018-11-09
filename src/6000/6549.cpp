#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int n;
ll h[100001];
ll get_area(int le, int ri)
{
	if (le == ri)
		return h[le];
	int mid = (le + ri) / 2;
	ll ret = max(get_area(le, mid), get_area(mid + 1, ri));

	ll t = min(h[mid], h[mid + 1]);
	ll t_a = t * 2;
	int t_le = mid, t_ri = mid+1;
	while (t_le > le || t_ri < ri)
	{
		if (t_le > le && (t_ri == ri || h[t_le-1] > h[t_ri+1]))
			t_le--, t = min(t, h[t_le]);
		else
			t_ri++, t = min(t, h[t_ri]);
		t_a = max(t_a, t*(t_ri - t_le+1));
	}
	return max(ret, t_a);
}
int main()
{
	while (1)
	{
		scanf("%d", &n);
		if (!n) break;
		for (int i = 0; i < n; i++)
			scanf("%lld", &h[i]);
		printf("%lld\n", get_area(0, n - 1));
	}
	return 0;
}