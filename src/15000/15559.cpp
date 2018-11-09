#include<cstdio>
char map[1001][1001];
int N, M, visit[1001][1001], cnt, ret;
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) scanf(" %c", &map[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++){
			if (visit[i][j]) continue;
			int x = j, y = i;
			cnt++;
			while (!visit[y][x]) {
				visit[y][x] = cnt;
				char c = map[y][x];
				if (c == 'N') y--;
				else if (c == 'W') x--;
				else if (c == 'E') x++;
				else y++;
			}
			if (visit[y][x] == cnt) ret++;
		}
	printf("%d\n", ret);
	return 0;
}