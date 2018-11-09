#include<cstdio>
#include<map>
int A, B, cnt;
int main() {
	scanf("%d%d", &A, &B);
	for (int x = A; x <= B; x++) {
		std::map<int, bool> m;
		for (int d = 10, f, b, y; x/d; d *= 10) {
			f = x / d;
			b = x % d;
			for (int i = f; i; i /= 10) b *= 10;
			y = b + f;
			if (y <= B && y > x) {
				if (m.find(y) != m.end()) continue;
				m[y] = 1;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}