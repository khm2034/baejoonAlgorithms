/*#include<iostream>
#include<vector>

using namespace std;

void input();


int main() 
{

}*/

//
//#include<iostream>
//
//using namespace std;
//
//template<typename It>
//void _swap(It &a, It&b)
//{
//	It c(a);
//	a = b;
//	b = c;
//}
//
//
//template<typename It, typename Comp>
//void _sort(It begin, It end, Comp comp)
//{
//	if (begin == end)
//		return;
//	_swap(*begin, *((end - begin) / 2 + begin));
//	It pi = begin;
//	It le = begin + 1;
//	It ri = end - 1;
//	while (le <= ri)
//	{
//		while (le <= ri && !comp(*pi, *le))
//			le++;
//		while (le <= ri && !comp(*ri, *pi))
//			ri--;
//		if (le <= ri)
//			_swap(*le, *ri);
//	}
//	_swqp(*pi, *ri);
//	_sort(begin, ri, comp);
//	_sort(ri + 1, end, comp);
//}
//
//template<typename It, typename Comp>
//void _sort(It A[], It begin, It end, Comp comp)
//{
//
//}