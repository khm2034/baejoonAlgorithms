#include<cstdio>
int a[5], ret;
int main() {
	for (int i = 0; i < 5; i++) scanf("%d", &a[i]);
	while (1) {
		if (!a[0] && a[1]) a[0]++, a[1]--;
		if (!a[4] && a[3]) a[4]++, a[3]--;
		if (!a[2] && (a[1] || a[3])) {
			if (a[1] > a[3]) a[2]++, a[1]--;
			else if (a[3] > a[1]) a[2]++, a[3]--;
			else {
				if (a[0] >= a[4]) a[2]++, a[1]--;
				else a[2]++, a[3]--;
			}
		}
		if (a[0] && a[2] && a[4]) {
			ret++;
			a[0]--, a[2]--, a[4]--;
		}
		else break;
	}
	printf("%d", ret);
	return 0;
}