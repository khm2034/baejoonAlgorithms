#include<iostream>
#include<string>
using namespace std;

int main() {
	string s[4];
	long long ret;
	cin >> s[0] >> s[1] >> s[2] >> s[3];
	s[0] += s[1];
	s[2] += s[3];
	ret = stoll(s[0]) + stoll(s[2]);
	cout << ret <<"\n";
	return 0;
}