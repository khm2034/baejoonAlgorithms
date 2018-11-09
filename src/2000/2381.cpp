#include<cstdio>
#include<algorithm>
using namespace std;
int N, sma=-1e9, smi=1e9, mma=-1e9, mmi = 1e9;
int main() {
	scanf("%d", &N);
	for (int i = 0, x, y; i < N; i++) {
		scanf("%d%d", &x, &y);
		sma = max(sma, x + y);
		smi = min(smi, x + y);
		mma = max(mma, x - y);
		mmi = min(mmi, x - y);
	}
	printf("%d", max(sma - smi, mma - mmi));
	return 0;
}