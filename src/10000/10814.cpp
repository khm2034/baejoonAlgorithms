#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Info
{
	int age;
	string name;
	int id;
};

Info arr[100001];
int N;

void inputData()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i].age >> arr[i].name;
		arr[i].id = i;
	}
}

bool comp(Info a, Info b)
{
	if (a.age != b.age)
		return a.age < b.age;
	return a.id < b.id;
}

void solution()
{
	sort(arr, arr + N, comp);

	for (int i = 0; i < N; ++i)
		cout << arr[i].age << " " << arr[i].name << "\n";
}

int main()
{
	inputData();
	solution();
	return 0;
}