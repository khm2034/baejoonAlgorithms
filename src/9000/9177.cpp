#include<iostream>
#include<string.h>
#include<memory.h>
using namespace std;

char src1[300], src2[300], dest[500];
char s[500];
int dp[300][300];
int T, s1_l, s2_l, dl;
bool func(int l_1, int l_2, int idx)
{
	if (idx == dl)
		return true;
	int &ret = dp[l_1][l_2];
	if (ret != -1) return ret;
	ret = false;
	if (l_1 < s1_l && dest[idx] == src1[l_1])
		if (func(l_1 + 1, l_2, idx + 1))
			return true;
	if (l_2 < s2_l && dest[idx] == src2[l_2])
		if (func(l_1, l_2 + 1, idx + 1))
			return true;
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++)
	{
		memset(dp,-1, sizeof(dp));
		scanf("%s%s%s", src1, src2, dest);
		dl = strlen(dest); s1_l = strlen(src1); s2_l = strlen(src2);
		if (func(0, 0, 0))
			printf("Data set %d: yes\n", tc);
		else
			printf("Data set %d: no\n", tc);
	}
	return 0;
}