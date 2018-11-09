#include<cstdio>
#include<stack>
using namespace std;
int n, t;
char s[7];
stack<int> st;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf(" %s", s);
		if (s[0] == 'p') {
			if (s[1] == 'u') {
				scanf("%d", &t);
				st.push(t);
			}
			else {
				if (st.empty()) printf("-1\n");
				else {
					printf("%d\n", st.top());
					st.pop();
				}
			}
		}
		else if (s[0] == 't') printf("%d\n", st.empty() ? -1 : st.top());
		else if (s[0] == 's') printf("%d\n", st.size());
		else if (s[0] == 'e') printf("%d\n", st.empty() ? 1 : 0);
	}
	return 0;
}