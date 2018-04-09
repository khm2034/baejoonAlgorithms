#include<iostream>
#include<algorithm>
using namespace std;

int A, B, T;
int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> A >> B;
		if (A < B)	swap(A, B);
		int ret = A * B;
		while (1)
		{
			int t = A % B;
			if (!t) break;
			A = B;
			B = t;
		}
		cout << ret / B << "\n";
	}
	return 0;
}