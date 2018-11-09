#include<cstdio>
int N, c;
int main() {
	scanf("%d", &N);
	for (int i = 1, t = i/10; i <= N; i++, t=i/10) {
		int diff = t % 10 - i % 10;
		bool f = true;
		while (f && t > 9) {
			if ((t / 10) % 10 != t % 10 + diff) f = false;
			t /= 10;
		}
		if (f) c++;
	}
	printf("%d", c);
	return 0;
}