//#include <iostream>
//using namespace std;
//
//int n;
//int dp[1001][4][2];
//
//void inputData()
//{
//	cin >> n;
//	for (int i = 0; i < n+1; i++)
//		for (int j = 0; j < 4; j++)
//			for (int k = 0; k < 2; k++)
//				dp[i][j][k] = -1;
//}
//
//int solution(int cur, int state, int cnt)
//{
//	if (cnt >= 2)
//		return 0;
//	int& ret = dp[cur][state][cnt];
//	
//	if (ret != -1)
//		return ret;
//	if (cur == n-1)
//		return 1;
//
//	if (state == 0)
//		return ret = (solution(cur + 1, 0, cnt) + solution(cur + 1, 1, cnt + 1) + solution(cur + 1, 2, cnt)) % 1000000;
//	else if (state == 1)
//		return ret = (solution(cur + 1, 0, cnt) + solution(cur + 1, 2, cnt)) % 1000000;
//	else if (state == 2)
//		return ret = (solution(cur + 1, 0, cnt) + solution(cur + 1, 1, cnt + 1) + solution(cur + 1, 3, cnt)) % 1000000;
//	else
//		return ret = (solution(cur + 1, 0, cnt) + solution(cur + 1, 1, cnt + 1)) % 1000000;
//}
//
//int main()
//{
//	inputData();
//	cout << (solution(0,0,0) + solution(0,1,1) + solution(0, 2, 0)) % 1000000 << endl;
//
//	return 0;
//}
//
//
