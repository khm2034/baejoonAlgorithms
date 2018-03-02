#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string sArr[20001];
int N;
//template <typename T>
void _swap(string& a, string& b)
{
	string c(a);
	a = b;
	b = c;
}

//template<typename T, typename Comp>
void _sort(string* begin, string* end, bool(*comp)(string a, string b))
{
	if (begin == end)
		return;
	_swap(*begin, *((end - begin) / 2 + begin));
	string* pi = begin;
	string* le = begin + 1;
	string* ri = end - 1;
	while (le <= ri)
	{
		while (le <= ri && !comp(*pi, *le))
			++le;
		while (le <= ri && !comp(*ri, *pi))
			--ri;
		if (le <= ri)
			_swap(*le, *ri);
	}
	_swap(*pi, *ri);
	_sort(begin, ri, comp);
	_sort(ri + 1, end, comp);
}
void inputData()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> sArr[i];
}

bool comp(string a, string b)
{
	if (a.size() == b.size())
		return a<b;

	return a.size() < b.size();
}

void solution()
{
	sort(sArr, sArr + N, comp);
	for (int i = 0; i < N; i++)
	{
		if (i != 0 && sArr[i - 1] == sArr[i])
			continue;
		cout << sArr[i] << "\n";
	}
}

int main()
{
	inputData();
	solution();
	return 0;
}