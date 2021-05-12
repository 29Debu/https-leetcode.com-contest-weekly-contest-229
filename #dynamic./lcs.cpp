// pure dp

#include <iostream>
#include <string.h>
using namespace std;

int dp(char arr1[], char arr2[], int g1, int g2){
	int t[g1+1][g2+1];
	for(int a = 1; a < g1+1; a++)
		t[a][0] = 0;
	for(int b = 1; b < g2+1; b++)
		t[0][b] = 0;
	t[0][0] = 0;
	for (int i = 1; i < g1+1; ++i)
		for (int j = 0; j < g2+1; ++j)
		{
			if(arr1[i-1] == arr2[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else
				t[i][j] = max(t[i-1][j], t[i][j-1]);
		}
	return t[g1][g2];
}

int main()
{
	char s1[] = "rdebu";
	char s2[] = "rlebu";
	int a1 = sizeof(s1)/sizeof(s1[0]);
	int a2 = sizeof(s2)/sizeof(s2[0]);
	cout<< dp(s1, s2, a1, a2);
	return 0;
}