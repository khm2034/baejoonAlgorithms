#include<cstdio>
#include<stack>
std::stack<int> st;
char s[31];
int ret;
bool func(int ty, int v) {
	int t = 0;
	while (1) {
		if (st.empty()) return false;
		int tm = st.top(); st.pop();
		if (tm > 1) t += tm;
		else if (tm != ty) return false;
		else {
			if (!t) t = 1;
			t *= v;
			st.push(t);
			return true;
		}
	}
}
int main() {
	scanf("%s", s);
	bool f = true;
	for(int i=0; f&&s[i]; i++){
		if (s[i] == '(') st.push(0);
		else if (s[i] == ')') f = func(0, 2);
		else if (s[i] == '[') st.push(1);
		else f = func(1, 3);
	}
	while (!st.empty() && f) {
		int t = st.top(); st.pop();
		if (t < 2) f = false;
		ret += t;
	}
	printf("%d", f?ret:0);
	return 0;
}