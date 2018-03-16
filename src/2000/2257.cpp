#include <iostream>
using namespace std;

int stack[100] = { 0, };
int top = 0;
char s[200] = { 0, };

inline int getW(char a)
{
	return  (a == 'H') ? 1 : (a == 'C') ? 12 : 16;
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> s;

	int i = 0;
	while (s[i] != NULL)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			stack[top] += getW(s[i]);
		else if (s[i] >= '2' && s[i] <= '9')
			stack[top] += getW(s[i-1])*(s[i] - '0' - 1);
		else if (s[i] == '(')
			++top;
		else if (s[i] == ')')
		{
			if ((s[i + 1] != NULL) && (s[i + 1] >= '2' && s[i + 1] <= '9'))
			{
				stack[top] += stack[top]*(s[i + 1] - '0' - 1);
				++i;
			}
			stack[top - 1] += stack[top];
			stack[top--] = 0;
		}
		++i;
	}

	cout << stack[0] << endl;
	return 0;
}