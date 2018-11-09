#include<cstdio>
#include<stack>
int n, now=1,idx;
std::stack<int> st;
char s[200001];
int main() {
	scanf("%d", &n);
	for (int i = 0, t; i < n; i++) {
		scanf("%d", &t);
		for (; now <= t; now++) {
			st.push(now);
			s[idx++] = '+';
		}
		if (st.empty() || st.top() != t) {
			printf("NO");
			return 0;
		}
		else {
			st.pop();
			s[idx++] = '-';
		}
	}
	for (int i = 0; s[i]; i++) printf("%c\n", s[i]);
	return 0;
}