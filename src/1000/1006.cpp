//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//void input();
//void solution();
//void solution2();
//void init();
//void inFunction(int index, int right, int left, int tmp);
//void outFunction(int index, int right, int left, int tmp);
//
//int in[10000] = { 0, };
//int out[10000] = { 0, };
//int inVisit[10000] = { 0, };
//int outVisit[10000] = { 0, };
//int num;
//int w;
//int cnt = 0;
//int cnt2 = 0;
//int isClear;
//int tmpClear;
//
//int main()
//{
//	int testCase;
//
//	cin >> testCase;
//
//	for (; testCase > 0; testCase--)
//	{
//		
//		input();
//		
//		solution();
//
//		for (int i = 0; i < num; i++)
//		{
//			inVisit[i] = 0;
//			outVisit[i] = 0;
//		}
//		cnt2 = cnt;
//		cnt = 0;
//		isClear = tmpClear;
//		solution2();
//		if (cnt < cnt2)
//			cout << cnt << endl;
//		else
//			cout << cnt2 << endl;
//
//		cnt = 0;
//		cnt2 = 0;
//		init();
//	}
//
//	return 0;
//}
//void init()
//{
//	for (int i = 0; i < num; i++)
//	{
//		in[i] = 0;
//		out[i] = 0;
//		inVisit[i] = 0;
//		outVisit[i] = 0;
//	}
//}
//
//void input()
//{
//	cin >> num >> w;
//	isClear = num * 2;
//	tmpClear = isClear;
//	for (int i = 0; i < num; i++)
//		cin >> in[i];
//	for (int i = 0; i < num; i++)
//		cin >> out[i];
//}
//
//void solution()
//{
//	while (isClear != 0)
//	{
//		int max = 0;
//		int maxIndex = 0;
//		for (int i = 0; i < num; i++)
//		{
//			if (inVisit[i] == 0 && max < in[i])
//			{
//				max = in[i];
//				maxIndex = i;
//			}
//		}
//		for (int i = 0; i < num; i++)
//		{
//			if (outVisit[i] == 0 && max < out[i])
//			{
//				max = out[i];
//				maxIndex = i + num;
//			}
//		}
//
//		if (maxIndex >= num)
//		{
//			if (maxIndex == num)
//			{
//				int tmp = w - out[0];
//
//				outVisit[0] = 1;
//
//				int index = 0;
//				int right = 1;
//				int left = num - 1;
//
//				outFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//			else if (maxIndex == ((num * 2) - 1))
//			{
//				int tmp = w - out[num - 1];
//
//				outVisit[num - 1] = 1;
//
//				int index = num - 1;
//				int right = 0;
//				int left = index - 1;
//
//				outFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//			else
//			{
//				int tmp = w - out[maxIndex - num];
//
//				outVisit[maxIndex - num] = 1;
//
//				int index = maxIndex - num;
//				int right = index + 1;
//				int left = index - 1;
//
//				outFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//		}
//		else
//		{
//			if (maxIndex == 0)
//			{
//				int tmp = w - in[0];
//
//				inVisit[0] = 1;
//
//				int index = 0;
//				int right = 1;
//				int left = num - 1;
//
//				inFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//			else if (maxIndex == (num - 1))
//			{
//				int tmp = w - in[num - 1];
//
//				inVisit[num - 1] = 1;
//
//				int index = num - 1;
//				int right = 0;
//				int left = index - 1;
//
//				inFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//			else
//			{
//				int tmp = w - in[maxIndex];
//
//				inVisit[maxIndex] = 1;
//
//				int index = maxIndex;
//				int right = index + 1;
//				int left = index - 1;
//
//				inFunction(index, right, left, tmp);
//
//				cnt++;
//				isClear--;
//			}
//		}
//	}
//}
//
//void solution2()
//{
//	for (int i = 0; i < num; i++)
//	{
//		if (inVisit[i] != 0)
//			continue;
//
//		inVisit[i] = 1;
//
//		if (i == 0)
//		{
//			int tmp = w - in[0];
//				
//			int index = 0;
//			int right = 1;
//			int left = num - 1;
//				
//			inFunction(index, right, left, tmp);
//				
//			cnt++;
//			isClear--;
//		}
//		else if(i == num-1)
//		{
//			int tmp = w - in[i];
//			int index = i;
//			int right = 0;
//			int left = index - 1;
//				
//			inFunction(index, right, left, tmp);
//				
//			cnt++;
//			isClear--;
//		}
//		else
//		{			
//			int tmp = w - in[i];
//				
//			int index = i;
//			int right = index + 1;
//			int left = index - 1;
//				
//			inFunction(index, right, left, tmp);
//				
//			cnt++;
//			isClear--;
//		}
//	}
//
//	for (int i = 0; i < num; i++)
//	{
//		if (outVisit[i] != 0)
//			continue;
//
//		outVisit[i] = 1;
//
//		if (i == 0)
//		{
//			int tmp = w - out[0];
//			
//			int index = 0;
//			int right = 1;
//			int left = num - 1;
//			
//			outFunction(index, right, left, tmp);
//			
//			cnt++;
//			isClear--;
//		}
//		else if (i == num - 1)
//		{
//			int tmp = w - out[i];
//
//			int index = i;
//			int right = 0;
//			int left = index - 1;
//			
//			outFunction(index, right, left, tmp);
//
//			cnt++;
//			isClear--;
//		}
//		else
//		{
//			int tmp = w - out[i];
//			int index = i;
//			int right = index + 1;
//			int left = index - 1;
//	
//			outFunction(index, right, left, tmp);
//	
//			cnt++;
//			isClear--;
//		}
//	}
//}
//
//void inFunction(int index, int right, int left, int tmp)
//{
//	int tmpMax = 0;
//	int check = 0;
//	if (outVisit[index] == 0 && out[index] <= tmp && out[index] > tmpMax)
//	{
//		check = 1;
//		tmpMax = out[index];
//	}
//	if (inVisit[right] == 0 && in[right] <= tmp && in[right]>tmpMax)
//	{
//		check = 2;
//		tmpMax = in[right];
//	}
//	if (inVisit[left] == 0 && in[left] <= tmp && in[left]>tmpMax)
//	{
//		check = 3;
//		tmpMax = in[left];
//	}
//
//	switch (check)
//	{
//	case 1:
//		outVisit[index] = 1;
//		isClear--;
//		break;
//	case 2:
//		inVisit[right] = 1;
//		isClear--;
//		break;
//	case 3:
//		inVisit[left] = 1;
//		isClear--;
//		break;
//	defalut:
//		break;
//	}
//}
//void outFunction(int index, int right, int left, int tmp)
//{
//	int tmpMax = 0;
//	int check = 0;
//	if (inVisit[index] == 0 && in[index] <= tmp && in[index] > tmpMax)
//	{
//		check = 1;
//		tmpMax = in[index];
//	}
//	if (outVisit[right] == 0 && out[right] <= tmp && out[right]>tmpMax)
//	{
//		check = 2;
//		tmpMax = out[right];
//	}
//	if (outVisit[left] == 0 && out[left] <= tmp && out[left]>tmpMax)
//	{
//		check = 3;
//		tmpMax = out[left];
//	}
//	switch (check)
//	{
//	case 1:
//		inVisit[index] = 1;
//		isClear--;
//		break;
//	case 2:
//		outVisit[right] = 1;
//		isClear--;
//		break;
//	case 3:
//		outVisit[left] = 1;
//		isClear--;
//		break;
//	defalut:
//		break;
//	}
//}