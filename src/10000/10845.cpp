#include<cstdio>
#include<queue>
using namespace std;
int n, t;
queue<int> q;
char s[10];
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf(" %s", s);
		if (s[0] == 'p') {
			if (s[1] == 'u') {
				scanf("%d", &t);
				q.push(t);
			}
			else {
				if (q.empty()) printf("-1\n");
				else {
					printf("%d\n", q.front());
					q.pop();
				}
			}
		}
		else if (s[0] == 's') printf("%d\n", q.size());
		else if (s[0] == 'e') printf("%d\n", q.empty() ? 1 : 0);
		else if (s[0] == 'f') printf("%d\n", q.empty() ? -1 : q.front());
		else if (s[0] == 'b') printf("%d\n", q.empty() ? -1 : q.back());
	}
	return 0;
}