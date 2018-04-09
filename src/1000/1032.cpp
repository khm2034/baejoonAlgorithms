#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

int N;
string s[51];
char ret[51];
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	strcpy(ret, s[0].c_str());
	for (int i = 1; i < N; i++)
		for (int j = 0; s[i][j]; j++)
			if (ret[j] != s[i][j])
				ret[j] = '?';
	cout << ret << "\n";
	return 0;
}