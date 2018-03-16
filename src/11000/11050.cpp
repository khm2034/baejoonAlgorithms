#include <iostream>
using namespace std;

int N;
int K;
int ret;

int cb(int n, int k)
{
	if (k == 0 || n == k)
		return 1;

	return cb(n - 1, k) + cb(n - 1, k - 1);
}

int main()
{
	cin >> N >> K;
	ret = cb(N, K);
	cout << ret << "\n";
	return 0;
}