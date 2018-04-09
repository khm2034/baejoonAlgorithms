#include<iostream>
#include<string>
using namespace std;

string arr[2][8] = {
	{"0", "1", "10", "11", "100", "101", "110", "111"},
	{ "000", "001", "010", "011", "100", "101", "110", "111" }
};
string N;
int main()
{
	cin >> N;
	cout << arr[0][N[0] - '0'];
	for (int i = 1; N[i]; i++)
		cout << arr[1][N[i] - '0'];
	cout << "\n";
	return 0;
}