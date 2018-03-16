#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
typedef long long ll;

int hashValue1[26] = {1087, 1489, 1553, 1657, 2053, 2203, 2707, 3023, 3319, 1151, 1297, 1459, 1607, 1759, 1949, 2311, 2557, 2819, 3191, 3539, 4177, 4507, 5209, 5573, 6947, 7919};
int hashValue2[26] = { 73, 179, 283, 419, 547, 661, 811, 947, 1087, 1229, 1381, 1523, 1663, 1823, 1993, 2131, 2293, 2437, 2621, 2749, 2909, 3083, 3259, 3433, 3581, 3733 };
int hashValue3[26] = { 7829, 7643, 7499, 7297, 7103, 6917, 6761, 6571, 6367, 6221, 6053, 5857, 5693, 5521, 5387, 5179, 5003, 4831, 4657, 4493, 4297, 4139, 3989, 3821, 3643, 3511 };
string sa;
string sb;

ll hash_a[3] = { 0, };
ll save_hash_a[3] = { 0, };
bool save_a = false;
ll hash_b[3] = { 0, };
bool save_b = false;
ll save_hash_b[3][1501] = { 0, };

void init1()
{
	for (int i = 0; i < 3; i++)
		hash_a[i] = 0;
}
void init2()
{
	for (int i = 0; i < 3; i++)
		hash_b[i] = 0;
}

void getHash(int s_idx, int len, int sel)
{
	if (sel == 0)
	{
		if (!save_a)
		{
			init1();
			for (int i = s_idx; i < len; i++)
			{
				hash_a[0] = (hash_a[0] + hashValue1[sa[i] - 'a'] * (ll)sa[i]);
				hash_a[1] = (hash_a[1] + hashValue2[sa[i] - 'a'] * (ll)sa[i]);
				hash_a[2] = (hash_a[2] + hashValue3[sa[i] - 'a'] * (ll)sa[i]);
			}
			save_hash_a[0] = hash_a[0];
			save_hash_a[1] = hash_a[1];
			save_hash_a[2] = hash_a[2];
			save_a = true;
		}
		else
		{
			save_hash_a[0] = (save_hash_a[0]- ((hashValue1[sa[len] - 'a'] * (ll)sa[len])));
			save_hash_a[1] = (save_hash_a[1]- ((hashValue2[sa[len] - 'a'] * (ll)sa[len])));
			save_hash_a[2] = (save_hash_a[2]- ((hashValue3[sa[len] - 'a'] * (ll)sa[len])));
			hash_a[0] = save_hash_a[0];
			hash_a[1] = save_hash_a[1];
			hash_a[2] = save_hash_a[2];
		}
	}
	else
	{
		if (!save_b)
		{
			init2();
			for (int i = s_idx; i < len; i++)
			{
				hash_b[0] = (hash_b[0] + hashValue1[sb[i] - 'a'] * (ll)sb[i]);
				hash_b[1] = (hash_b[1] + hashValue2[sb[i] - 'a'] * (ll)sb[i]);
				hash_b[2] = (hash_b[2] + hashValue3[sb[i] - 'a'] * (ll)sb[i]);
			}
			save_hash_b[0][0] = hash_b[0];
			save_hash_b[1][0] = hash_b[1];
			save_hash_b[2][0] = hash_b[2];
			save_b = true;
		}
		else
		{
			save_hash_b[0][0] = (save_hash_b[0][0] - ((hashValue1[sb[len] - 'a'] * (ll)sb[len])));
			save_hash_b[1][0] = (save_hash_b[1][0] - ((hashValue2[sb[len] - 'a'] * (ll)sb[len])));
			save_hash_b[2][0] = (save_hash_b[2][0] - ((hashValue3[sb[len] - 'a'] * (ll)sb[len])));
			hash_b[0] = save_hash_b[0][0];
			hash_b[1] = save_hash_b[1][0];
			hash_b[2] = save_hash_b[2][0];
		}
	}
}
void solve()
{
	int sb_size = sb.size();
	int sa_size = sa.size();

	if (sa_size > sb_size)
	{
		swap(sa, sb);
		swap(sa_size, sb_size);
	}

	for (int i = sa_size, cnt=1; i > 0; i--, cnt++)
	{
		for (int j = 0; j < cnt; j++)
		{
			if (j == 0)
				getHash(j, i, 0);
			else
			{
				hash_a[0] = (hash_a[0] - (hashValue1[sa[j-1] - 'a'] * (ll)sa[j - 1]));
				hash_a[0] = (hash_a[0] + hashValue1[sa[j+i - 1] - 'a'] * (ll)sa[j+i - 1]);
				hash_a[1] = (hash_a[1] - (hashValue2[sa[j - 1] - 'a'] * (ll)sa[j - 1]));
				hash_a[1] = (hash_a[1] + hashValue2[sa[j + i - 1] - 'a'] * (ll)sa[j+i - 1]);
				hash_a[2] = (hash_a[2] - (hashValue3[sa[j - 1] - 'a'] * (ll)sa[j - 1]));
				hash_a[2] = (hash_a[2] + hashValue3[sa[j + i - 1] - 'a'] * (ll)sa[j+i - 1]);
			}
			int loop = sb_size - i+1;
			for (int k = 0; k < loop; k++)
			{
				if (j == 0)
				{
					if (k == 0)
						getHash(k, i, 1);
					else
					{
						hash_b[0] = (hash_b[0] - (hashValue1[sb[k - 1] - 'a'] * (ll)sb[k - 1]));
						save_hash_b[0][k] = hash_b[0] = (hash_b[0] + hashValue1[sb[k + i - 1] - 'a'] * (ll)sb[k + i - 1]);
						hash_b[1] = (hash_b[1] - (hashValue2[sb[k - 1] - 'a'] * (ll)sb[k - 1]));
						save_hash_b[1][k] = hash_b[1] = (hash_b[1] + hashValue2[sb[k + i - 1] - 'a'] * (ll)sb[k + i - 1]);
						hash_b[2] = (hash_b[2] - (hashValue3[sb[k - 1] - 'a'] * (ll)sb[k - 1]));
						save_hash_b[2][k] = hash_b[2] = (hash_b[2] + hashValue3[sb[k + i - 1] - 'a'] * (ll)sb[k + i - 1]);
					}
				}

				if ((hash_a[0] == save_hash_b[0][k]) && (hash_a[1] == save_hash_b[1][k]) && (hash_a[2] == save_hash_b[2][k]))
				{
					printf("%d\n", i);
					return;
				}
			}
		}
	}
	printf("0\n");
}

int main()
{
	freopen("input.txt", "r", stdin);
	cin >> sa >> sb;
	solve();
	return 0;
}