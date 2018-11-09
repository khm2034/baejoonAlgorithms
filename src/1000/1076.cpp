#include<iostream>
#include<map>
#include<string>
using namespace std;
typedef pair<int, int> pii;
map<string, pii> m;
long long ret;
int main() {
	m.insert({ "black", {0, 1} });
	m.insert({ "brown",{ 1, 10 } });
	m.insert({ "red",{ 2, 100 } });
	m.insert({ "orange",{ 3, 1000 } });
	m.insert({ "yellow",{ 4, 10000 } });
	m.insert({ "green",{ 5, 100000 } });
	m.insert({ "blue",{ 6, 1000000 } });
	m.insert({ "violet",{ 7, 10000000 } });
	m.insert({ "grey",{ 8, 100000000 } });
	m.insert({ "white",{ 9, 1000000000 } });
	string s;
	for (int i = 0; i < 3; i++) {
		cin >> s;
		pii t = m[s];
		if (i != 2) ret = ret * 10 + t.first;
		else ret *= t.second;
	}
	cout << ret;
	return 0;
}