#include<cstdio>
#include<algorithm>
using namespace std;
int N, arr[9];
void func(int x, int a[9]) {
	if (x == N-1) {
		for (int i = 0; i < N; i++)
			printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (int i = x; i < N; i++) {
		sort(arr + x, arr + N);
		swap(a[x], a[i]);
		func(x+1, a);
		sort(arr + x, arr + N);
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) arr[i] = i+1;
	func(0, arr);
	return 0;
}