//recursive + dp

#include<iostream>
#include<string.h>
using namespace std;

int static t[1000][1000];

int dp(char arr1[], char arr2[], int g1, int g2){
	if(g1 == 0 || g2 == 0)
		return 0;
	if(t[g1-1][g2-1] != -1)
		return t[g1-1][g2-1];
	else{
		if(arr1[g1-1] == arr2[g2-1]){
			t[g1-1][g2-1] = 1 + dp(arr1, arr2, g1 - 1, g2 - 1);
			return t[g1-1][g2-1];
		}
		else{
			t[g1-1][g2-1] = max(dp(arr1, arr2, g1-1, g2), dp(arr1, arr2, g1, g2 - 1));
			return t[g1-1][g2-1];
		}
	}
	return 0;
}

int main()
{
	char s1[] = "debu";
	char s2[] = "sebu";
	int a1 = sizeof(s1)/sizeof(s1[0]);
	int a2 = sizeof(s2)/sizeof(s2[0]);
	memset(t, -1, sizeof(t));
	cout<<dp(s1, s2, a1, a2);
	return 0;
}