#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int T, N;
pair<ll, string> arr[1001];
int main() {
	ios_base::sync_with_stdio();
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i].first >> arr[i].second;
		sort(arr, arr + N);
		cout << arr[N-1].second << "\n";
	}
	return 0;
}