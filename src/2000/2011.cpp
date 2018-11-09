#include<iostream>
#include<string>
using namespace std;
string s;
int dp[5001] = { 1 }, f;
int main() {
	cin >> s;
	for (int i = 1; i <= s.size(); i++) {
		if (i > 1 && (s[i - 2] == '0' || s[i-2]>'2') && s[i - 1] == '0') {
			f = 1;
			break;
		}
		if (i > 1 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] >= '0'&& s[i - 1] < '7'))
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		if (s[i - 1] != '0') dp[i] = (dp[i] + dp[i - 1]) % 1000000;
	}
	if (f) cout << "0";
	else cout << dp[s.size()];
	return 0;
}