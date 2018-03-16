#include <iostream>
using namespace std;

int cnt[10];
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int mul = a*b*c;
	
	while (mul != 0)
	{
		int tmp = mul % 10;
		cnt[tmp]++;
		mul = mul / 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << cnt[i] << "\n";
	}
	return 0;
}