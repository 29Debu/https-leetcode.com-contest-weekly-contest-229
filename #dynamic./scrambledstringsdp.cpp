#include <iostream>
#include <limits.h>
#include <string.h>
#include <unordered_map>
using namespace std;

unordered_map <string, bool> abc;

bool ss(string s1, string s2){
	if(s1.length() != s2.length())
		return false;
	int n = s1.length();
	if(s1 == s2 || n == 0)
		return true;
	string key = s1;
	key.push_back(' ');
	key.append(s2);
	if(abc.find(key) != abc.end())
	    return abc[key];
	else{
	for (int i = 1; i < n; ++i){
		if(ss(s1.substr(0, i), s2.substr(0, i)) && ss(s1.substr(i, n-i), s2.substr(i, n-i))){
		    abc[key] = true;
			return true;
		}
		if(ss(s1.substr(0, i), s2.substr(n-i, i)) && ss(s1.substr(i, n-1), s2.substr(0, n-i))){
			abc[key] = true;
			return true;
		}
	}
	return false;
	}
}

int main()
{
	string arr1 = "great";
	string arr2 = "rgeat";
	bool k = ss(arr1, arr2);
	cout<<k;
	return 0;
}