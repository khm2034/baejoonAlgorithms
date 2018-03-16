#include<iostream>
#define SIZE 100001
using namespace std;

char a_s[SIZE];
char b_s[SIZE];
int result_s[5][SIZE];
int main()
{
	for (int i = SIZE -2; i >= 0; --i)
		cin >> a_s[i];
	for (int i = SIZE -2; i >= 0; --i)
		cin >> b_s[i];
	a_s[SIZE-1] = b_s[SIZE-1] = '\0';
	for (int i = 0; i < SIZE-1; ++i)
	{
		result_s[0][i] = (a_s[i] - '0') & (b_s[i] - '0');
		result_s[1][i] = (a_s[i] - '0') | (b_s[i] - '0');
		result_s[2][i] = (a_s[i] - '0') ^ (b_s[i] - '0');
		result_s[3][i] = ((a_s[i] - '0' )== 0) ? 1 : 0;
		result_s[4][i] = ((b_s[i] - '0') == 0) ? 1 : 0;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = SIZE - 2; j >=0 ; j--)
			cout << result_s[i][j];
		cout << "\n";
	}
	return 0;
}