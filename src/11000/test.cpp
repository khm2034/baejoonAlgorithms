//#include<iostream>
//#include<string>
//#include<memory.h>
//#define QUEUESIZE 2505
//using namespace std;
//
//int R, C;
//int map[51][51];
//int visit_w[51][51];
//int visit_s[51][51];
//struct qu {
//	pair<int, int> q[QUEUESIZE];
//	int rear, front;
//	qu() { rear = front = 0;  }
//	void push(int x, int y)
//	{
//		rear++;
//		rear = rear % QUEUESIZE;
//		q[rear].first = x;
//		q[rear].second = y;
//	}
//	pair<int, int> pop()
//	{
//		front++;
//		front = front % QUEUESIZE;
//		return q[front];
//	}
//};
//qu q_s, q_w;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//bool safe(int x, int y)
//{
//	return x >= 0 && x < C && y >= 0 && y < R;
//}
//void bfs_w()
//{
//	while (q_w.front != q_w.rear)
//	{
//		pair<int, int> t = q_w.pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !map[ty][tx] && !visit_w[ty][tx])
//			{
//				visit_w[ty][tx] = visit_w[t.second][t.first] + 1;
//				q_w.push(tx, ty);
//			}
//		}
//	}
//}
//int bfs_s()
//{
//	while (q_s.front != q_s.rear)
//	{
//		pair<int, int> t = q_s.pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//
//			if (safe(tx, ty))
//			{
//				if (map[ty][tx] == 1)
//					return visit_s[t.second][t.first];
//				else if (map[ty][tx] != -1 && !visit_s[ty][tx] && ((visit_w[ty][tx] > visit_s[t.second][t.first] + 1) || (visit_w[ty][tx] == 0)))
//				{
//					visit_s[ty][tx] = visit_s[t.second][t.first] + 1;
//					q_s.push(tx, ty);
//				}
//			}
//		}
//	}
//	return 0;
//}
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	cin >> R >> C;
//	string s;
//	for (int i = 0; i < R; i++)
//	{
//		cin >> s;
//		for (int j = 0; s[j]; j++)
//		{
//			if (s[j] == 'D') map[i][j] = 1;
//			else if(s[j] == '.') map[i][j] = 0;
//			else if (s[j] == 'X') map[i][j] = -1;
//			else if (s[j] == 'S')
//			{
//				q_s.push(j, i);
//				visit_s[i][j] = 1;
//			}
//			else if (s[j] == '*')
//			{
//				q_w.push(j, i);
//				visit_w[i][j] = 1;
//			}
//		}
//	}
//	bfs_w();
//	int ret =  bfs_s();
//	if (ret)
//		cout << ret << "\n";
//	else
//		cout << "KAKTUS\n";
//	return 0;
//}

//#include<iostream>
//#include<string>
//#include<memory.h>
//#define QUEUESIZE 100
//using namespace std;
//
//int map[13][7];
//bool visit[13][7];
//string s;
//pair<int, int> q[QUEUESIZE];
//int front, rear;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int> pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < 6 && y >= 0 && y < 12;
//}
//bool bfs(int x, int y, int color)
//{
//	pair<int, int> r_l[100];
//	int r_idx = 0;
//	push(x, y);
//	visit[y][x] = true;
//	r_l[r_idx].first = x;
//	r_l[r_idx++].second = y;
//	while (front != rear)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !visit[ty][tx] && map[ty][tx] == color)
//			{
//				push(tx, ty);
//				visit[ty][tx] = true;
//				r_l[r_idx].first = tx;
//				r_l[r_idx++].second = ty;
//			}
//		}
//	}
//	if (r_idx < 4)
//		return false;
//	for (int i = 0; i < r_idx; i++)
//		map[r_l[i].second][r_l[i].first] = 0;
//	return true;
//}
//void drop()
//{
//	for (int i = 0; i < 6; i++)
//	{
//		int lo, hi, diff;
//		bool flag = false;
//		for (int j = 11; j >= 0; j--)
//		{
//			if (!map[j][i])
//			{
//				lo = j;
//				j--;
//				while(1)
//				{ 
//					if (map[j][i] || j == 0)
//						break;
//					j--;
//				}
//				diff = lo - j;
//				while (1)
//				{
//					if (!map[j][i] || j==0)
//						break;
//					j--;
//				}
//				hi = j;
//				for (int k = lo; k >= hi + diff; k--)
//				{
//					map[k][i] = map[k - diff][i];
//					map[k - diff][i] = 0;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	for (int i = 0; i < 12; i++)
//	{
//		cin >> s;
//		for (int j = 0; s[j]; j++)
//		{
//			if (s[j] == '.')
//				map[i][j] = 0;
//			else if (s[j] == 'R')
//				map[i][j] = 1;
//			else if (s[j] == 'G')
//				map[i][j] = 2;
//			else if (s[j] == 'B')
//				map[i][j] = 3;
//			else if (s[j] == 'P')
//				map[i][j] = 4;
//			else if (s[j] == 'Y')
//				map[i][j] = 5;
//		}
//	}
//
//	int cnt = 0;
//	while (1)
//	{
//		memset(visit, false, sizeof(visit));
//		int flag = false;
//		for (int i = 0; i < 12; i++)
//			for (int j = 0; j < 6; j++)
//			{
//				if (map[i][j] && !visit[i][j])
//					flag = flag | bfs(j, i, map[i][j]);
//			}
//		if (!flag)
//			break;
//		cnt++;
//		drop();
//	}
//	cout << cnt << "\n";
//	return 0;
//}
//#include<iostream>
//#include<algorithm>
//#define QUEUESIZE 10005
//using namespace std;
//
//int N, M, K;
//int map[101][101];
//bool visit[101][101];
//int sx, sy, ex, ey;
//pair<int, int> q[QUEUESIZE];
//int front, rear;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int result[2501];
//int result_idx;
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int> pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < N && y >= 0 && y < M;
//}
//int bfs(int x, int y)
//{
//	int ret = 1;
//	push(x, y);
//	visit[y][x] = true;
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !visit[ty][tx] && !map[ty][tx])
//			{
//				ret++;
//				visit[ty][tx] = true;
//				push(tx, ty);
//			}
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	cin >> M >> N >> K;
//	for (int i = 0; i < K; i++)
//	{
//		cin >> sx >> sy >> ex >> ey;
//		for (int j = sy; j < ey; j++)
//			for (int k = sx; k < ex; k++)
//				map[j][k] = 1;
//	}
//
//	for (int i = 0; i < M; i++)
//		for (int j = 0; j < N; j++)
//			if (!map[i][j] && !visit[i][j])
//				result[result_idx++] = bfs(j, i);
//	sort(result, result + result_idx);
//	cout << result_idx << "\n";
//	for (int i = 0; i < result_idx; i++)
//		cout << result[i] << " ";
//	cout << "\n";
//	return 0;
//}
//#include<iostream>
//#include<memory.h>
//#define QUEUESIZE 2505
//using namespace std;
//
//int W, H;
//int map[51][51];
//bool visit[51][51];
//pair<int, int> q[2505];
//int front, rear;
//int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1};
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int> pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < W && y >= 0 && y < H;
//}
//
//void bfs(int x, int y)
//{
//	push(x, y);
//	visit[y][x] = true;
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 8; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx])
//			{
//				visit[ty][tx] = true;
//				push(tx, ty);
//			}
//		}
//	}
//}
//
//int main()
//{
//	while (1)
//	{
//		memset(map, 0, sizeof(map));
//		memset(visit, false, sizeof(visit));
//		cin >> W >> H;
//		if (!W && !H)
//			break;
//		for(int i=0; i<H; i++)
//			for (int j = 0; j < W; j++)
//				cin >> map[i][j];
//
//		int cnt = 0;
//		for (int i = 0; i < H; i++)
//			for (int j = 0; j < W; j++)
//				if (map[i][j] && !visit[i][j])
//				{
//					bfs(j, i);
//					cnt++;
//				}
//		cout << cnt << "\n";
//	}
//	return 0;
//}
//#include<iostream>
//#include<memory.h>
//#define QUEUESIZE 2505
//using namespace std;
//
//int N, M, K;
//int T;
//int map[51][51];
//bool visit[51][51];
//
//pair<int, int> q[QUEUESIZE];
//int rear, front;
//
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//
//pair<int, int> pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//
//bool safe(int x, int y)
//{
//	return x >= 0 && x < M && y >= 0 && y < N;
//}
//
//void bfs(int x, int y)
//{
//	push(x, y);
//	visit[y][x] = true;
//	while (front != rear)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx])
//			{
//				visit[ty][tx] = true;
//				push(tx, ty);
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> T;
//	for (int tc = 0; tc < T; tc++)
//	{
//		memset(map, 0, sizeof(map));
//		memset(visit, false, sizeof(visit));
//		cin >> M >> N >> K;
//		int x, y;
//		int cnt = 0;
//		for (int i = 0; i < K; i++)
//		{
//			cin >> x >> y;
//			map[y][x] = 1;
//		}
//		for(int i=0; i<N; i++)
//			for (int j = 0; j < M; j++)
//			{
//				if (map[i][j] && !visit[i][j])
//				{
//					bfs(j, i);
//					cnt++;
//				}
//			}
//
//		cout << cnt << "\n";
//	}
//	return 0;
//}

////#include<iostream>
////#include<cstdio>
////#include<memory.h>
////#define QUEUESIZE (1000*1000*5)
////using namespace std;
////
////int N, M;
////int map[1001][1001];
////int dx[4] = { 1, 0, -1, 0 };
////int dy[4] = { 0, -1, 0, 1 };
////pair<int, int> q[QUEUESIZE];
////
////int rear = 0;
////int front = 0;
////int ret = 0;
////void push(int x, int y)
////{
////	rear++;
////	rear = rear%QUEUESIZE;
////	q[rear].first = x;
////	q[rear].second = y;
////}
////pair<int, int> pop()
////{
////	front++;
////	front = front%QUEUESIZE;
////	return q[front];
////}
////
////bool safe(int x, int y)
////{
////	return x >= 0 && x < N && y >= 0 && y < M;
////}
////
////void bfs()
////{
////	while (rear != front)
////	{
////		pair<int, int> t = pop();
////		for (int i = 0; i < 4; i++)
////		{
////			int tmp_x = t.first + dx[i];
////			int tmp_y = t.second + dy[i];
////			if (safe(tmp_x, tmp_y) && map[tmp_y][tmp_x] == 0)
////			{
////				map[tmp_y][tmp_x] = map[t.second][t.first] + 1;
////				push(tmp_x, tmp_y);
////				if (ret < map[tmp_y][tmp_x]-1)
////					ret = map[tmp_y][tmp_x]-1;
////			}
////		}
////	}
////}
////int chk()
////{
////	for (int i = 0; i < M; i++)
////		for (int j = 0; j < N; j++)
////			if (!map[i][j])
////				return -1;
////	return ret;
////}
////int main()
////{
////	scanf("%d%d", &N, &M);
////	int tmp;
////	for (int i = 0; i < M; i++)
////		for (int j = 0; j < N; j++)
////		{
////			scanf("%d", &tmp);
////			if (tmp == 1)
////				push(j, i);
////			map[i][j] = tmp;
////		}
////
////	bfs();
////	printf("%d\n", chk());
////	return 0;
////}
////
////#include<iostream>
////#include<cstdio>
////#include<algorithm>
////using namespace std;
////
////int N;
////int map[26][26];
////bool visit[26][26];
////char s[26];
////int dx[4] = { 1, 0, -1, 0 };
////int dy[4] = { 0 ,1, 0, -1 };
////int ret[25 * 25];
////int ret_idx = 0;
////bool safe(int x, int y)
////{
////	return x >= 0 && x < N && y >= 0 && y < N;
////}
////
////void dfs(int x, int y)
////{
////	visit[y][x] = true;
////	ret[ret_idx]++;
////	for (int i = 0; i < 4; i++)
////	{
////		int tx = x + dx[i];
////		int ty = y + dy[i];
////		if (safe(tx, ty) && map[ty][tx] && !visit[ty][tx])
////		{
////			dfs(tx, ty);
////		}
////	}
////
////}
////int main()
////{
////	scanf("%d", &N);
////	for (int i = 0; i < N; i++)
////	{
////		scanf("%s", s);
////		for (int j = 0; s[j]; j++)
////			map[i][j] = s[j] - '0';
////	}
////	int total = 0;
////	for (int i = 0; i < N; i++)
////		for (int j = 0; j < N; j++)
////			if (map[i][j] && !visit[i][j])
////			{
////				total++;
////				dfs(j, i);
////				ret_idx++;
////			}
////	printf("%d\n", total);
////	sort(ret, ret + total, cmp);
////	for (int i = 0; i < ret_idx; i++)
////		printf("%d\n", ret[i]);
////	return 0;
////}
////
////#include<iostream>
////#include<cstdio>
////typedef long long ll;
////using namespace std;
////
////int N, M;
////ll arr[1000001];
////ll le, ri;
////int main()
////{
////	scanf("%d%d", &N, &M);
////	for (int i = 0; i < N; i++)
////	{
////		scanf("%lld", &arr[i]);
////		if (ri < arr[i])
////			ri = arr[i];
////	}
////	ll ret = -1;
////	ll mid;
////	while (le <= ri)
////	{
////		mid = (ri + le) / 2;
////		ll sum = 0;
////		for (int i = 0; i < N; i++)
////			if(arr[i] > mid)
////				sum += arr[i] - mid;
////		
////		if (sum >= M)
////		{
////			if (ret < mid)
////				ret = mid;
////			le = mid+1;
////		}
////		else if (sum < M)
////			ri = mid-1;
////	}
////	printf("%lld\n", ret);
////	return 0;
////}
////
////#include<iostream>
////#include<cstdio>
////#define QUEUESIZE (1000*1000*5)
////using namespace std;
////
////int N, M;
////int map[1001][1001];
////int visit[1001][1001][2];
////char s[1001];
////int dx[4] = { 1, 0, -1, 0 };
////int dy[4] = { 0 ,1, 0, -1 };
////pair<int, int> q[QUEUESIZE];
////int front, rear;
////void push(int x, int y)
////{
////	rear++;
////	rear = rear%QUEUESIZE;
////	q[rear].first = x;
////	q[rear].second = y;
////}
////pair<int, int> pop()
////{
////	front++;
////	front = front%QUEUESIZE;
////	return q[front];
////}
////bool safe(int x, int y)
////{
////	return x >= 0 && x < M && y >= 0 && y < N;
////}
////void bfs()
////{
////	visit[0][0][0] = 1;
////	push(0, 0);
////	while (rear != front)
////	{
////		pair<int, int> t = pop();
////		int tx, ty;
////		for (int i = 0; i < 4; i++)
////		{
////			tx = t.first + dx[i];
////			ty = t.second + dy[i];
////			if (safe(tx, ty))
////			{
////				if (map[ty][tx] == 1 && !visit[ty][tx][1] && visit[t.second][t.first][0])
////				{
////					visit[ty][tx][1] = visit[t.second][t.first][0] + 1;
////					push(tx, ty);
////				}
////				else if (!map[ty][tx])
////				{
////					bool flag = false;
////					if(!visit[ty][tx][0] && visit[t.second][t.first][0])
////						flag = visit[ty][tx][0] = visit[t.second][t.first][0] + 1;
////					if(!visit[ty][tx][1] && visit[t.second][t.first][1])
////						flag = visit[ty][tx][1] = visit[t.second][t.first][1] + 1;
////
////					if (flag)
////						push(tx, ty);
////				}
////			}
////		}
////	}
////}
////int main()
////{
////	scanf("%d%d", &N, &M);
////	for (int i = 0; i < N; i++)
////	{
////		scanf("%s", s);
////		for (int j = 0; j < M; j++)
////			map[i][j] = s[j] - '0';
////	}
////	bfs();
////	int& ret0 = visit[N - 1][M - 1][0];
////	int& ret1 = visit[N - 1][M - 1][1];
////	int ret = (ret0 < ret1) ? (ret0 > 0 ? ret0 : ret1) : (ret1 > 0 ? ret1 : ret0);
////	printf("%d\n", ret > 0 ? ret : -1);
////
////	return 0;
////}
////#include <iostream>
////#include <cstdio>
////#include <cstring>
////using namespace std;
////
////struct student
////{
////	char hak[30];
////	char name[10];
////};
////
////student stack[10];
////int top = 0;
////
////bool empty()
////{
////	return top == 0;
////}
////
////void push(char* hak, char* name)
////{
////	strcpy(stack[top].hak, hak);
////	strcpy(stack[top++].name, name);
////}
////
////student pop()
////{
////	return stack[--top];
////}
////
////int main()
////{
////	char tmp_hak[30];
////	char tmp_name[10];
////	for (int i = 0; i < 3; i++)
////	{
////		scanf("%s%s", tmp_hak, tmp_name);
////		push(tmp_hak, tmp_name);
////	}
////	student tmp;
////	for (int i = 0; i < 3; i++)
////	{
////		tmp = pop();
////		printf("hak : %s\n name : %s\n", tmp.hak, tmp.name);
////	}
////}
//
//
//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//
//int map[1001][1001];
//
//int main()
//{
//	int row, col;
//	int ci = 0;
//	int count = 0;
//	int counti = 0, countj = 0;
//	int store_i[100] = { 0, };
//	int store_j[100] = { 0, };
//	int stack = 0;
//
//	scanf("%d %d", &col, &row);
//
//	if (2 <= col && col <= 1000)
//	{
//		if (2 <= row && row <= 1000)
//		{
//			int **m = malloc(sizeof(int *)*row); //2차원배열 동적할당
//
//			for (int i = 0; i < row; i++)
//			{
//				m[i] = malloc(sizeof(int) * col);
//			}
//
//			for (int i = 0; i < row; i++) //2차원배열 삽입
//			{
//				for (int j = 0; j < col; j++)
//				{
//					scanf("%d", &m[i][j]);
//				}
//			}
//
//			while (1)
//			{
//				for (int i = 0; i < row; i++) //1위치탐색
//				{
//					for (int j = 0; j < col; j++)
//					{
//						if (m[i][j] == 1)
//						{
//							store_i[counti] = i; // 1이 있는 위치 저장
//							store_j[countj] = j;
//							++counti;
//							++countj;
//						}
//					}
//				}
//
//				for (ci = 0; ci < counti; ci++) //끝내기
//				{
//					if (m[store_i[ci] - 1][store_j[ci]] != 0 && m[store_i[ci] + 1][store_j[ci]] != 0 && m[store_i[ci]][store_j[ci] - 1] != 0 && m[store_i[ci]][store_j[ci] + 1] != 0)
//					{
//						stack++;
//						printf("%d", count);
//						break;
//					}
//				}
//
//
//				for (ci = 0; ci < counti; ci++)
//				{
//					if (store_i[ci] - 1 <= 0)
//					{
//						m[store_i[ci] - 1][store_j[ci]] = m[0][store_j[ci]];
//						if (m[store_i[ci] - 1][store_j[ci]] == 0)
//						{
//							m[store_i[ci] - 1][store_j[ci]] = 1;
//						}
//					}
//
//					if (store_i[ci] + 1 >= row)
//					{
//						m[store_i[ci] + 1][store_j[ci]] = m[row][store_j[ci]];
//						if (m[store_i[ci] + 1][store_j[ci]] == 0)
//						{
//							m[store_i[ci] + 1][store_j[ci]] = 1;
//						}
//					}
//
//					if (store_j[ci] - 1 <= 0)
//					{
//						m[store_i[ci]][store_j[ci] - 1] = m[store_i[ci]][0];
//						if (m[store_i[ci]][store_j[ci] - 1] == 0)
//						{
//							m[store_i[ci]][store_j[ci] - 1] = 1;
//						}
//					}
//
//					if (store_j[ci] + 1 >= col)
//					{
//						m[store_i[ci]][store_j[ci] + 1] = m[store_i[ci]][col];
//						if (m[store_i[ci]][store_j[ci] + 1] == 0)
//						{
//							m[store_i[ci]][store_j[ci] + 1] = 1;
//						}
//					}
//				}
//				count++;
//			}
//		}
//	}
//}

// dfs bfs

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <memory.h>
//#define QUEUESIZE 1000005
//using namespace std;
//
//vector<int> graph[1001];
//bool visit[1001];
//int N, M, V;
//int q[QUEUESIZE];
//int front, rear;
//void push(int x)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear] = x;
//}
//int pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//void bfs(int n)
//{
//	cout << n << " ";
//	push(n);
//	visit[n] = true;
//	while (rear != front)
//	{
//		int t = pop();
//		int ts = graph[t].size();
//		for (int i = 0; i < ts; i++)
//		{
//			if (!visit[graph[t][i]])
//			{
//				cout << graph[t][i] << " ";
//				visit[graph[t][i]] = true;
//				push(graph[t][i]);
//			}
//		}
//	}
//}
//void dfs(int n)
//{
//	int size = graph[n].size();
//	if (!size)
//		return;
//	visit[n] = true;
//	cout << n << " ";
//	for (int i = 0; i < size; i++)
//		if (!visit[graph[n][i]])
//			dfs(graph[n][i]);
//}
//int main()
//{
//	cin >> N >> M >> V;
//	int to, from;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> from >> to;
//		graph[from].push_back(to);
//		graph[to].push_back(from);
//	}
//	for (int i = 0; i < N; i++)
//		sort(graph[i].begin(), graph[i].end());
//	dfs(V);
//	memset(visit, false, sizeof(visit));
//	cout << "\n";
//	bfs(V);
//	cout << "\n";
//	return 0;
//}

// 치즈

//#include <iostream>
//#include <string>
//#include <memory.h>
//#define QUEUESIZE 100005
//using namespace std;
//
//int map[1001][1001];
//int visit[1001][1001];
//int H, W, N;
//pair<int, int> q[QUEUESIZE];
//int front, rear;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int st = 1;
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int> pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < W && y >= 0 && y < H;
//}
//
//int bfs()
//{
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !visit[ty][tx] && map[ty][tx] != -1)
//			{
//				visit[ty][tx] = visit[t.second][t.first]+1;
//				if (map[ty][tx] == st)
//				{
//					if (st == N)
//						return visit[ty][tx];
//					st++;
//					int tmp = visit[ty][tx];
//					memset(visit, false, sizeof(visit));
//					front = rear = 0;
//					push(tx, ty);
//					visit[ty][tx] = tmp;
//					break;
//				}
//
//				push(tx, ty);
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> H >> W >> N;
//	string s;
//	for (int i = 0; i < H; i++)
//	{
//		cin >> s;
//		for (int j = 0; s[j]; j++)
//		{
//			if (s[j] == 'S')
//			{
//				push(j, i);
//				visit[i][j] = 1;
//			}
//			else if (s[j] == 'X')
//				map[i][j] = -1;
//			else if (s[j] >= '1' && s[j] <= '9')
//				map[i][j] = s[j] - '0';
//		}
//	}
//	cout << bfs()-1 << "\n";
//	return 0;
//}

// 연산자 끼워넣기

//#include<iostream>
//#define INF 2e10
//using namespace std;
//typedef long long ll;
//int N;
//int arr[101];
//int oper[4];
//ll max_v = -INF;
//ll min_v = INF;
//void func(int n, ll val)
//{
//	if (n == N-1)
//	{
//		if (val > max_v)
//			max_v = val;
//		if (val < min_v)
//			min_v = val;
//		return;
//	}
//
//	for (int i = 0; i < 4; i++)
//		if (oper[i])
//		{
//			oper[i]--;
//			switch (i)
//			{
//			case 0:
//				func(n + 1, val + arr[n + 1]);
//				break;
//			case 1:
//				func(n + 1, val - arr[n + 1]);
//				break;
//			case 2:
//				func(n + 1, val * arr[n + 1]);
//				break;
//			case 3:
//				func(n + 1, val / arr[n + 1]);
//				break;
//			}
//			oper[i]++;
//		}
//}
//int main()
//{
//	cin >> N;
//	for (int i = 0; i < N; i++)
//		cin >> arr[i];
//	for (int i = 0; i < 4; i++)
//		cin >> oper[i];
//	func(0, arr[0]);
//	cout << max_v << "\n";
//	cout << min_v << "\n";
//	return 0;
//}

// 나이트의 이동

//#include<iostream>
//#include<memory.h>
//#define QUEUESIZE 90005
//using namespace std;
//
//int visit[301][301];
//int T, l;
//int sx, sy, ex, ey;
//int dx[8] = { 1, 2, 2, 1, -1, -2 ,-2 ,-1 };
//int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
//pair<int, int> q[QUEUESIZE];
//int front, rear;
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int>pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < l && y >= 0 && y < l;
//}
//int bfs()
//{
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 8; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !visit[ty][tx])
//			{
//				visit[ty][tx] = visit[t.second][t.first] + 1;
//				if (tx == ex && ty == ey)
//					return visit[ty][tx];
//				push(tx, ty);
//			}
//		}
//	}
//	return 1;
//}
//int main()
//{
//	cin >> T;
//	for (int tc = 0; tc < T; tc++)
//	{
//		cin >> l;
//		memset(visit, false, sizeof(visit));
//		front = rear = 0;
//		cin >> sx >> sy >> ex >> ey;
//		push(sx, sy);
//		visit[sy][sx] = 1;
//		cout << bfs() - 1 << "\n";
//	}
//	return 0;
//}

//보물섬

//#include <iostream>
//#include <string>
//#include <memory.h>
//#define QUEUESIZE 2505
//using namespace std;
//
//int map[51][51];
//int visit[51][51];
//int W, H;
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//pair<int, int> q[QUEUESIZE];
//int front, rear;
//int ret = -1e9;
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int>pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < W && y >= 0 && y < H;
//}
//void bfs(int x, int y)
//{
//	int cur_max = -1e9;
//	memset(visit, 0, sizeof(visit));
//	push(x, y);
//	visit[y][x] = 1;
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !visit[ty][tx] && !map[ty][tx])
//			{
//				visit[ty][tx] = visit[t.second][t.first] + 1;
//				push(tx, ty);
//				if (cur_max < visit[ty][tx])
//					cur_max = visit[ty][tx];
//			}
//		}
//	}
//	if (ret < cur_max)
//		ret = cur_max;
//}
//int main()
//{
//	cin >> H >> W;
//	string s;
//	for (int i = 0; i < H; i++)
//	{
//		cin >> s;
//		for (int j = 0; s[j]; j++)
//			if (s[j] == 'W')
//				map[i][j] = 1;
//			else
//				map[i][j] = 0;
//	}
//	
//	for (int i = 0; i < H; i++)
//		for (int j = 0; j < W; j++)
//			if(!map[i][j])
//				bfs(j, i);
//	cout << ret - 1 << "\n";
//	return 0;
//}

//빙산

//#include<iostream>
//#include<memory.h>
//#define QUEUESZIE 90005
//using namespace std;
//
//int map[301][301];
//bool visit[301][301];
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int N, M;
//pair<int, int> q[QUEUESZIE];
//int front, rear, result;
//void push(int x, int y)
//{
//	rear++;
//	rear = rear % QUEUESZIE;
//	q[rear].first = x;
//	q[rear].second = y;
//}
//pair<int, int>pop()
//{
//	front++;
//	front = front % QUEUESZIE;
//	return q[front];
//}
//bool safe(int x, int y)
//{
//	return x >= 0 && x < M && y >= 0 && y < N;
//}
//void bfs(int x, int y)
//{
//	push(x, y);
//	visit[y][x] = true;
//	while (rear != front)
//	{
//		pair<int, int> t = pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty))
//			{
//				if (map[ty][tx] && !visit[ty][tx])
//				{
//					visit[ty][tx] = true;
//					push(tx, ty);
//				}
//				else if (!map[ty][tx] && !visit[ty][tx])
//				{
//					map[t.second][t.first]--;
//					if (map[t.second][t.first] < 0)
//						map[t.second][t.first] = 0;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> N >> M;
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < M; j++)
//			cin >> map[i][j];
//
//	while (1)
//	{
//		int cnt = 0;
//		memset(visit, false, sizeof(visit));
//		for(int i=0; i<N; i++)
//			for(int j=0; j<M; j++)
//				if (map[i][j] && !visit[i][j])
//				{
//					cnt++;
//					bfs(j, i);
//				}
//		if (!cnt)
//		{
//			cout << "0\n";
//			break;
//		}
//		else if (cnt >= 2)
//		{
//			cout << result << "\n";
//			break;
//		}
//		result++;
//	}
//	return 0;
//}

//불

//#include<iostream>
//#include<string>
//#include<memory.h>
//#define QUEUESIZE 1000005
//using namespace std;
//
//struct qu {
//	int front, rear;
//	pair<int, int> q[QUEUESIZE];
//	qu() { front = rear = 0;}
//	void push(int x, int y)
//	{
//		rear++;
//		rear = rear % QUEUESIZE;
//		q[rear].first = x;
//		q[rear].second = y;
//	}
//	pair<int, int> pop()
//	{
//		front++;
//		front = front % QUEUESIZE;
//		return q[front];
//	}
//};
//qu q_f, q_s;
//int map[1001][1001];
//int visit_s[1001][1001];
//int visit_f[1001][1001];
//int dx[4] = { 1, 0, -1, 0 };
//int dy[4] = { 0, 1, 0, -1 };
//int T, W, H;
//string s;
//bool safe(int x, int y)
//{
//	return x >= 0 && x < W && y >= 0 && y < H;
//}
//void bfs_f()
//{
//	while (q_f.front != q_f.rear)
//	{
//		pair<int, int> t = q_f.pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !map[ty][tx] && !visit_f[ty][tx])
//			{
//				visit_f[ty][tx] = visit_f[t.second][t.first] + 1;
//				q_f.push(tx, ty);
//			}
//		}
//	}
//}
//int bfs_s()
//{
//	while (q_s.front != q_s.rear)
//	{
//		pair<int, int> t = q_s.pop();
//		int tx, ty;
//		for (int i = 0; i < 4; i++)
//		{
//			tx = t.first + dx[i];
//			ty = t.second + dy[i];
//			if (safe(tx, ty) && !map[ty][tx] && !visit_s[ty][tx]
//				&& (visit_f[ty][tx] > visit_s[t.second][t.first] + 1 || !visit_f[ty][tx]))
//			{
//				visit_s[ty][tx] = visit_s[t.second][t.first] + 1;
//				q_s.push(tx, ty);
//			}
//			else if (!safe(tx, ty))
//			{
//				q_s.front = q_s.rear = 0;
//				return visit_s[t.second][t.first];
//			}
//		}
//	}
//	return -1;
//}
//int main()
//{
//	cin >> T;
//	for (int tc = 0; tc < T; tc++)
//	{
//		memset(visit_s, 0, sizeof(visit_s));
//		memset(visit_f, 0, sizeof(visit_f));
//
//		cin >> W >> H;
//		for (int i = 0; i < H; i++)
//		{
//			cin >> s;
//			for (int j = 0; s[j]; j++)
//			{
//				switch (s[j])
//				{
//				case '#':
//					map[i][j] = -1;
//					break;
//				case '.':
//					map[i][j] = 0;
//					break;
//				case '*':
//					q_f.push(j, i);
//					visit_f[i][j] = 1;
//					break;
//				case '@':
//					q_s.push(j, i);
//					visit_s[i][j] = 1;
//					break;
//				}
//			}
//		}
//		bfs_f();
//		int ret = bfs_s();
//		if (ret == -1)
//			cout << "IMPOSSIBLE\n";
//		else
//			cout << ret << "\n";
//	}
//	return 0;
//}

//토마토2

//#include <cstdio>
//#include <iostream>
//#define QUEUESIZE 1000005
//using namespace std;
//
//struct p {
//	int x, y, z;
//};
//int M, N, H;
//int map[101][101][101];
//int dx[6] = { 1, 0, -1, 0, 0, 0 };
//int dy[6] = { 0, 1, 0, -1, 0, 0 };
//int dz[6] = { 0, 0, 0, 0, 1, -1 };
//p q[QUEUESIZE];
//int front, rear;
//void push(int x, int y, int z)
//{
//	rear++;
//	rear = rear % QUEUESIZE;
//	q[rear].x = x;
//	q[rear].y = y;
//	q[rear].z = z;
//}
//p pop()
//{
//	front++;
//	front = front % QUEUESIZE;
//	return q[front];
//}
//
//bool safe(int x, int y, int z)
//{
//	return x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < H;
//}
//
//void bfs()
//{
//	while (front != rear)
//	{
//		p t = pop();
//		int tx, ty, tz;
//		for (int i = 0; i < 6; i++)
//		{
//			tx = t.x + dx[i]; ty = t.y + dy[i]; tz = t.z + dz[i];
//			if (safe(tx, ty, tz) && !map[tz][ty][tx])
//			{
//				map[tz][ty][tx] = map[t.z][t.y][t.x] + 1;
//				push(tx, ty, tz);
//			}
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d%d%d", &M, &N, &H);
//	for (int i = 0; i < H; i++)
//		for (int j = 0; j < N; j++)
//			for (int k = 0; k < M; k++)
//			{
//				scanf("%d", &map[i][j][k]);
//				if (map[i][j][k] == 1)
//					push(k, j, i);
//			}
//	bfs();
//	int ret = 0;
//	for (int i = 0; i < H; i++)
//		for (int j = 0; j < N; j++)
//			for (int k = 0; k < M; k++)
//			{
//				if (!map[i][j][k])
//				{
//					printf("-1\n");
//					return 0;
//				}
//				if (ret < map[i][j][k])
//					ret = map[i][j][k];
//			}
//	printf("%d\n", ret-1);
//	return 0;
//}

//N Queen

//#include<iostream>
//#include<cstdio>
//#include<memory.h>
//using namespace std;
//
//int N;
//int dx[3] = { 1, 0 ,-1 };
//int dy[3] = { 1, 1, 1 };
//int ret;
//void func(int n, int* left, int* mid, int* right)
//{
//	if (n == N)
//	{
//		ret++;
//		return;
//	}
//
//	int n_left[16] = { 0, };
//	int n_mid[16] = { 0, };
//	int n_right[16] = { 0, };
//	for (int i = 0; i < N; i++)
//	{
//		if (left[i])
//			if (i > 0)
//				n_left[i - 1] = 1;
//		if (mid[i])
//			n_mid[i] = 1;
//		if (right[i])
//			if (i < N - 1)
//				n_right[i + 1] = 1;
//			
//	}
//	for (int i = 0; i < N; i++)
//	{
//		if (!n_left[i] && !n_right[i] && !n_mid[i])
//		{
//			n_left[i] = n_right[i] = n_mid[i] = 1;
//			func(n + 1, n_left, n_mid, n_right);
//			n_left[i] = n_right[i] = n_mid[i] = 0;
//		}
//	}
//}
//int main()
//{
//	int left[16] = { 0, };
//	int mid[16] = { 0, };
//	int right[16] = { 0, };
//	scanf("%d", &N);
//	func(0, left, mid, right);
//	printf("%d\n", ret);
//	
//
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//int N;
//int ret;
//void func(int n, int left, int mid, int right)
//{
//	if (n == N)
//	{
//		ret++;
//		return;
//	}
//
//	int n_left = 0;
//	int n_mid = 0;
//	int n_right = 0;
//	for (int i = 1; i < 1<<N; i = i<<1)
//	{
//		if (left & i)
//			n_left |= i<<1;
//		if (mid & i)
//			n_mid |= i;
//		if (right&i)
//			n_right |= i>>1;
//	}
//	for (int i = 1; i < 1<<N; i = i<<1)
//	{
//		if (!(n_left &i) && !(n_right&i) && !(n_mid&i))
//		{
//			n_left |= i;
//			n_right |= i;
//			n_mid |= i;
//			func(n + 1, n_left, n_mid, n_right);
//			n_left &= ~i;
//			n_right &= ~i;
//			n_mid &= ~i;
//		}
//	}
//}
//int main()
//{
//	int left = 0;
//	int mid = 0;
//	int right = 0;
//	scanf("%d", &N);
//	func(0, left, mid, right);
//	printf("%d\n", ret);
//	return 0;
//}

// 암호만들기

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//
//int L, C;
//char arr[16];
//char ret[16];
//void func(int l, int idx, int c, int v)
//{
//	if (l == L)
//	{
//		if (c >= 2 && v >= 1)
//			printf("%s\n", ret);
//		return;
//	}
//		
//
//	for (int i = idx; i < C; i++)
//	{
//		ret[l] = arr[i];
//		if (ret[l] == 'a' || ret[l] == 'e' || ret[l] == 'o'
//			|| ret[l] == 'i' || ret[l] == 'u')
//			func(l + 1, i+1, c, v + 1);
//		else
//			func(l + 1, i+1, c+1, v);
//		ret[l] = '\0';
//	}
//}
//int main()
//{
//	scanf("%d %d", &L, &C);
//	for (int i = 0; i < C; i++)
//		scanf(" %c", &arr[i]);
//	sort(arr, arr + C);
//	func(0,0,0,0);
//	return 0;
//}

//ACM Craft

//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<memory.h>
//using namespace std;
//
//int T, N, K, W;
//int to, from;
//int time[1001];
//vector<int> graph[1001];
//bool visit[1001];
//
//int dfs(int n)
//{
//	int size = graph[n].size();
//	if (size == 0)
//		return 0;
//	int max = 0;
//	for (int i = 0; i < size; i++)
//	{
//		int pre = graph[n][i];
//		if (!visit[pre])
//		{
//			visit[pre] = true;
//			time[pre] += dfs(pre);
//		}
//		if (max < time[pre])
//			max = time[pre];
//	}
//	return max;
//}
//
//int main()
//{
//	scanf("%d", &T);
//	for (int tc = 0; tc < T; tc++)
//	{
//		memset(time, 0, sizeof(time));
//		memset(visit, 0, sizeof(visit));
//		for (int i = 1; i <= N; i++)
//			graph[i].clear();
//		scanf("%d%d", &N, &K);
//		for (int i = 1; i <= N; i++)
//			scanf("%d", &time[i]);
//		for (int i = 0; i < K; i++)
//		{
//			scanf("%d%d", &to, &from);
//			graph[from].push_back(to);
//		}
//		scanf("%d", &W);
//		printf("%d\n", dfs(W)+time[W]);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<memory.h>
//using namespace std;
//
//int T, N, K, W;
//int to, from;
//int time[1001];
//vector<int> graph[1001];
//int visit[1001];
//
//int dfs(int n)
//{
//	int size = graph[n].size();
//	if (size == 0)
//		return 0;
//	int max = -1e9;
//	for (int i = 0; i < size; i++)
//	{
//		int pre = graph[n][i];
//		if (visit[pre] == -1)
//			visit[pre] += (dfs(pre) + time[pre] +1);
//		if (max < visit[pre])
//			max = visit[pre];
//	}
//	return max;
//}
//
//int main()
//{
//	scanf("%d", &T);
//	for (int tc = 0; tc < T; tc++)
//	{
//		memset(time, 0, sizeof(time));
//		memset(visit, -1, sizeof(visit));
//		for (int i = 1; i <= N; i++)
//			graph[i].clear();
//		scanf("%d%d", &N, &K);
//		for (int i = 1; i <= N; i++)
//			scanf("%d", &time[i]);
//		for (int i = 0; i < K; i++)
//		{
//			scanf("%d%d", &to, &from);
//			graph[from].push_back(to);
//		}
//		scanf("%d", &W);
//		printf("%d\n", dfs(W) + time[W]);
//	}
//	return 0;
//}