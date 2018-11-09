#include<cstdio>
int main() {
	for (int tc = 0, a=0; tc < 3; tc++, a=0) {
		for (int i = 0, t; i < 4; i++) {
			scanf("%d", &t);
			if (t) a++;
		}
		if (a == 0) printf("D\n");
		else if (a == 1) printf("C\n");
		else if (a == 2) printf("B\n");
		else if (a == 3)printf("A\n");
		else printf("E\n");
	}
	return 0;
}