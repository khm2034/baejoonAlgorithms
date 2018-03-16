#include <iostream>
using namespace std;

bool hashArr[99008];
char s[101];
int idx = 0;
int cnt = 0;

int h(const char* s) {
	int ret = 0;
	while (*s) {
		ret = (ret * 4827 + (*s) * 31) % 99007;
		s++;
	}
	return ret;
}

void init()
{
	for (int i = 0; i < 99008; i++)
		hashArr[i] = false;
	hashArr[h("c=")] = true;
	hashArr[h("c-")] = true;
	hashArr[h("dz=")] = true;
	hashArr[h("d-")] = true;
	hashArr[h("lj")] = true;
	hashArr[h("nj")] = true;
	hashArr[h("s=")] = true;
	hashArr[h("z=")] = true;
}

char* getS(int st, int l)
{
	char* tmp = new char[l + 1];
	int x = 0;
	for (int i = st; i < st + l; i++, x++)
		tmp[x] = s[i];
	tmp[l] = '\0';
	return tmp;
}

void solve()
{
	for (int i = 0; s[i] != NULL;)
	{
		char* t = getS(i, 2);
		if (hashArr[h(t)])
		{
			++cnt;
			i += 2;
			continue;
		}
		
		t = getS(i, 3);
		if (hashArr[h(t)])
		{
			++cnt;
			i += 3;
			continue;
		}
		++cnt;
		++i;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	init();
	cin >> s;

	solve();
	cout << cnt << endl;
	return 0;
}