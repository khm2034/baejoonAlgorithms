#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string S, T;
int main() {
	cin >> S >> T;
	while (S.size() < T.size()) {
		char c = T.back();
		T.pop_back();
		if (c == 'B') reverse(T.begin(), T.end());
	}
	if (S == T) cout << "1";
	else cout << "0";
	return 0;
}