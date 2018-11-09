#include<cstdio>
char s[3];
int main() {
	scanf("%s", s);
	if (s[0] == 'A') {
		if (s[1] == '+') printf("4.3");
		if (s[1] == '0') printf("4.0");
		if (s[1] == '-') printf("3.7");
	}
	if (s[0] == 'B') {
		if (s[1] == '+') printf("3.3");
		if (s[1] == '0') printf("3.0");
		if (s[1] == '-') printf("2.7");
	}
	if (s[0] == 'C') {
		if (s[1] == '+') printf("2.3");
		if (s[1] == '0') printf("2.0");
		if (s[1] == '-') printf("1.7");
	}
	if (s[0] == 'D') {
		if (s[1] == '+') printf("1.3");
		if (s[1] == '0') printf("1.0");
		if (s[1] == '-') printf("0.7");
	}
	if (s[0] == 'F') printf("0.0");
	return 0;
}