#include<cstdio>
#include<queue>
using namespace std;
int N, t;
queue<int> q;
int main() {
	scanf("%d", &N);
	if (N == 1) printf("1");
	else {
		for (int i = 1; i <= N; i++) q.push(i);
		do{
			t++;
			int r = 1;
			for (int i = 0; i < 3; i++) r = (r*t) % N;
			if (!r) r = N;
			for (int i = 0; i < r - 1; i++) {
				q.push(q.front());
				q.pop();
			}
			q.pop();
		}while (--N != 1);
		printf("%d", q.front());
	}
	return 0;
}