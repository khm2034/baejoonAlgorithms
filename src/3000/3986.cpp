#include <iostream>
#include <string>
using namespace std;

int N;
string s[100];
char stack[100000];
int top = 0;
int cnt = 0;
void push(char c)
{
	stack[top++] = c;
}

char pop()
{
	return stack[--top];
}

void inputData()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
}

void chk()
{
	if (stack[top - 1] == stack[top - 2])
	{
		pop(); pop();
	}
}
bool empty()
{
	return (top == 0) ? true : false;
}

void solution()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < s[i].length(); j++)
		{
			push(s[i][j]);
			chk();
		}
		if (empty())
			cnt++;
		else
			top = 0;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	inputData();
	solution();
	cout << cnt << "\n";
	return 0;
}