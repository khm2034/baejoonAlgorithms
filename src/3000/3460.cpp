#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		int in;
		cin >> in;
		int i, cnt;
		for (i = 1, cnt = 0; i <= in; i = i << 1, cnt++)
		{
			if (in&i)
				cout << cnt << " ";
		}
		cout << "\n";
	}
	return 0;
}