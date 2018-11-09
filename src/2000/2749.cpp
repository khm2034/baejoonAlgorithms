#include <iostream>
#define MOD 1000000
#define P (15*MOD/10)
using namespace std;

int fibo[P];
int main()
{
	long long n;
	cin >> n;
	fibo[0] = 0, fibo[1] = 1;
	for (int i = 2; i < P; i++)
		fibo[i] = (fibo[i - 2] + fibo[i - 1]) % MOD;
	cout << fibo[n%(long long)P] << "\n";
	return 0;
}