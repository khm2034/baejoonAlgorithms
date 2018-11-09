#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int a[500001], b[500001], N, H,a_c[500002], b_c[500002];
vector<int> calc;
int main()
{
	scanf("%d%d", &N, &H);
	for (int i = 0, t; i < N; i++)
	{
		scanf("%d", &t);
		if (i & 1) b[t]++;
		else a[t]++;
	}
	for (int i = 1, a_s = 0, b_s = 0; i < H; i++)
	{
		a_c[i] = N/2 - a_s; a_s += a[i];
		b_c[i] = N/2 - b_s; b_s += b[i];
	}
	for (int i = 1; i <= H; i++)
		calc.push_back(a_c[i] + b_c[H - i+1]);
	sort(calc.begin(), calc.end());
	int min = calc[0] , cnt = 1;
	for (int i = 1; i < calc.size(); i++, cnt++)
		if (min != calc[i]) break;
	printf("%d %d", min, cnt);
	return 0;
}
