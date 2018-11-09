#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[9];
vector<int> cm;
bool func(int idx, int cnt, int sum) {
	if (cnt == 7) {
		if (sum == 100) return true;
		return false;
	}
	for (int i = idx; i < 9; i++) {
		cm.push_back(arr[i]);
		if (func(i + 1, cnt+1, sum + arr[i])) return true;
		cm.pop_back();
	}
	return false;
}
int main() {
	for (int i = 0; i < 9; i++) scanf("%d", &arr[i]);
	func(0, 0,0);
	sort(cm.begin(), cm.end());
	for (auto v : cm) printf("%d\n", v);
	return 0;
}