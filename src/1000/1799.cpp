#include<cstdio>
#include<algorithm>
using namespace std;
int N, ret[2], m_idx[2];
pair<int, int> m[2][105];
void func(int cnt, int idx, int left, int right, int type)
{
	if (cnt + m_idx[type] - idx <= ret[type]) return;
	if (idx == m_idx[type])
	{
		ret[type] = max(ret[type], cnt);
		return;
	}
	for (int i = idx; i < m_idx[type]; i++)
	{
		if (cnt + m_idx[type] - i <= ret[type]) return;
		pair<int, int> &t = m[type][i];
		if (!(left << t.second & 1 << (t.first + 10))
			&& !(right >> t.second & 1 << (t.first + 10)))
			func(cnt + 1, i + 1,
				left | 1 << (t.first - t.second + 10), right | 1 << (t.first + t.second + 10), type);
	}
	ret[type] = max(ret[type], cnt);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &t);
			if (t)
				if ((i + j)&1)
					m[0][m_idx[0]++] = { j,i };
				else
					m[1][m_idx[1]++] = { j,i };
		}
	func(0, 0, 0, 0, 0); func(0, 0, 0, 0, 1);
	printf("%d\n", ret[0] + ret[1]);
	return 0;
}