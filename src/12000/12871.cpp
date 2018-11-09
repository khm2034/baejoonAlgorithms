#include<iostream>
#include<string>
using namespace std;
string s, t, fs, ft;
int sl, tl,lcm;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int main() {
	cin >> s >> t;
	sl = s.size(), tl = t.size();
	if (sl > tl) lcm = sl * tl / gcd(sl, tl);
	else lcm = sl * tl / gcd(tl, sl);
	for (int i = 0; i < lcm / sl; i++) fs += s;
	for (int i = 0; i < lcm / tl; i++) ft += t;
	if (fs == ft) cout << "1";
	else cout << "0";
	return 0;
}