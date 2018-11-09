#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1001], s = 1;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	sort(arr, arr + N);
	if (arr[0] != 1) cout << "1\n";
	else {
		for (int i = 1; i < N; i++) 
			if (s +1>= arr[i]) 
				s += arr[i];
		cout << s +1<< "\n";
	}
	return 0;
}