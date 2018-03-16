#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template <typename It>
void _swap(It &a, It &b) 
{
	It c(a); a = b; b = c;
}
template <typename It, typename Comp>
void _sort(It begin, It end, Comp comp)
{
	if (begin == end)
		return;
	_swap(*begin, *((end - begin) / 2 + begin));
	It pi = begin;
	It le = begin + 1;
	It ri = end - 1;
	while (le <= ri) {
		while (le <= ri && !comp(*pi, *le))
			le++;
		while (le <= ri && !comp(*ri, *pi))
			ri--;
		if (le <= ri)
			_swap(*le, *ri);
	}
	_swap(*pi, *ri);
	_sort(begin, ri, comp);
	_sort(ri + 1, end, comp);
}

struct Info
{
	string name;
	int ko;
	int en;
	int ma;
};

Info arr[100001];
int N;
int tmp[10] = { 1,4,2,3,5,2,1,2,5,7 };
void inputData()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i].name >> arr[i].ko >> arr[i].en >> arr[i].ma;
}

bool comp(Info a, Info b)
{
	if (a.ko != b.ko)
		return a.ko > b.ko;
	if (a.en != b.en)
		return a.en < b.en;
	if (a.ma != b.ma)
		return a.ma > b.ma;
	return a.name < b.name;
}

void solution()
{
	_sort(arr, arr + N, comp);

	for (int i = 0; i < N; ++i)
		cout << arr[i].name << "\n";
}

int main()
{
	inputData();
	solution();
	return 0;
}