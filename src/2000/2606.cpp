#include <iostream>
#include <vector>

using namespace std;

void input();
void solution(int p);
void result();


int visitCom[101];
vector<vector<int>*> connect;

int comNum;
int connectNum;
int virus = 0;

int main()
{
	input();
	solution(0);
	result();

	cout << virus << endl;

	return 0;
}

void input()
{
	for (int i = 0; i < 101; i++)
		visitCom[i] = -1;


	cin >> comNum;

	for (int i = 0; i < comNum; i++)
	{
		visitCom[i] = 0;
		connect.push_back(new vector<int>());
	}

	cin >> connectNum;

	for (int i = 0; i < connectNum; i++)
	{
		int com1;
		int com2;

		cin >> com1 >> com2;

		connect[com2 - 1]->push_back(com1 - 1);
		connect[com1 - 1]->push_back(com2 - 1);
	}

	visitCom[0] = 1;
}

void solution(int p)
{	
	vector<int> tmp = *(connect[p]);

	for (int i = 0; i < tmp.size(); i++) {
		if (visitCom[tmp[i]] == 0) {
			visitCom[tmp[i]] = 1;
			solution(tmp[i]);
		}
	}
}

void result() 
{
	for (int i = 1; i < comNum; i++) 
	{
		virus += visitCom[i];
	}
}