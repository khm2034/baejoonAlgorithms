//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void input();
//int solution();
//
//int map[12][12];
//int N;
//int M;
//
//int main()
//{
//	int T;
//	cin >> T;
//
//	for (int t = 0; t < T; t++)
//	{
//		input();
//		cout << solution() << endl;
//	}
//	return 0;
//}
//
//void input()
//{
//	for (int i = 0; i < 12; i++)
//		for (int j = 0; j < 12; j++)
//			map[i][j] = -1;
//
//
//	cin >> N >> M;
//	for (int i = 1; i <= N; i++)
//	{
//		string tmp;
//		cin >> tmp;
//		for (int j = 1; j <= M; j++)
//		{
//			if (tmp[j-1] == '.')
//				map[i][j] = 0;
//		}
//	}
//}
//
//int solution(int i)
//{
//	for (int j = 1; j <= M; j++)
//	{
//		if(map)
//	}
//}

//int solution()
//{
//	int result1 = 0;
//	int result2 = 0;
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= M; j += 2)
//		{
//			if (map[i][j] == 0)
//				result1++;
//			else
//			{
//				if (map[i][j] == -1 && map[i - 1][j] == -1 && map[i+1][j] == -1
//					&& map[i][j + 2] == -1 && map[i - 1][j + 2] == -1 && map[i+1][j+2]== -1
//					&& map[i][j+1] == 0)
//					result1++;
//			}
//		}
//	}
//
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 0; j <= M; j += 2)
//		{
//			if (map[i][j] == 0)
//				result2++;
//			else
//			{
//				if (map[i][j] == -1 && map[i - 1][j] == -1 && map[i + 1][j] == -1
//					&& map[i][j + 2] == -1 && map[i - 1][j + 2] == -1 && map[i + 1][j + 2] == -1
//					&& map[i][j + 1] == 0)
//					result2++;
//			}
//		}
//	}
//
//	return result1 > result2 ? result1 : result2;
//}