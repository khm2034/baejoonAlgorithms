#include<iostream>
#include<deque>
#include<string>
using namespace std;
deque<int> dq;
int main() {
	int n, t;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "push_back") {
			cin >> t;
			dq.push_back(t);
		}
		else if (s == "push_front") {
			cin >> t;
			dq.push_front(t);
		}
		else if (s == "pop_front") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (dq.empty()) printf("-1\n");
			else {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
		}
		else if (s == "size") printf("%d\n", dq.size());
		else if (s == "empty") printf("%d\n", dq.empty() ? 1 : 0);
		else if (s == "front") printf("%d\n", dq.empty() ? -1 : dq.front());
		else if (s == "back") printf("%d\n", dq.empty() ? -1 : dq.back());
	}
	return 0;
}