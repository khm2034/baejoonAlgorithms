#include<iostream>
#include<vector>

using namespace std;

class Point
{
public:
	int x;
	int y;
	int r;

	Point(int x, int y, int r)
	{
		this->x = x;
		this->y = y;
		this->r = r;
	}
};

void input();
void solution();
void dfs(int i);
bool check(Point* p1, Point* p2);

int tmpX;
int tmpY;
int tmpR;
int anemyNum;
int groupNum = 0;
int depth = 0;
bool isCheck = false;
vector<Point*> anemyPoint;
vector<vector<int>*> group;
int visit[3000] = { 0, };

int main()
{
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		input();
		solution();

		cout << groupNum << endl;
		groupNum = 0;
		anemyPoint.clear();
		group.clear();
		fill_n(visit, 3000, 0);
	}

	return 0;
}

void input()
{
	cin >> anemyNum;

	for (int i = 0; i < anemyNum; i++)
	{
		cin >> tmpX >> tmpY >> tmpR;
		anemyPoint.push_back(new Point(tmpX, tmpY, tmpR));
		group.push_back(new vector<int>);
	}
}

void solution()
{
	for (int i = 0; i < anemyNum-1; i++)
	{
		for (int j = i + 1; j < anemyNum; j++)
		{
			if (check(anemyPoint[i], anemyPoint[j]))
			{
				group[i]->push_back(j);
				group[j]->push_back(i);
			}
		}
	}
	
	// 规过 2
	visit[0] = 1;
	//

	for (int i = 0; i < group.size(); i++)
	{
		//规过 1
		//if (visit[i] != 0)
		//	continue;
		//visit[i] = 1;
		//dfs(i);
		//groupNum++;


		//规过2
		dfs(i);
		isCheck = false;
		depth = 0;
		
	}
}

void dfs(int i)
{
	//规过 1
	/*for (int j = 0; j < group[i]->size(); j++)
	{
		if (visit[(*group[i])[j]] != 0)
			continue;

		visit[(*group[i])[j]] = 1;
		dfs((*group[i])[j]);
	}*/


	//规过 2
	for (int j = 0; j < group[i]->size(); j++)
	{
		if (visit[(*group[i])[j]] != 0)
			continue;

		visit[(*group[i])[j]] = 1;
		depth++;
		isCheck = true;
		dfs((*group[i])[j]);
		depth--;
	}

	if ((depth == 0 && isCheck) || (group[i]->size() == 0))
		groupNum++;
}

bool check(Point* p1, Point* p2)
{
	int deffX = p1->x - p2->x;
	int deffY = p1->y - p2->y;
	int sumR = p1->r + p2->r;

	if ((deffX*deffX + deffY*deffY) > (sumR*sumR))
		return false;
	else
		return true;
}