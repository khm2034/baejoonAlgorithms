#include<iostream>

using namespace std;

void input();
void solution();
int min(int a, int b);

int houseNum;
int house[1001][3] = { 0, };
int houseColor[1000][3] = { 0, };
int result;
int main() 
{
	input();
	solution();
	
	cout << result << endl;
	return 0;
}

void input()
{
	cin >> houseNum;

	for (int i = 0; i < houseNum; i++)
		for (int j = 0; j < 3; j++)
			cin >> houseColor[i][j];
}

void solution()
{
	for (int i = houseNum-1 ; i >= 0; i--)
	{
		house[i][0] = min(house[i + 1][1], house[i + 1][2]) + houseColor[i][0];
		house[i][1] = min(house[i + 1][0], house[i + 1][2]) + houseColor[i][1];
		house[i][2] = min(house[i + 1][0], house[i + 1][1]) + houseColor[i][2];
	}

	result = min(min(house[0][0], house[0][1]), house[0][2]);
}


int min(int a, int b)
{
	return a > b ? b : a;
}