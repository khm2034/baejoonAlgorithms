#include<cstdio>
#include<vector>
std::vector<int> v;
int n, t;
long long s;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &t);
		if (!t) v.pop_back();
		else v.push_back(t);
	}
	for (int t : v) s += t;
	printf("%lld", s);
	return 0;
}