#include <iostream>

using namespace std;

void input();
void solution();
void result();

int testcase;
int in[1001];
int out[1001];

int main()
{
	input();
	solution();
	result();
	
	return 0;
}

void input()
{
	cin >> testcase;
	for (int i = 0; i < testcase; i++) 
	{
		int testnum;
		cin >> testnum >> in[i];
		out[i] = 0;
	}
}

void solution()
{
	int check1 = 1;
	int check2 = 1;
	int temp;

	for (int i = 0; i < testcase; i++)
	{
		while (true)
		{
			temp = check1;
			check1 = check2;
			check2 = (check2 + temp) % in[i];

			out[i]++;

			if (check1 == 1 && check2 == 1)
				break;
		}
	}
}

void result()
{
	for (int i = 0; i < testcase; i++)
	{
		cout << i + 1 << ' ' << out[i] << endl;
	}
}