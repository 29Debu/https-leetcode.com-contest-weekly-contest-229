#include <iostream>
#include <limits.h>
#include <string.h>
using namespace std;

bool ss(string s1, string s2){
	if(s1.length() != s2.length())
		return false;
	int n = s1.length();
	if(s1 == s2 || n == 0)
		return true;
	for (int i = 1; i < n; ++i){
		if(ss(s1.substr(0, i), s2.substr(0, i)) && ss(s1.substr(i, n-i), s2.substr(i, n-i)))
			return true;
		if(ss(s1.substr(0, i), s2.substr(n-i, i)) && ss(s1.substr(i, n-1), s2.substr(0, n-i)))
			return true;
	}
	return false;
}

int main()
{
	string arr1 = "great";
	string arr2 = "tgeat";
	bool k = ss(arr1, arr2);
	cout<<k;
	return 0;
}