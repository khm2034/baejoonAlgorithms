#include<cstdio>
#include<stack>
using namespace std;
int T;
char s[51];
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf(" %s", s);
		stack<char> st;
		bool f = true;
		for (int i = 0; s[i]; i++) {
			if (s[i] == '(') st.push('(');
			else {
				if (st.empty()) {
					f = false;
					break;
				}
				st.pop();
			}
		}
		if (!st.empty() || !f) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}