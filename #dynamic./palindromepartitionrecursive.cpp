#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

bool ispalindrome(string drr, int t, int r){
	while(t < r){
		if(drr[t] != drr[r])
			return false;
		t++;
		r--;
	}
	return true;
}

int pp(string arr, int a, int b){
	if(a >= b)
		return 0;
	if(ispalindrome(arr, a, b) == true)
		return 0;
	int temp;
	int mn = INT_MAX;
	for (int i = a; i < b; ++i)
	{
		temp = pp(arr, a, i) + pp(arr, i+1, b) + 1;
		if(mn > temp)
			mn = temp;
	}
	return mn;
}

int main()
{
	string s = "debabrata";
	int sa = s.length();
	cout<<pp(s, 0, sa-1);
	return 0;
}