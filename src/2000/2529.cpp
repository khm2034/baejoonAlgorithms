#include<iostream>
#include<algorithm>
using namespace std;
int N, ne[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }, pr[10] = { 9,8,7,6,5,4,3,2,1,0 };
char op[10], mx[10], mi[10];
void input_data() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf(" %c", &op[i]);
}
bool chk(int a[10]) {
	for (int i = 0; i < N; i++) {
		if (op[i] == '<' && a[i] > a[i + 1]) return false;
		if (op[i] == '>' && a[i] < a[i + 1]) return false;
	}
	return true;
}
void solution() {
	do {
		if (chk(ne)) {
			for (int i = 0; i < N+1; i++) mi[i] = ne[i] + '0';
			break;
		}
	} while (next_permutation(ne, ne + 10));

	do {
		if (chk(pr)) {
			for (int i = 0; i < N+1; i++) mx[i] = pr[i] + '0';
			break;
		}
	} while (prev_permutation(pr, pr + 10));
	printf("%s\n%s\n", mx, mi);
}
int main() {
	input_data();
	solution();
	return 0;
}