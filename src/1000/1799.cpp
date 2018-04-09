//#include <iostream>
//#include <cstdio>
//using namespace std;
//
//int N;
//int map[11][11];
//int ret = -1e9;
//
//void func(int x, int y, int cnt, int left, int right, int n_left, int n_right)
//{
//	if (x == N - 1 && y == N - 1)
//	{
//		if (ret < cnt)
//			ret = cnt;
//		return;
//	}
//	for (int i = 1; i < 1 << N; i = i << 1)
//	{
//		if (left&i)
//			n_left |= i << 1;
//		if (right&i)
//			n_right |= i >> 1;
//	}
//
//	if (!map[y][x])
//		if (x >= N-1)
//			func(0, y + 1, cnt, n_left, n_right, 0, 0);
//		else
//			func(x + 1, y, cnt, left, right, n_left, n_right);
//	else
//	{
//		if (!(left & 1 << x) && !(right & 1 << x))
//		{
//			n_left |= 1 << (x+1);
//			n_right |= 1 << (x - 1);
//			map[y][x] = 0;
//			if (x >= N-1)
//				func(0, y + 1, cnt+1, n_left, n_right, 0, 0);
//			else
//				func(x + 2, y, cnt+1, left, right, n_left, n_right);
//			map[y][x] = 1;
//			n_left &= ~(1 << (x+1));
//			n_right &= ~(1 << (x -1));
//			if (x >= N-1)
//				func(0, y + 1, cnt, n_left, n_right, 0, 0);
//			else
//				func(x + 1, y, cnt, left, right, n_left, n_right);
//		}
//		else
//		{
//			if (x >= N-1)
//				func(0, y + 1, cnt, n_left, n_right, 0, 0);
//			else
//				func(x + 1, y, cnt, left, right, n_left, n_right);
//		}
//	}
//
//}
//int main()
//{
//	scanf("%d", &N);
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < N; j++)
//			scanf("%d", &map[i][j]);
//	func(0, 0, 0, 0, 0, 0, 0);
//	printf("%d\n", ret);
//	return 0;
//}