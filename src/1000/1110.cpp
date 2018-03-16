#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int tmp = N;
	int cnt = 0;
	do
	{
		int tmp2;
		tmp2 = tmp / 10 + tmp % 10;
		tmp = (tmp % 10) * 10 + tmp2 % 10;
		cnt++;
	} while (N != tmp);
	cout << cnt << "\n";
	return 0;
}