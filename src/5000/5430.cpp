#include<cstdio>
#include<deque>
std::deque<int> dq;
int T, N;
char s[600001], c;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf(" %s%d", s, &N);
		int i = 0;
		bool d = true, f = true;
		scanf(" %c", &c);
		for(int i=0,t ; i<N; i++) {
			scanf("%d,", &t);
			dq.push_back(t);
		}
		scanf(" %c", &c);
		for (int i = 0; f&&s[i]; i++) {
			if (s[i] == 'R') d = !d;
			else {
				if (dq.empty()) f = !f;
				else {
					if (d) dq.pop_front();
					else dq.pop_back();
				}
			}
		}
		if (!f) printf("error\n");
		else {
			if (dq.empty())printf("[]\n");
			else {
				if (d) {
					printf("[");
					while (dq.size() != 1) {
						printf("%d,", dq.front()); dq.pop_front();
					}
					printf("%d]\n", dq.front()); dq.pop_front();
				}
				else {
					printf("[");
					while (dq.size() != 1) {
						printf("%d,", dq.back()); dq.pop_back();
					}
					printf("%d]\n", dq.back()); dq.pop_back();
				}
			}
		}
	}
	return 0;
}