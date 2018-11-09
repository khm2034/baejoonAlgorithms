#include<cstdio>
int main() {
	int n;
	scanf("%d", &n);
	if (n != 1){
		for (int i = 2; i <= n;) {
			if (!(n%i)) {
				printf("%d\n", i);
				n /= i;
			}
			else i++;
		}
	}
	return 0;
}