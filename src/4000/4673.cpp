#include <iostream>
using namespace std;

bool visit[20001];
int main()
{
	for (int i = 1; i <= 10000; i++)
	{
		int result, tmp;
		result = tmp = i;
		while (tmp != 0)
		{
			result += tmp % 10;
			tmp /= 10;
		}
		visit[result] = true;
	}
	for (int i = 1; i <= 10000; i++)
		if (!visit[i])
			cout << i << "\n";
	return 0;
}