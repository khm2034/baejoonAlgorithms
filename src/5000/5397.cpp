#include <iostream>
#define MAXSIZE 1000001
using namespace std;

int TC;
char s[1000001];
int sLength;

class stack
{
public:
	int top;
	char arr[MAXSIZE];

	stack()
	{
		top = 0;
		for (int i = 0; i < MAXSIZE; i++)
		{
			arr[i] = NULL;
		}
	}

	char pop()
	{
		return arr[--top];
	}

	void push(char item)
	{
		arr[top++] = item;
	}

	void init()
	{
		top = 0;
		for (int i = 0; i < MAXSIZE; i++)
		{
			arr[i] = NULL;
		}
	}
	
	void print()
	{
		for (int i = 0; i < top; i++)
			cout << arr[i];
	}

	void reversePrint()
	{
		for (int i = top-1; i >= 0; i--)
			cout << arr[i];
	}
};

stack s1;
stack s2;

void init()
{
	sLength = 0;
	s1.init();
	s2.init();
	for (int i = 0; i < MAXSIZE; i++)
		s[i] = NULL;
}

void strLength()
{
	for (int i = 0; s[i] != NULL; i++)
		sLength++;
}

void inputData()
{
	init();

	cin >> s;
	strLength();
}

void solution()
{
	for (int i = 0; i < sLength; i++)
	{
		switch (s[i])
		{
		case '<':
			if (s1.top == 0)
				break;
			s2.push(s1.pop());
			break;
		case '>':
			if (s2.top == 0)
				break;
			s1.push(s2.pop());
			break;
		case '-':
			if(s1.top == 0)
				break;
			s1.pop();
			break;
		default:
			s1.push(s[i]);
			break;
		}
	}

}

int main()
{
	cin >> TC;
	for (int t = 0; t < TC; t++)
	{
		inputData();
		solution();
		s1.print();
		s2.reversePrint();
		cout << "\n";
		
	}
	return 0;
}