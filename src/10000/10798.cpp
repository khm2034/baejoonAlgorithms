#include<iostream>
#include<string>
std::string s[5];
int main() {
	for (int i = 0; i < 5; i++) std::cin >> s[i];
	for (int i = 0;; i++) {
		bool f = false;
		for (int j = 0; j < 5; j++) {
			if (s[j].size() <= i) continue;
			printf("%c", s[j][i]);
			f = true;
		}
		if (!f) break;
	}
	return 0;
}