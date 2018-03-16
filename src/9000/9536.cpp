#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Node {
	string s;
	int hash = 0;
	bool chk = true;

	void setHash()
	{
		int k = 1;
		for (int i = s.size()-1; i >= 0; --i)
		{
			hash += (((s[i] - 'a')% 1000001) * k) % 1000001;
			k *= 337;
			k %= 1000001;
		}
		hash = hash % 1000001;
	}
};
char tmp[100000];

Node rec[100];
int recIdx = 0;

Node ani[100];
int aniIdx = 0;

char question[] = "what does the fox say?";

bool table[1000001] = { 0, };

void inputData()
{
	scanf(" %[^\n]s", tmp);
	int i = 0, j=0;
	char t[100];
	while (1)
	{
		if (tmp[i] == '\0')
		{
			++i;
			t[j] = '\0';
			rec[recIdx].s = t;
			rec[recIdx].setHash();
			++recIdx;
			j = 0;
			break;
		}

		if (tmp[i] == ' ')
		{
			++i;
			t[j] = '\0';
			rec[recIdx].s = t;
			rec[recIdx].setHash();
			++recIdx;
			j = 0;
			continue;
		}
		t[j] = tmp[i];
		++j; ++i;
	}

	i = 0; j = 0;
	while(1)
	{
		scanf(" %[^\n]s", tmp);
		if (strcmp(tmp, question) == 0)
			break;

		int bcnt = 0;
		while (1)
		{
			if (tmp[i] == '\0')
			{
				t[j] = '\0';
				ani[aniIdx].s = t;
				ani[aniIdx].setHash();
				table[ani[aniIdx].hash] = true;
				++aniIdx;
				i = 0; j = 0;
				break;
			}

			if (tmp[i] == ' ')
			{
				++bcnt;
				++i;
				continue;
			}
			
			if (bcnt == 2)
			{
				t[j] = tmp[i];
				++j;
			}
			++i;
		}
	}
}

string solve()
{
	string ret = "";
	for (int i = 0; i < recIdx; i++)
	{
		if (table[rec[i].hash])
			rec[i].chk = false;
	}

	for (int i = 0; i < recIdx; ++i)
	{
		if (rec[i].chk)
			ret += rec[i].s + " ";
	}
	
	return ret;
}

void init()
{
	tmp[0] = '\0';

	for (int i = 0; i < 100; i++)
	{
		rec[i].chk = ani[i].chk = true;
		rec[i].hash = ani[i].hash = 0;
		rec[i].s = ani[i].s = "";
	}
	recIdx = aniIdx = 0;

	for (int i = 0; i < 1000001; ++i)
		table[i] = false;

}

int main()
{
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		init();
		inputData();
		string s = solve();
		printf("%s\n", s.c_str());
	}
	return 0;
}