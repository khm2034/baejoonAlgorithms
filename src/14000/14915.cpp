#include<cstdio>
int main() {
	int m, n, idx=0, t;
	char s[30];
	scanf("%d%d", &m, &n);
	if (!m) printf("0");
	else {
		while (m) {
			t = m % n;
			if (t >= 10) s[idx++] = t - 10 + 'A';
			else s[idx++] = t + '0';
			m /= n;
		}
		for (int i = idx - 1; i >= 0; i--) printf("%c", s[i]);
	}
	return 0;
}