#include <iostream>
#include <string>
using namespace std;

int T;
string s;
int ret = 0;
int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> s;
		int cnt=0;
		for (int i = 0; s[i]; i++)
		{
			if (s[i] == 'O')
				ret += ++cnt;
			else
				cnt = 0;
		}
		cout << ret << "\n";
		ret = 0;
	}
}