#include<iostream>
#include <string>
using namespace std;

int cnt[26];
int main()
{
	freopen("input.txt", "r", stdin);
	char tmp;
	while (scanf("%c", &tmp) != EOF)
	{
		if (tmp >= 'a' && tmp <= 'z')
			++cnt[tmp - 'a'];
	}

	int max = cnt[0];
	for (int i = 1; i < 26; ++i)
		if (max < cnt[i])
			max = cnt[i];

	for (int i = 0; i < 26; ++i)
		if (cnt[i] == max)
			cout << (char)(i + 'a');
	cout << "\n";
	return 0;
}