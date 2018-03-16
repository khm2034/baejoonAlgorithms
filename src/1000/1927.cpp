#include<iostream>
#include<memory.h>
using namespace std;

struct HEAP {
	int arr[100001];
	int size;
	bool(*cmp)(int x, int y);
	HEAP(bool(*_cmp)(int x, int y))
	{
		cmp = _cmp;
		size = 0;
		memset(arr, 0, sizeof(arr));
	}

	void swap(int& x, int& y)
	{
		int c(x); x = y; y = c;
	}
	int top()
	{
		return arr[1];
	}
	bool empty()
	{
		return size == 0;
	}

	void upheap()
	{
		int cur = size;
		while (cur / 2 > 0 && cmp(arr[cur], arr[cur / 2]))
		{
			swap(arr[cur], arr[cur / 2]);
			cur = cur / 2;
		}
	}

	void downheap()
	{
		int cur = 1;
		while (cur * 2 <= size)
		{
			int target = cur * 2;
			if (target + 1 <= size && cmp(arr[target + 1], arr[target]))
				target = target + 1;

			if (cmp(arr[target], arr[cur]))
			{
				swap(arr[target], arr[cur]);
				cur = target;
			}
			else
				break;
		}
	}

	void push(int x)
	{
		arr[++size] = x;
		upheap();
	}

	int pop()
	{
		int ret = arr[1];
		arr[1] = arr[size--];
		downheap();
		return ret;
	}
};

bool min_cmp(int x, int y)
{
	return x < y;
}

HEAP minheap(min_cmp);
int N;
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N;
	int x;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0)
			if (minheap.empty())
				cout << "0\n";
			else
				cout << minheap.pop() << "\n";
		else if (x > 0)
			minheap.push(x);
	}
	return 0;
}