#include<cstdio>
int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		float a;
		scanf("%f", &a);
		char c;
		while (1) {
			scanf("%c", &c);
			if (c == '\n') break;
			if (c == '@') a *= 3;
			if (c == '%') a += 5;
			if (c == '#') a -= 7;
		}
		printf("%.2f\n", a);
	}
	return 0;
}