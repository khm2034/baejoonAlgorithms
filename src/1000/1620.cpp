#include <iostream>
#include <string>
#include <map>
using namespace std;

void inputData();
void solution();
bool chk(string s);
map<string, int> pok;
string pokArr[100001];
string question[100000];
int n;
int m;

int main()
{
	inputData();
	solution();
	return 0;
}

void inputData()
{
	cin >> n >> m;

	for (int i = 1; i < n + 1; i++)
	{
		cin >> pokArr[i];
		pok.insert(pair<string, int>(pokArr[i], i));
	}

	for (int i = 0; i < m; i++)
	{
		cin >> question[i];
	}
}

void solution()
{
	for (int i = 0; i < m; i++)
	{
		if (chk(question[i]))
			cout << pokArr[stoi(question[i])] << "\n";
		else
			cout << pok.find(question[i])->second << "\n";
	}
}

bool chk(string s)
{
	if (s[0] >= '1' && s[0] <= '9')
		return true;

	return false;
}