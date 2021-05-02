#include <iostream>
using namespace std;


int dp(int ar[], int k, int wt){
    int z[k+1][wt+1];
    for (int i = 0; i < k+1; ++i)
    	for (int j = 0; j < wt+1; ++j)
    	{
    		if (i == 0 || j== 0)
    			z[i][j] = 0;
    		else if (ar[i-1] <= j)
    		{
    			z[i][j] = max(ar[i-1] + z[i-1][j - ar[i-1]], z[i-1][j]);
    		}
    		else
    			z[i][j] = z[i-1][j];
    	}
    return z[k][wt];
}


int main()
{
	int arr[] = {2, 3, 7, 8, 10};
	int n = sizeof(arr)/sizeof(arr[0]);
	int w = 11;
	int c = dp(arr, n, w);
	if (c == w)
		cout<<"yes";
	else
		cout<<"no";
	return 0;
}