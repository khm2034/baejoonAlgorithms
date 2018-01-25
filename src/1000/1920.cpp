//#include<iostream>
//#include<algorithm>
//
//using namespace std;
//
//typedef long long ll;
//
//void inputData();
//void solution();
//bool check(int i);
//
//int A[100000];
//int n;
//int m;
//int B[100000];
//
//int main()
//{
//	inputData();
//	solution();
//	return 0;
//}
//
//void inputData()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> A[i];
//	}
//	sort(A, A + n);
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		cin >> B[i];
//	}
//}
//
//void solution()
//{
//	for (int i = 0; i < m; i++)
//	{
//		if (check(i))
//			cout << "1\n";
//		else
//			cout << "0\n";
//	}
//}
//bool check(int i)
//{
//	ll right = n - 1;
//	ll left = 0;
//	ll mid;
//	while (right >= left)
//	{
//		mid = (right + left) >> 1;
//
//		if (B[i] == A[mid])
//		{
//			return true;
//		}
//		else if (B[i] > A[mid])
//		{
//			left = mid + 1;
//		}
//		else if (B[i] < A[mid])
//		{
//			right = mid - 1;
//		}
//	}
//	return false;
//}