#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void input();
void solution();

long long inputMin;
long long inputMax;

long long maxPrime;

bool* prime;
bool* result;
vector<long long> primeArr;
int cnt = 0;

int main()
{
	input();
	solution();
	cout << cnt << endl;
	return 0;
}

void input()
{
	cin >> inputMin >> inputMax;
	maxPrime = (long long)sqrt(inputMax) + 1;
	prime = new bool[maxPrime];
	result = new bool[inputMax - inputMin + 1];
}

void solution()
{
	fill_n(prime, maxPrime, true);
	fill_n(result, inputMax - inputMin + 1, true);

	for (int i = 2; i <= maxPrime; i++)
	{
		if (prime[i])
		{
			for (int j = i + i; j <= maxPrime; j += i)
				prime[j] = false;
		}
	}

	for (long long i = 2; i <= maxPrime; i++)
	{
		if (prime[i])
			primeArr.push_back(i*i);

	}

	for (int i = 0; i < primeArr.size(); i++)
	{
		long long tMin, tMax;
		if (inputMin % primeArr[i] != 0)
			tMin = (inputMin / primeArr[i] + 1) * primeArr[i];
		else
			tMin = inputMin;

		for (long long j = tMin; j <= inputMax; j += primeArr[i])
		{
			if (result[j - inputMin])
				result[j - inputMin] = false;
		}
	}

	for (int i = 0; i < inputMax - inputMin + 1; i++)
	{
		if (result[i])
			cnt++;
	}
}