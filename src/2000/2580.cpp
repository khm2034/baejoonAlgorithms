#include<iostream>
#include<vector>
using namespace std;
int map[10][10], cnt;
bool ve[10][10], ho[10][10], sq[10][10];
vector<pair<int, int>> v;
int trans(int x, int y) {
	if (y >= 0 && y <= 2) {
		if (x >= 0 && x <= 2) return 1;
		else if (x >= 3 && x <= 5) return 2;
		else return 3;
	}
	else if (y >= 3 && y <= 5) {
		if (x >= 0 && x <= 2) return 4;
		else if (x >= 3 && x <= 5) return 5;
		else return 6;
	}
	else {
		if (x >= 0 && x <= 2) return 7;
		else if (x >= 3 && x <= 5) return 8;
		else return 9;
	}
}
bool func(int c, int idx) {
	if (!c) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) 
				printf("%d ", map[i][j]);
			printf("\n");
		}
		return true;
	}
	pair<int, int> t = v[idx];
	int te = trans(t.first, t.second);
	for (int k = 1; k <= 9; k++) {
		if (!ho[t.second][k] && !ve[t.first][k] && !sq[te][k]) {
			map[t.second][t.first] = k;
			ho[t.second][k] = ve[t.first][k] = sq[te][k] = true;
			if (func(c - 1, idx+1)) return true;
			map[t.second][t.first] = 0;
			ho[t.second][k] = ve[t.first][k] = sq[te][k] = false;
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &map[i][j]);
			if (!map[i][j]) {
				v.push_back({ j, i });
				cnt++;
			}
			else {
				ho[i][map[i][j]] = true;
				ve[j][map[i][j]] = true;
				sq[trans(j, i)][map[i][j]] = true;
			}
		}
	}
	func(cnt, 0);
	return 0;
}