#include<cstdio>
char s[21];
int sum;
int ctoi(char c) {
	if (c >= 'a') return c - 'a' + 1;
	else return c - 'A' + 27;
}
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++) sum += ctoi(s[i]);
	for (int i = 2; i*i <= sum; i++) {
		if (!(sum%i)) {
			printf("It is not a prime word.");
			return 0;
		}
	}
	printf("It is a prime word.");
	return 0;
}