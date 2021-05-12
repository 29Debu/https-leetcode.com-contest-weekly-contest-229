#include <iostream>
using namespace std;

int dp(char arr1[], char arr2[], int g1, int g2){
	int maxi = 0;
	int count = 0;
	for (int i = 1; i < g1+1; ++i)
		for (int j = 1; j < g2+1; ++j)
		{
			if(arr1[i-1] == arr2[j-1]){
				count++;
				maxi = max(count, maxi);
				i++;
			}
			else{
				i = i - count;
				count = 0;
			}
		}
	return maxi;
}

int main(int argc, char const *argv[])
{
	char s1[] = "abcdefgh";
	char s2[] = "kbcrdefgi";
	int a1 = sizeof(s1)/sizeof(s1[0]);
	int a2 = sizeof(s2)/sizeof(s2[0]);
	cout<< dp(s1, s2, a1, a2);
	return 0;
}