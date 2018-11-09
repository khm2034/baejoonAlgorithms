#include<iostream>
#include<string>
using namespace std;
string a, b, op;
int main() {
	cin >> a >> op >> b;
	if (op == "+") {
		int l1 = a.length(), l2 = b.length();
		if (l1 == l2) cout << "2" << a.erase(0, 1);
		else if (l1 > l2)  cout << a.erase(l1 - l2, l2) << b;
		else cout << b.erase(l2 - l1, l1) << a;
	}
	else cout << a << b.erase(0,1);
	return 0;
}