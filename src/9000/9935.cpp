#include<iostream>
#include<string.h>
using namespace std;

struct stack
{
	char s[1000001] = { 0, };
	int top = 0;

	void push(char c)
	{
		s[top++] = c;
	}
	char pop()
	{
		return s[--top];
	}
	
	bool empty()
	{
		return (top == 0) ? true : false;
	}
};

stack s;
char tmps[1000001];
char b[40];
char rb[40];
stack tmp;

void solution()
{
	bool chk = true;
	int bLen = strlen(b);
	for (int i = 0; i < bLen; i++)
		rb[i] = b[bLen - i-1];
	for (int i = 0; tmps[i] != '\0'; i++)
	{
		s.push(tmps[i]);
	}

	while (chk)
	{
		int i = s.top;
		bool remove = false;
		for (int j = i - bLen; j < i; j++)
		{
			if (s.s[j] != b[j - (i - bLen)])
				break;

			if (j == i - 1)
				remove = true;
		}
		if (remove)
		{
			for (int j = 0; j < bLen; j++)
			{
				s.pop();
			}
			for (int j = 0; j < bLen; j++)
			{
				s.push(tmp.pop());
			}
		}
		else
		{
			tmp.push(s.pop());
		}

		if (s.empty())
			chk = false;
	}

	while(!tmp.empty())
		s.push(tmp.pop());
}


int main()
{
	freopen("input.txt", "r", stdin);
	cin >> tmps >> b;
	solution();
	if (s.empty())
		cout << "FRULA\n";
	else
	{
		s.s[s.top] = '\0';
		cout << s.s << "\n";
	}
	
	return 0;
}