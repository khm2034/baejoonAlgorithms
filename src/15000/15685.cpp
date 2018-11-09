#include<cstdio>
int n, x, y, d, g, arr[(1 << 10) + 1], ret;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,-1,0,1 };
bool map[101][101];
int main(){
	for (int i = 1, k = 1; i < 1<<10; i <<= 1)
		for (int j = i - 1; j >= 0; j--)
			arr[k++] = (arr[j] + 1) % 4;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d", &x, &y, &d, &g);
		map[y][x] = 1;
		for (int j = 0, td; j < 1<<g; j++){
			td = (d + arr[j]) % 4;
			x += dx[td]; y += dy[td];
			map[y][x] = 1;
		}
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (map[i][j] & map[i][j + 1] & map[i + 1][j] & map[i + 1][j + 1]) ret++;
	printf("%d\n", ret);
	return 0;
}