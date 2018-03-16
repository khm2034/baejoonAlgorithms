#include <iostream>
#include <memory.h>
using namespace std;

struct HEAP {
	int heap[100001];
	int size;
	bool(*cmp)(int x, int y);
	HEAP(bool(*_cmp)(int x, int y))
	{
		cmp = _cmp;
		memset(heap, 0, sizeof(heap));
		size = 0;
	}

	int top()
	{
		return heap[1];
	}
	bool empty()
	{
		return size == 0;
	}
	void swap(int& a, int& b)
	{
		int c(a); a = b; b = c;
	}
	void upheap()
	{
		int cur = size;
		while (cur / 2 > 0 && cmp(heap[cur], heap[cur / 2]))
		{
			swap(heap[cur], heap[cur / 2]);
			cur = cur / 2;
		}
	}

	void push(int i)
	{
		heap[++size] = i;
		upheap();
	}

	void downheap()
	{
		int cur = 1;
		while (cur * 2 <= size)
		{
			int target = cur * 2;
			if (target + 1 <= size && cmp(heap[target + 1], heap[target]))
				target = target + 1;

			if (cmp(heap[target], heap[cur]))
			{
				swap(heap[target], heap[cur]);
				cur = target;
			}
			else
				break;
		}
	}
	int pop()
	{
		int ret = top();
		heap[1] = heap[size--];
		downheap();
		return ret;
	}
};

bool max_cmp(int x, int y)
{
	return x > y;
}

HEAP max_heap(max_cmp);
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
			if (max_heap.empty())
				cout << "0\n";
			else
				cout << max_heap.pop() << "\n";
		else if (x > 0)
			max_heap.push(x);
	}
	return 0;
}