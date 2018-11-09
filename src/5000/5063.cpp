#include<cstdio>
int N, r, e, c;
int main() {
	scanf("%d", &N);
	while (N--) {
		scanf("%d%d%d", &r, &e, &c);
		if (r < e - c) printf("advertise\n");
		else if (r > e - c) printf("do not advertise\n");
		else printf("does not matter\n");
	}
	return 0;
}