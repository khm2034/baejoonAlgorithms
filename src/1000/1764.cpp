#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
vector<string> c;
map<string, bool> m;
int N, M;
int main() {
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s] = true;
	}
	for (int i = 0; i < M; i++) {
		cin >> s;
		if(!(m.find(s) == m.end()))
			c.push_back(s);
	}
	sort(c.begin(), c.end());
	cout << c.size() << "\n";
	for (auto v : c) cout << v << "\n";
	return 0;
}