//#include<cstdio>
//#include<algorithm>
//#define fi first
//#define se second
//using namespace std;
//typedef pair<int, int> pii;
//pair<pii,pii> s[100];
//int K, N,a, b, c;
//int main() {
//	scanf("%d%d", &N, &K);
//	for (int i = 0; i < N; i++) {
//		scanf("%d%d%d", &a, &b, &c);
//		s[i] = { {a+b+c, a},{b,c} };
//	}
//	sort(s, s + N);
//	a = b = c = 0;
//	for (int i = 0; i < K; i++) {
//		a = max(a, s[i].fi.se);
//		b = max(b, s[i].se.fi);
//		c = max(c, s[i].se.se);
//	}
//	printf("%lld", a+b+c);
//	return 0;
//}