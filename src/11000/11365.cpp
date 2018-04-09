#include<cstdio>
#include<cstring>
using namespace std;

char s[501];
int main()
{
	while (1)
	{
		scanf(" %[^\n]s", s);
		if (strcmp(s, "END") == 0)
			break;
		for (int i = strlen(s)-1; i>=0; i--)
			printf("%c", s[i]);
		printf("\n");
	}
}
