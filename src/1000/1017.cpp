#include <iostream>
#include <cmath>

using namespace std;

void input();
void solution();
void getPrime();
void solution();

int n;
int* inputData;
bool prime[2001];

int main()
{
	return 0;
}

void input()
{
	cin >> n;

	inputData = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> inputData[i];
	}
}

void getPrime()
{
	fill_n(prime, 2001, true);

	for (int i = 2; i <= sqrt(2001); i++)
	{
		if (prime[i])
		{
			for (int j = i+i; j <= 2001; j += i)
				prime[j] = false;
		}
	}
}

void solution()
{
	getPrime();
}
//
//#include<iostream>
//using namespace std;
//
//void Per(int N, int r);
//int checking();
//void swap(int i, int j);
//
//int cnt = 0;
//int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int visit[11] = { 0, };
//int main()
//{
//	Per(10, 10);
//	cout << cnt;
//	return 0;
//}
//
//void Per(int N, int r)
//{
//	if (r == 1)
//	{
//		if (checking() == 1)
//		{
//			for (int j = 0; j < 10; j++)
//			{
//				cout << arr[j] << " ";
//			}
//			cnt++;
//			cout << endl;
//		}
//
//		fill_n(visit, 11, 0);
//		return;
//	}
//
//	for (int i = 0; i < r; i++)
//	{
//		swap(i, r - 1);
//		Per(N, r - 1);
//		swap(i, r - 1);
//	}
//}
//
//void swap(int i, int j)
//{
//	int temp;
//	temp = arr[i];
//	arr[i] = arr[j];
//	arr[j] = temp;
//}
//
//int checking()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		visit[arr[i]] = 1;
//		switch (arr[i])
//		{
//		case 1:
//			if (visit[3] == 1 && visit[9] == 1)
//				continue;
//			else
//				return 0;
//		case 2:
//			if (visit[3] == 1 && visit[9] == 1)
//				continue;
//			else
//				return 0;
//		case 4:
//			if (visit[5] == 1 && visit[10] == 1)
//				continue;
//			else
//				return 0;
//		case 5:
//			if (visit[1] == 1)
//				continue;
//			else
//				return 0;
//		case 7:
//			if (visit[5] == 1)
//				continue;
//			else
//				return 0;
//		case 8:
//			if (visit[6] == 1 && visit[7] == 1 && visit[9] == 1)
//				continue;
//			else
//				return 0;
//		case 10:
//			if (visit[3] == 1 && visit[5] == 1 && visit[9] == 1)
//				continue;
//			else
//				return 0;
//		default:
//			continue;
//		}
//	}
//
//	return 1;
//}