#include<cstdio>
#include<string>
#include<map>
using namespace std;
int N, M, a[50], idx, p[50];
map<int, int> m;
map<string, int> v;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a[i]);
		if (m.find(a[i]) == m.end()) m.insert({ a[i], idx++ });
	}
	string s="";
	for (int i = 0; i < idx; i++) s += "0";
	v.insert({ s, 1 });
	for (int i = 0; i < M; i++) {
		char c;
		scanf(" %c", &c);
		if (c == '+') p[m[a[i]]]++;
		else p[m[a[i]]]--;
		s = "";
		for (int j = 0; j < idx; j++) s += to_string(p[j]);
		if (v.find(s) != v.end()) {
			printf("0");
			return 0;
		}
		v.insert({ s, 1 });
	}
	printf("1");
	return 0;
}