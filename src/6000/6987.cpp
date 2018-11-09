#include<cstdio>
int w[6], d[6], l[6];
bool func(int a, int b, int c) {
	if (c == 15) return true;
	if (b == 6 && func(a + 1, a + 2, c)) return true;
	else {
		w[a]--, l[b]--;
		if (w[a] >= 0 && l[b] >= 0 && func(a, b + 1, c + 1)) return true;
		w[a]++, l[b]++;

		d[a]--, d[b]--;
		if (d[a] >= 0 && d[b] >= 0 && func(a, b + 1, c + 1)) return true;
		d[a]++, d[b]++;

		w[b]--, l[a]--;
		if (w[b] >= 0 && l[a] >= 0 && func(a, b + 1, c + 1)) return true;
		w[b]++, l[a]++;
	}
	return false;
}
int main() {
	for (int i = 0,sum=0; i < 4; i++, sum = 0) {
		for (int j = 0; j < 6; j++) {
			scanf("%d%d%d", &w[j], &d[j], &l[j]);
			sum += w[j] + d[j] + l[j];
		}
		if (sum == 30 && func(0, 1, 0)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}