#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string a, b;
int mi=51, diff;
void solution() {
	for (int i = 0, t = 0; i <= diff; i++, t = 0) {
		for (int j = i, k=0; a[k]; j++, k++)
			if (a[k] != b[j]) t++;
		mi = min(mi, t);
	}
}
int main() {
	cin >> a >> b;
	diff = b.size() - a.size();
	solution();
	printf("%d\n", mi);
	return 0;
}