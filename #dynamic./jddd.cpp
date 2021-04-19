//edit distance
#include<iostream>
using namespace std;

int min(int x, int y, int z) 
{
    return min(min(x, y), z);
}

int main()
{
	char str1[] = "CART";
	char str2[] = "MARCH";
	int n = sizeof(str1)/sizeof(str1[0]);
	int m = sizeof(str2)/sizeof(str2[0]);
	int dmmy[n+1][m+1];
	for (int i = 0; i < m+1; ++i)
		dmmy[0][i] = i;
	for (int j = 0; j < n+1; ++j)
		dmmy[j][0] = j;
	for (int p = 0; p < n; ++p)
		for (int q = 0; q < m; ++q)
		{
			if (str1[p] == str2[q])
				dmmy[p+1][q+1] = dmmy[p][q];
			else
				dmmy[p+1][q+1] = min(dmmy[p][q], dmmy[p+1][q], dmmy[p][q+1]) + 1;
		}
	cout<<dmmy[n][m];
	return 0;
}