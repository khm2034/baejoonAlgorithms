#include<iostream>
using namespace std;
int N;
pair<int, int> arr[51];
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d%d", &arr[i].first, &arr[i].second);

	for (int i = 0, cnt = 1; i < N; i++, cnt= 1) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (arr[i].first < arr[j].first && arr[i].second < arr[j].second) cnt++;
		}
		printf("%d ", cnt);
	}
	return 0;
}