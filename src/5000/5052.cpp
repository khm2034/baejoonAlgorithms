#include<iostream>
#include<string>
using namespace std;

struct trie 
{
	string data;
	trie* ch[10];

	trie()
	{
		data = "";
		for (int i = 0; i < 10; i++)
			ch[i] = NULL;
	}
	
	~trie()
	{
		for (int i = 0; i < 10; i++)
		{
			if (ch[i] != NULL)
				delete ch[i];
		}
	}
};
trie root;
int T;
int N;
string num[10001];

void inputData()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];
}

void init()
{
	N = 0;
	for (int i = 0; i < 10001; i++)
		num[i] = "";
	
	for (int i = 0; i < 10; i++)
	{
		if (root.ch[i] != NULL)
			delete root.ch[i];
		root.ch[i] = NULL;
	}
}

bool solution()
{
	for (int i = 0; i < N; i++)
	{
		trie* t = &root;
		int j = 0;
		for (j = 0; num[i][j] != NULL; j++)
		{
			if (t->ch[num[i][j] - '0'] == NULL)
			{
				t->ch[num[i][j] - '0'] = new trie();
			}

			if (t->data != "")
				return false;

			t = t->ch[num[i][j] - '0'];
		}

		for (int i = 0; i < 10; i++)
		{
			if (t->ch[i] != NULL)
				return false;
		}

		t->data = num[i];
	}
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (int tc = 0; tc < T; ++tc)
	{
		init();
		inputData();
		if (solution())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}