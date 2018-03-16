#include<iostream>
#include<math.h>
using namespace std;

int N;

bool chk(int i)
{
	int diff;
	bool flag = false;
	while (i != 0)
	{
		int tmp = (i / 10);
		if (tmp == 0)
			return true;
		if (!flag)
		{
			diff = (tmp % 10) - (i % 10);
			flag = true;
		}
		else
			if ((tmp % 10) != (i % 10)+ diff)
				return false;

		i = tmp;
	}
	return true;
}

int main()
{
	cin >> N;
	int ret = 0;
	for (int i = 1; i <= N; i++)
	{
		if (chk(i))
			ret++;
	}
	cout << ret << "\n";
	return 0;
}