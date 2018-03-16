#include<iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		cout << s[i];
		if ((i + 1) % 10 == 0)
			cout << "\n";
	}
	return 0;
}