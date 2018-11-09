#include<cstdio>
#include<vector>
using namespace std;
int N, sum[11][11];
char map[11][11];
vector<int> v;
bool chk(int j, int cnt) {
	return sum[j][cnt] > 0 && map[j][cnt] == '+'
		|| sum[j][cnt] == 0 && map[j][cnt] == '0'
		|| sum[j][cnt] < 0 && map[j][cnt] == '-';
}
bool func(int cnt) {
	if (cnt == N) {
		for (int i : v) printf("%d ", i);
		return true;
	}
	if (map[cnt][cnt] != '0') {
		for (int i = 1; i <= 10; i++) {
			int ty = 1;
			if (map[cnt][cnt] == '-') ty = -1;
			bool flag = false;
			sum[cnt][cnt] = i * ty; 
			int j;
			for (j = cnt - 1; j >= 0; j--) {
				sum[j][cnt] = sum[j][cnt - 1] + sum[cnt][cnt];
				if (flag = !chk(j, cnt)){
					j--;
					break;
				}
			}
			if (!flag) {
				v.push_back(i*ty);
				if (func(cnt + 1)) return true;
				v.pop_back();
			}
			for (j = j + 1; j <= cnt; j++) sum[j][cnt] = 0;
		}
	}
	else {
		bool flag = false;
		sum[cnt][cnt] = 0;
		int j;
		for (j = cnt - 1; j >= 0; j--) {
			sum[j][cnt] = sum[j][cnt - 1];
			if (flag = !chk(j, cnt)) {
				j--;
				break;
			}
		}
		if (!flag) {
			v.push_back(0);
			if (func(cnt+1)) return true;
			v.pop_back();
		}
		for (j = j + 1; j <= cnt; j++) sum[j][cnt] = 0;
	}
	return false;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++)
			scanf(" %1c", &map[i][j]);
	}
	func(0);
	return 0;
}