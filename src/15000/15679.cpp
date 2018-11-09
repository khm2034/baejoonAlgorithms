#include<cstdio>
int N, M, visit[9], arr[9], idx;
void func(int c) {
	if (c == M) {
		for (int i = 0; i < idx; i++) printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visit[i]) continue;
		if (!visit[i]) {
			arr[idx] = i; 
			idx++; visit[i] = 1;
			func(c + 1);
			idx--; visit[i] = 0;
		}
	}
}
int main() {
	scanf("%d%d", &N, &M);
	func(0);
	return 0;
}