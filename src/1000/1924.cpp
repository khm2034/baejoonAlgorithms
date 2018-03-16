#include <iostream>
#include <string>
using namespace std;
int month[12] = { 0, 31,28,31,30,31,30,31,31,30,31,30};
string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int main()
{
	int m, d;
	cin >> m >> d;
	int tmp = 0;
	for (int i = 0; i < m; i++)
		tmp += month[i];
	tmp += d;
	cout << day[tmp % 7] << "\n";
	return 0;
}