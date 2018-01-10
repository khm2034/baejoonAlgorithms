//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void input();
//void solution(string s1, string s2);
//
//string inputData[2];
//string dp[1002][1002];
//
//int main()
//{
//	input();
//	solution(inputData[0], inputData[1]);
//
//	cout << dp[inputData[0].length()][inputData[1].length()] << endl;
//	return 0;
//}
//
//void input()
//{
//	cin >> inputData[0] >> inputData[1];
//}
//
//void solution(string s1, string s2)
//{
//	for(int i = 1; i <= (int)s2.length(); i++)
//		for (int j = 1; j <= (int)s1.length(); j++)
//		{
//			if (s2[i - 1] == s1[j - 1])
//			{
//				dp[i][j].append(dp[i - 1][j - 1]);
//				dp[i][j].push_back(s1[j-1]);
//			}
//			else
//			{
//				if (dp[i - 1][j].length() >= dp[i][j - 1].length())
//					dp[i][j] = dp[i - 1][j];
//				else
//					dp[i][j] = dp[i][j-1];
//			}
//		}
//}