#include<iostream>
#include<vector>
using namespace std;

int T;
vector<char> s1, s2;
char s[1000001];
int main() {
	scanf("%d", &T);
	while (T--) {
		s1.clear(); s2.clear();
		scanf("%s", s);
		for (int i = 0; s[i]; i++) {
			switch (s[i]) {
			case '<':
				if (s1.size() == 0) break;
				s2.push_back(s1.back()); s1.pop_back();
				break;
			case '>':
				if (s2.size() == 0) break;
				s1.push_back(s2.back()); s2.pop_back();
				break;
			case '-':
				if (s1.size() == 0) break;
				s1.pop_back();
				break;
			default:
				s1.push_back(s[i]);
				break;
			}
		}
		for (int i = 0; i < s1.size(); i++) printf("%c", s1[i]);
		for(int i=s2.size()-1; i>=0; i--) printf("%c", s2[i]);
		printf("\n");
	}
	return 0;
}
