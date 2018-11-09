#include<cstdio>
#include<stack>
std::stack<char> le, ri;
char s[100001], t, c;;
int N;
int main(){
	scanf("%s", s);
	for (int i = 0; s[i]; i++) le.push(s[i]);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %c", &t);
		if (t == 'L' && !le.empty()) {
			ri.push(le.top());
			le.pop();
		}
		if (t == 'D' && !ri.empty()) {
			le.push(ri.top());
			ri.pop();
		}
		if(t == 'B' && !le.empty()) le.pop();
		if (t == 'P') {
			scanf(" %c", &c);
			le.push(c);
		}
	}
	while (!le.empty()) {
		ri.push(le.top());
		le.pop();
	}
	while (!ri.empty()) {
		printf("%c", ri.top());
		ri.pop();
	}
	return 0;
}