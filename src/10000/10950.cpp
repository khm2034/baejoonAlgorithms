#include <iostream>
using namespace std;

int T;
int a, b;
int main()
{
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return 0;
}