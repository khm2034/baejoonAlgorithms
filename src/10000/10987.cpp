#include<cstdio>
int cnt;
char c;
int main() {
	while(scanf("%c", &c) != EOF){
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
	}
	printf("%d", cnt);
	return 0;
}