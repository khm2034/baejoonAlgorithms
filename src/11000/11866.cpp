#include<cstdio>
using namespace std;

struct Node
{
	int n;
	Node* next;
	Node* pre;
	Node(){}
	Node(int _n, Node* _next, Node* _pre)
	{
		n = _n; next = _next; pre = _pre;
	}
};

Node* head;
Node* cur;
int N, M;
void insert(int i)
{
	Node* tmp = new Node(i, nullptr, nullptr);
	Node* tail = head->next->pre;

	tmp->next = tail->next;
	tmp->pre = tail;
	tail->next->pre = tmp;
	tail->next = tmp;
}

void pop()
{
	Node* tmp = cur;
	cur->next->pre = tmp->pre;
	cur->pre->next = tmp->next;
	cur = cur->pre;
	delete tmp;
}
int main()
{
	head = new Node();
	cur = new Node(-1, nullptr, nullptr);
	cur->next = cur;
	cur->pre = cur;
	head->next = cur;

	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		insert(i + 1);
	int cnt = 0;
	cur = head->next;
	printf("<");
	while (cnt != N)
	{
		cnt++;
		for (int i = 0; i < M; i++)
		{
			cur = cur->next;
			if(cur->n < 0)
				cur = cur->next;
		}
		if(cnt == N)
			printf("%d", cur->n);
		else
			printf("%d, ", cur->n);
		pop();
	}
	printf(">");
	return 0;
}