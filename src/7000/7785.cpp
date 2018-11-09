#include<iostream>
#include<map>
#include<string>
#include<functional>
using namespace std;

map<string, bool, greater<string>> m;
int N;
string n, s;
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> n >> s;
		if (s == "enter") m[n] = true;
		else m[n] = false;
	}
	for (auto a : m)
	{
		if (a.second)
			cout << a.first<< "\n";
	}
	return 0;
}