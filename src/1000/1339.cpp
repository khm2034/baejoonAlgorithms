#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, cnt, ret;
char s[11][10];
int visit[26], perm[10] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
vector<int> v;
int calc() {
	int sum = 0;
	for (int i = 0, t = 0; i < N; i++, t=0) {
		for (int j = 0; s[i][j]; j++)
			t = t * 10 + visit[s[i][j] - 'A'];
		sum += t;
	}
	return sum;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", s[i]);
		for (int j = 0; s[i][j]; j++)
			if (!visit[s[i][j] - 'A']) {
				visit[s[i][j] - 'A'] = 1;
				cnt++;
				v.push_back(s[i][j] - 'A');
			}
	}
	do {
		for (int i = 0; i < cnt; i++) visit[v[i]] = perm[i];
		ret = max(ret, calc());
	} while (prev_permutation(perm, perm + cnt));
	printf("%d\n", ret);
	return 0;
}