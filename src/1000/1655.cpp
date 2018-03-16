#include <cstdio>
#include <memory.h>
#define INF 1e9
using namespace std;

struct HEAP {
	int heap[100001];
	int sz = 0;
	bool(*cmp)(int a, int b);

	HEAP(bool(*_cmp)(int a, int b))
	{
		cmp = _cmp;
		memset(heap, 0, sizeof(heap));
		sz = 0;
	}
	void swap(int& a, int& b)
	{
		int tmp(a);
		a = b;
		b = tmp;
	}

	void upheap()
	{
		int cur = sz;

		while (cur / 2 > 0 && cmp(heap[cur], heap[cur / 2]))
		{
			swap(heap[cur], heap[cur / 2]);
			cur = cur / 2;
		}
	}

	void downheap()
	{
		int cur = 1;
		while (cur * 2 <= sz)
		{
			int target = cur*2;
			if (target + 1 <= sz && cmp(heap[target + 1], heap[target]))
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

	void push(int i)
	{
		heap[++sz] = i;
		upheap();
	}

	int pop()
	{
		int ret = heap[1];
		heap[1] = heap[sz--];
		downheap();
		return ret;
	}

	int top()
	{
		return heap[1];
	}

	bool empty()
	{
		return sz == 0;
	}
};


bool compMin(int a, int b)
{
	return a < b;
}

bool compMax(int a, int b)
{
	return a > b;
}

HEAP min_heap(compMin);
HEAP max_heap(compMax);
int main()
{
	freopen("input.txt", "r", stdin);
	int N, tmp;
	scanf("%d", &N);
	min_heap.push(INF);
	max_heap.push(-INF);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &tmp);
		if (tmp < min_heap.top())// 왼쪽에 넣어야 함
		{
			// 오른쪽이 왼쪽보다 사이즈가 1이 크거나 같아야함
			max_heap.push(tmp);
			if (max_heap.sz > min_heap.sz+1)
				min_heap.push(max_heap.pop());
		}
		else
		{
			min_heap.push(tmp);
			if (min_heap.sz == max_heap.sz + 1)
				max_heap.push(min_heap.pop());
		}
		printf("%d\n", max_heap.top());
	}
	return 0;
}