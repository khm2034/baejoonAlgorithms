#include<iostream>
#include<vector>

using namespace std;

int fibo(int n);

class PrintVal
{
public:
	int zero;
	int one;

	PrintVal(int zero, int one)
	{
		this->zero = zero;
		this->one = one;
	}
};

int zeroNum = 0;
int oneNum = 0;

int inputVal;
vector<PrintVal*> printArr;

int main()
{
	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++)
	{
		int tmpVal;
		cin >> tmpVal;
		fibo(tmpVal);
		printArr.push_back(new PrintVal(zeroNum, oneNum));
		zeroNum = 0;
		oneNum = 0;
	}

	for (int i = 0; i < printArr.size(); i++)
	{
		cout << printArr[i]->zero << " " << printArr[i]->one << endl;
	}

	return 0;
}

int fibo(int n)
{
	if (n == 0)
	{
		zeroNum++;
		return 0;
	}
	else if (n == 1)
	{
		oneNum++;
		return 1;
	}
	else
	{
		return fibo(n - 1) + fibo(n - 2);
	}
}