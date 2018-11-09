#include<cstdio>
#include<stack>
std::stack<int> st[7];
int N, P, a, b, c;
int main() {
	scanf("%d%d", &N, &P);
	while (N--) {
		scanf("%d%d", &a, &b);
		if (st[a].empty() || st[a].top() < b) {
			c++;
			st[a].push(b);
		}
		else if (st[a].top() > b) {
			while (!st[a].empty() && st[a].top() > b) {
				st[a].pop();
				c++;
			}
			if (st[a].empty() || st[a].top() < b) {
				st[a].push(b);
				c++;
			}
		}
	}
	printf("%d", c);
	return 0;
}