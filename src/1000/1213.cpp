#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s;
int cnt[26];

void solution()
{
	int odd = 0;
	int idx = 0;
	int size = s.size() - 1;
	int tmp = -1;

	for (int i = 0; i < s.size(); ++i)
		++cnt[s[i] - 'A'];

	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] & 1)
		{
			if (odd >= 1)
			{
				cout << "I'm Sorry Hansoo";
				return;
			}
			tmp = i;
			--cnt[i];
			++odd;
		}
		for (int j = 0; j < cnt[i]; j += 2)
		{
			s[idx] = s[size] = char(i + 'A');
			++idx;
			--size;
		}
	}

	if (tmp != -1)
		s[idx] = char(tmp + 'A');
	cout << s << "\n";
	return;
}

int main()
{
	cin >> s;
	solution();
	return 0;
}