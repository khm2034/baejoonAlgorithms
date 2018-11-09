#include<cstdio>
int a, b;
int main() {
	while (1) {
		scanf("%d%d", &a, &b);
		if (!a && !b) break;
		if (!(b%a)) printf("factor\n");
		else if (!(a%b)) printf("multiple\n");
		else printf("neither\n");
	}
	return 0;
}