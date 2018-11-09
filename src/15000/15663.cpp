#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
map<string, bool> m;
int N, M, arr[9], visit[9], ret[9];
void func(int c) {
	if (c == M) {
		string t = to_string(ret[0]);
		for (int i = 1; i < c; i++) t = t + " " + to_string(ret[i]);
		if (m.find(t) == m.end()) {
			m.insert({ t, true });
			printf("%s\n", t.c_str());
		}
	}
	for (int i = 0; i < N; i++) {
		if (visit[i]) continue;
		visit[i] = 1;
		ret[c] = arr[i];
		func(c + 1);
		visit[i] = 0;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	sort(arr, arr + N);
	func(0);
	return 0;
}