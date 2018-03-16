#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;
	int ret = 0;
	for (int i = 0; i < n; i++)
		ret += (s[i] - '0');
	cout << ret << "\n";
	return 0;
}