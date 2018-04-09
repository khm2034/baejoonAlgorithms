#include<iostream>
#include<algorithm>
using namespace std;

int L, C;
char arr[16];
char ret[16];

void func(int l, int idx, int a, int b)
{
	if (l == L)
	{
		if(a >=1 && b>=2)
			cout << ret << "\n";
		return;
	}
	for (int i = idx; i < C; i++)
	{
		if (arr[i] == 'a' || arr[i] == 'e'
			|| arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
		{
			ret[l] = arr[i];
			a++;
			func(l + 1, i + 1, a, b);
			a--;
		}
		else
		{
			b++;
			ret[l] = arr[i];
			func(l + 1, i + 1, a, b);
			b--;
		}
		ret[i] = '\0';
	}
}
int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(arr, arr + C);
	func(0, 0, 0, 0);
	return 0;
}