#include<iostream>
using namespace std;

int cnt = 0;
struct stack
{
	int arr[300001] = { 0, };
	int top = 0;

	void push(int i)
	{
		arr[top++] = i;
		++cnt;
	}

	int pop()
	{
		++cnt;
		return arr[top--];
	}

	bool empty()
	{
		return (top == 0) ? true : false;
	}
};

stack s[6];
int N, P;

void chk(stack& st, int pl)
{
	if (st.empty())
	{
		st.push(pl);
	}
	else
	{
		while (!st.empty() && st.arr[st.top - 1] > pl )
		{
			st.pop();
		}

		if (st.empty())
		{
			st.push(pl);
		}
		else if (st.arr[st.top - 1] != pl)
		{
			st.push(pl);
		}
	}
}

void solution()
{
	int line, pl;
	for (int i = 0; i < N; i++)
	{
		cin >> line >> pl;

		switch (line)
		{
		case 1:
			chk(s[0], pl);
			break;
		case 2:
			chk(s[1], pl);
			break;
		case 3:
			chk(s[2], pl);
			break;
		case 4:
			chk(s[3], pl);
			break;
		case 5:
			chk(s[4], pl);
			break;
		case 6:
			chk(s[5], pl);
			break;
		default:
			break;
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> P;
	solution();
	cout << cnt << "\n";
	return 0;
}