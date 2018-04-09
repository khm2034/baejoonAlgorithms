#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

pair<char, int> arr[27];
string s;
bool cmp(pair<char, int> a, pair<char, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second > b.second;
}
int main()
{
	cin >> s;
	for (int i = 0; s[i]; i++)
	{
		if (s[i] >= 'a')
			s[i] = s[i] - 'a' + 'A';
		arr[s[i]-'A'].second++;
		arr[s[i]-'A'].first = s[i];
	}
	sort(arr, arr + 27, cmp);
	if (arr[0].second == arr[1].second)
		cout << "?\n";
	else
		cout << arr[0].first << "\n";
	return 0;
}