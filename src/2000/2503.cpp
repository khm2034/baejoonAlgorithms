#include<cstdio>
struct question { int n, s, b; };
int N, c;
question q[101];
int main() {
	scanf("%d", &N);
	for (int i = 0,a,b,c; i < N; i++) {
		scanf("%d%d%d", &a, &b, &c);
		q[i] = { a,b,c };
	}
	for (int i = 123; i <= 999; i++) {
		bool count[10] = { false }, f = true;
		for (int j = i, t; f&&j; j /= 10) {
			t = j % 10;
			if (!t || count[t]) f = !f;
			count[t] = true;
		}
		for (int j = 0; f && j < N; j++) {
			int ts = 0, tb = 0;
			for (int k = q[j].n, l = i; k; k /= 10, l/=10) {
				if (k % 10 == l % 10) ts++;
				else if (count[k % 10]) tb++;
			}
			if (!(ts == q[j].s && tb == q[j].b)) f = !f;
		}
		if (f) c++;
	}
	printf("%d", c);
	return 0;
}