#include<iostream>
#include<string>
using namespace std;

string s;
int main()
{
	cin >> s;
	int ret = 0;
	for (int i = 0; s[i]; i++)
	{
		switch (s[i])
		{
		case 'A':case 'B':case 'C':
			ret += 3;
			break;
		case 'D':case 'E':case 'F':
			ret += 4;
			break;
		case 'G':case 'H':case 'I':
			ret += 5;
			break;
		case 'J':case 'K':case 'L':
			ret += 6;
			break;
		case 'M':case 'N':case 'O':
			ret += 7;
			break;
		case 'P':case 'Q':case 'R':case 'S':
			ret += 8;
			break;
		case 'T':case 'U':case 'V':
			ret += 9;
			break;
		case 'W':case 'X':case 'Y':case 'Z':
			ret += 10;
			break;
		}
	}
	cout << ret << "\n";
	return 0;
}