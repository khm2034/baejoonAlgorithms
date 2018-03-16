#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s;
int arr[11];
int N;

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	cin >> s;
	N = s.length();

	for (int i = 0; i < N; i++)
		arr[i] = s[i] - '0';
	sort(arr, arr + N, cmp);
	
	for (int i = 0; i < N; i++)
		cout << arr[i];
	cout << "\n";
	return 0;
}