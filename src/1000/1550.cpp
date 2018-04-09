#include<iostream>
#include<string>
using namespace std;

string s;
int ret;
int main()
{
	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		int t;
		if (s[i] >= 'A')
			t = s[i] - 'A' + 10;
		else
			t = s[i] - '0';
		ret = ret * 16 + t;
	}
	cout << ret << "\n";
	return 0;
}