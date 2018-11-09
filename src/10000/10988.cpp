#include<iostream>
#include<string>
std::string s;
int main() {
	std::cin >> s;
	for (int i = 0; i * 2 < s.size(); i++) {
		if (s[i] != s[s.size() - 1 - i]) {
			printf("0");
			return 0;
		}
	}
	printf("1");
	return 0;
}