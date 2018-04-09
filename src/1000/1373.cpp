#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

string N, ret;
int main()
{
	cin >> N;
	if (N == "0")
	{
		printf("0\n");
		return 0;
	}
	int i, l = N.length();
	for (i = l-1; i >= 2; i = i - 3)
	{
		if (N[i - 2] == '0')
			if (N[i - 1] == '0')
				if (N[i] == '0')
					ret += '0';
				else
					ret += '1';
			else
				if (N[i] == '0')
					ret += '2';
				else
					ret += '3';
		else
			if (N[i - 1] == '0')
				if (N[i] == '0')
					ret += '4';
				else
					ret += '5';
			else
				if (N[i] == '0')
					ret += '6';
				else
					ret += '7';
	}

	if (i == 0)
		ret += '1';
	else if (i == 1)
		if (N[i] == '0')
			ret += '2';
		else
			ret += '3';
	l = ret.size();
	for (int i = l - 1; i >= 0; i--)
		printf("%c", ret[i]);
	printf("\n");
	return 0;
}