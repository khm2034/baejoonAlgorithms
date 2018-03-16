#include<iostream>
#include <string>

using namespace std;

struct Trie
{
	Trie* ch[26];
	string data;

	Trie()
	{
		data = "";
		for (int i = 0; i < 26; i++)
			ch[i] = NULL;
	}
	~Trie()
	{
		for (int i = 0; i < 26; i++)
		{
			if (ch[i] != NULL)
				delete ch[i];
		}
	}
};

Trie root;

int N;
int cnt;
string word[100001];

void init()
{
	cnt = 0;
	for (int i = 0; i < 26; i++)
	{
		if (root.ch[i] != NULL)
			delete root.ch[i];
		root.ch[i] = NULL;
	}

	for (int i = 0; i < 100001; i++)
		word[i] = "";
}

void inputData()
{
	for (int i = 0; i < N; i++)
		cin >> word[i];
		//scanf("%s", word[i]);
}

void makeTrie(string w)
{
	Trie* t = &root;
	for (int j = 0; w[j] != NULL; j++)
	{
		if (t->ch[w[j] - 'a'] == NULL)
			t->ch[w[j] - 'a'] = new Trie();

		t = t->ch[w[j] - 'a'];
	}
	t->data = w;
}

void solve()
{
	for (int i = 0; i < N; i++)
		makeTrie(word[i]);

	for (int i = 0; i < N; i++)
	{
		Trie* t = &root;
		t = t->ch[word[i][0] - 'a'];
		cnt++;
		for (int j = 1; word[i][j] != NULL; j++)
		{
			int c = 0;
			if(t->data == "")
				for (int k = 0; k < 26; k++)
				{
					if (t->ch[k] != NULL)
						c++;
				}
			if (c == 1)
			{
				t = t->ch[word[i][j] - 'a'];
				continue;
			}
			else
			{
				t = t->ch[word[i][j] - 'a'];
				cnt++;
			}
		}
	}
}

int main()
{
	freopen("input.txt", "r", stdin);

	while(scanf("%d", &N) != EOF)
	{
		init();
		inputData();
		solve();
		printf("%.2lf\n", (double)cnt / (double)N);
	}
	return 0;
}