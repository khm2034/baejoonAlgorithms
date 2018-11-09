#include<cstdio>
#include<stack>
std::stack<int> st;
char c;
int ret;
int main() {
	while (scanf(" %c", &c) != EOF) {
		if (c == '(') st.push(0);
		else {
			int ts=0, t;
			while (1) {
				t = st.top(); st.pop();
				if (!t) {
					if (!ts) st.push(1);
					else {
						ret += (ts + 1);
						st.push(ts);
					}
					break;
				}
				else ts += t;
			}
		}
	}
	printf("%d", ret);
	return 0;
}