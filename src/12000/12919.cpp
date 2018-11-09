#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int func(string s, string t) {
	if (s.size() == t.size()) {
		if (s == t) return 1;
		return 0;
	}
	string ts = t;
	if (t.back() == 'A') {
		ts.pop_back();
		if (func(s, ts)) return 1;
	}
	if (t[0] == 'B') {
		ts = t;
		reverse(ts.begin(), ts.end());
		ts.pop_back();
		if (func(s, ts)) return 1;
	}
	return 0;
}
int main() {
	string s, t;
	cin >> s >> t;
	cout << func(s, t);
	return 0;
}