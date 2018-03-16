#include<iostream>
#include<string>
using namespace std;

struct URL
{
	string pro;
	string host;
	string port;
	string path;

	URL()
	{
		pro = host = port = path = "<default>";
	}
};
	
string s;

void solve(int t)
{
	URL url;
	string tmp;
	int ty = 0;
	for (int i = 0; i <= s.size(); i++)
	{
		switch (ty)
		{
		case 0:
			if (s[i] == ':')
			{
				url.pro = tmp;
				i += 2;
				ty = 1;
				tmp = "";
				continue;
			}
			tmp += s[i];
			break;
		case 1:
			if (s[i] == ':')
			{
				url.host = tmp;
				ty = 2;
				tmp = "";
				continue;
			}
			if (s[i] == '/')
			{
				url.host = tmp;
				ty = 3;
				tmp = "";
				continue;
			}
			if (s[i] == NULL)
			{
				url.host = tmp;
				continue;
			}
			tmp += s[i];
			break;
		case 2:
			if (s[i] == '/')
			{
				url.port = tmp;
				ty = 3;
				tmp = "";
				continue;
			}
			if (s[i] == NULL)
			{
				url.port = tmp;
				continue;
			}
			tmp += s[i];
			break;
		case 3:
			if (s[i] == NULL)
			{
				url.path = tmp;
				continue;
			}
			tmp += s[i];
			break;
		}
	}
	if (t != 0)
		cout << endl;
	cout << "URL #" << t+1 << endl;
	cout << "Protocol = " << url.pro << endl;
	cout << "Host     = " << url.host << endl;
	cout << "Port     = " << url.port << endl;
	cout << "Path     = " << url.path << endl;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; ++tc)
	{
		cin >> s;
		solve(tc);
	}
	return 0;
}