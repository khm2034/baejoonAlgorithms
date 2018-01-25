#include <iostream>
#define MAXTEXTLENGTH 300050
#define MAXALENGTH 28
using namespace std;

struct stack {
	char arr[MAXTEXTLENGTH] = { 0, };
	int top = 0;

	void push(char ch)
	{
		arr[top++] = ch;
	}

	char pop()
	{
		return arr[--top];
	}

	bool empty()
	{
		return (top == 0) ? true : false;
	}
};

stack st[2];
char A[MAXALENGTH];
char rA[MAXALENGTH];
int aSize = 0;
char text[MAXTEXTLENGTH];
char result[MAXTEXTLENGTH];
int textSize = 0;

void inputData()
{
	scanf("%s %s", A, text);
	//cin >> A >> text;

	int n = 0;
	while (A[aSize++] != '\0') {}
	--aSize;
	while (text[textSize++] != '\0') {}
	--textSize;

	for (int i = 0; i < aSize; i++)
	{
		rA[i] = A[aSize - i - 1];
	}
	rA[aSize] = '\0';
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void solution()
{
	bool flag = true;
	bool find = true;
	
	int le = 0;
	int ri = textSize - 1;
	while(le<=ri && le < textSize && ri >= 0)
	{
		find = true;
		if (flag)
		{
			st[0].push(text[le]);
			if (st[0].top >= aSize)
			{
				for (int j = st[0].top - aSize, k = 0; j < st[0].top; j++, k++)
				{
					if (A[k] != st[0].arr[j])
					{
						find = false;
						break;
					}
				}

				if (find)
				{
					for (int j = 0; j < aSize; j++)
						st[0].pop();
					find = true;
					flag = false;
				}
			}
			le++;
		}
		else
		{
			st[1].push(text[ri]);
			if (st[1].top >= aSize)
			{
				for (int j = st[1].top - aSize, k = 0; j < st[1].top; j++, k++)
				{
					if (rA[k] != st[1].arr[j])
					{
						find = false;
						break;
					}
				}

				if (find)
				{
					for (int j = 0; j < aSize; j++)
						st[1].pop();
					find = true;
					flag = true;
				}
			}
			ri--;
		}
	}

	if (st[0].empty() && !st[1].empty())
	{
		int i = 0;
		while (!st[1].empty())
			result[i++] = st[1].pop();
		result[i] = '\0';
		return;
	}
	if (!st[0].empty() && st[1].empty())
	{
		int i = 0;
		for (i = 0; i < st[0].top; i++)
		{
			result[i] = st[0].arr[i];
		}
		result[i] = '\0';
		return;
	}

	find = true;
	while (find)
	{
		if (st[0].top + st[1].top < aSize) break;

		find = false;
		for (int n = max(0, st[0].top - aSize); n < st[0].top; n++)
		{
			int idx = 0;
			int le = 0;
			int ri = 0;
			for (int m = n; m < st[0].top; m++, le++)
				if (st[0].arr[m] == A[idx]) idx++;
			for (int m = st[1].top - 1; m >= 0 && le + ri < aSize; m--, ri++)
				if (st[1].arr[m] == A[idx]) idx++;

			if (idx == aSize && le + ri == idx)
			{
				find = true;
				for (int m = 0; m < le; m++) st[0].pop();
				for (int m = 0; m < ri; m++) st[1].pop();
				break;
			}
		}
		
	}
	int i = 0;
	for (i = 0; i < st[0].top; i++)
	{
		result[i] = st[0].arr[i];
	}

	while (!st[1].empty())
		result[i++] = st[1].pop();

	result[i] = '\0';
}

void init()
{
	for (int i = 0; i < 2; i++)
	{
		st[i].top = 0;
		for (int j = 0; j < MAXTEXTLENGTH; j++)
			st[i].arr[j] = '\0';
	}
	for (int i = 0; i < MAXALENGTH; i++)
	{
		A[i] = rA[i] = '\0';
	}
	aSize = textSize = 0;
	for (int i = 0; i < MAXTEXTLENGTH; i++)
	{
		text[i] = result[i] = '\0';
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	init();
	inputData();
	solution();
	//cout << result << endl;
	printf("%s\n", result);

	return 0;
}