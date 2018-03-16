#include<iostream>
#include <string>
using namespace std;

int N;
string s;

char stack[51];
int top = 0;

void push(char c)
{
	stack[top++] = c;
}
char pop()
{
	return stack[--top];
}
bool empty()
{
	return top == 0;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		top = 0;
		cin >> s;
		for (int j = 0; s[j]; j++)
		{
			if (s[j] == '(')
				push('(');
			else if (s[j] == ')')
			{
				if (top == 0)
				{
					top = 1;
					break;
				}
				pop();
			}
		}

		if (empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}