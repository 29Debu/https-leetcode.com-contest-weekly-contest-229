#include<iostream>
using namespace std;

int dp(int arr[], int n, int wt){
	int ed[n+1][wt+1];
	for (int i = 0; i < n+1; ++i)
		for (int j = 0; j < wt+1; ++j)
		{
			if(j == 0)
				ed[i][0] = 1;
			else if(i == 0)
				ed[0][j] = 0;
			else if(arr[i - 1] > j)
				ed[i][j] = ed[i -1][j];
			else
				ed[i][j] = ed[i - 1][j] + ed[i-1][j-arr[i-1]];
		}
	return ed[n][wt];
}

int main()
{
	int brr[] = {2, 3, 5, 6, 7, 8, 10};
	int k = sizeof(brr)/sizeof(brr[0]);
	int m = 10;
	cout<< dp(brr, k, m);
	return 0;
}