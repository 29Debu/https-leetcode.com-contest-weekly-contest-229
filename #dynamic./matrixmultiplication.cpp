//recursive solution

#include<iostream>
#include <limits.h>
using namespace std;

int mm(int ar[], int x, int y){
	if(x == y)
		return 0;
	int temp;
	int mn = INT_MAX;
	for (int i = x; i < y; ++i)
	{
		temp = mm(ar, x, i) + mm(ar, i+1, y) + (ar[x-1]*ar[i]*ar[y]);
		if(mn > temp){
		    mn = temp;
		}
	}
	return mn;
}

int main()
{
	int arr[] = {40, 20, 30, 10, 30};
	int t = sizeof(arr)/sizeof(arr[0]);
	int a = 1;
	int k = mm(arr, a, t-1);
	cout<<k;
	return 0;
}