#include <iostream>
#include <string>

using namespace std;

void input();
void solution(string s);

int T;
int t;
string* inputData;
string* outputData;

int main()
{
	input();
	for (t = 0; t < T; t++)
	{
		solution(inputData[t]);
		if (outputData[t].empty())
			outputData[t] = "NO";
	}

	for (t = 0; t < T; t++)
	{
		cout << outputData[t] << endl;
	}
	return 0;
}

void input()
{
	cin >> T;

	inputData = new string[T];
	outputData = new string[T];

	for (t = 0; t < T; t++)
	{
		cin >> inputData[t];
	}
}

void solution(string s)
{
	int len = (int)s.length();
	if (s.empty())
	{
		outputData[t] = "YES";
		return;
	}

	if ((len > 3) && (s[0] == '1' && s[1] == '0' && s[2] == '0'))
	{
		int tmp = 2;
		while (1)
		{
			if (len <= tmp+1)
			{
				return;
			}
			tmp++;
			if ((len >= tmp+1) && (s[tmp] == '1'))
				break;
		}
 		while (1)
		{
			if (len == tmp + 1)
			{ 
				tmp++;
				break;
			}	

			tmp++;
			if ((len >= tmp + 1) && s[tmp] == '0')
				break;
			
		}

		if(s[tmp-2] == '1')
		{
			solution(s.substr(tmp - 1));
			if (!outputData[t].empty())
			{
				return;
			}
		}

		solution(s.substr(tmp));
	}
	else if ((len >= 2) && (s[0] == '0' && s[1] == '1'))
	{
		solution(s.substr(2));
	}
}