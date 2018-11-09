#include<iostream>
#include<cstdio>
using namespace std;

int W[3];
bool visit[201][201][201];
int pick[6][2] = { {0,1}, {1,0}, {0,2}, {2, 0}, {1, 2}, {2,1} };
void func2(int&a, int &b, int w)
{
	if (a + b > w) { a += b; b =a - w; a = w; }
	else { a += b; b = 0; }
}

void func(int a, int b, int c)
{
	if (visit[a][b][c]) return;
	visit[a][b][c] = true;
	int tw[3];
	for(int i=0; i<6; i++)
	{
		tw[0] = a, tw[1] = b, tw[2] = c;
		func2(tw[pick[i][0]], tw[pick[i][1]], W[pick[i][0]]);
		func(tw[0], tw[1], tw[2]);
	}
}
int main()
{
	scanf("%d%d%d", &W[0], &W[1], &W[2]);
	func(0, 0, W[2]);
	for (int i = W[1]; i >= 0; i--)
		for (int j = 0; j <= W[2]; j++)
			if (visit[0][i][j])
				printf("%d ",j);
	return 0;
}