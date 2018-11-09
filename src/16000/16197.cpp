#include<cstdio>
struct p { int x, y; };
int N, M, f, mi = 20, dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
char m[22][22];
p co[2];
bool safe(p a) {
	return a.x >= 0 && a.x < M && a.y >= 0 && a.y < N;
}
void func(int c) {
	if (c > 10 || c >= mi || !(safe(co[0]) || safe(co[1]))) return;
	if (safe(co[0]) ^ safe(co[1])) {
		mi = c;
		return;
	}
	p t[2]; t[0] = co[0], t[1] = co[1];
	for (int i = 0,tx,ty; i < 4; i++) {
		int w = 2;
		for (int j = 0; j < 2; j++) {
			tx = co[j].x + dx[i], ty = co[j].y + dy[i];
			if (!safe({ tx, ty }) || m[ty][tx] !='#') co[j] = { tx, ty }, w--;
		}
		if (w<2) func(c + 1);
		co[0] = t[0], co[1] = t[1];
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for(int j=0; j<M; j++){
		scanf(" %c", &m[i][j]);
		if (m[i][j] == 'o') {
			if (!f) co[0] = { j,i }, f = 1;
			else co[1] = { j,i };
		}
	}
	func(0);
	printf("%d", mi > 10 ? -1 : mi);
	return 0;
}