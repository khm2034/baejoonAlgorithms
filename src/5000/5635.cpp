#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<pair<string, string>> v;
int N;
string s, d, m, y;
int main() {
	ios_base::sync_with_stdio();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s >> d >> m >> y;
		if (d.length() == 1) d = "0" + d;
		if (m.length() == 1) m = "0" + m;
		v.push_back({ y + m + d, s });
	}
	sort(v.begin(), v.end());
	cout << v[N - 1].second << "\n";
	cout << v[0].second << "\n";
	return 0;
}