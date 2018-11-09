#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[10001];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	if(next_permutation(arr, arr + N))
		for (int i = 0; i < N; i++) printf("%d ", arr[i]);
	else printf("-1");
	return 0;
}