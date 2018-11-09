#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> v;
int main() {
	string s;
	cin >> s;
	for (int i = 0, l = s.length(); i < l; i++)
		v.push_back(s.substr(i, l));
	sort(v.begin(), v.end());
	for (auto a : v)
		cout << a << "\n";
	return 0;
}