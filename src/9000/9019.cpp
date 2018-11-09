#include<iostream>
#include<string>
#include<queue>
using namespace std;

int a, b, T;
int D(int a) {
	return (a * 2) % 10000;
}
int S(int a) {
	return a == 0 ? 9999 : a - 1;
}
int L(int a) {
	int t = a / 1000;
	return  (a % 1000)*10 + t;
}
int R(int a) {
	int t = a % 10;
	return ((a - t) / 10 + (t * 1000));
}
int(*f[4])(int) = { D, S, L, R };
string s[4] = { "D", "S", "L", "R" };
void func(int a, int b) {
	queue<pair<int, string>> q;
	bool visit[10000] = { 0, };
	q.push({ a, "" });
	visit[a] = true;
	while (!q.empty()) {
		pair<int, string> t = q.front(); q.pop();
		if (t.first == b) {
			printf("%s\n", t.second.c_str());
			break;
		}
		for (int i = 0, ta; i < 4; i++) {
			ta = f[i](t.first);
			if (!visit[ta]) {
				visit[ta] = true;
				q.push({ ta, t.second + s[i] });
			}
		}
	}
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &a, &b);
		func(a, b);
	}
	return 0;
}