
//Longest Common Subsequence
#include <iostream>
#include<string.h>
using namespace std;
int j = 0;

int longcom(char c1[], int dum1, char c2[], int dum2)
{
    int l[dum1+1][dum2+1];
    for (int i = 0; i < dum1+1; ++i)
    	for (int j = 0; j < dum2+1; ++j)
    	{
    		if (i == 0 || j == 0)
    			l[i][j] = 0;
    		else if (c1[i - 1] == c2[j-1])
    			l[i][j] = l[i-1][j-1] + 1;
    		else
    			l[i][j] = max(l[i-1][j], l[i][j-1]);
    	}
    return l[dum1][dum2];
}

int main()
{
	char s1[] = "bact";
	char s2[] = "abart";
    int size1 = sizeof(s1)/sizeof(s1[0]);
    int size2 = sizeof(s2)/sizeof(s2[0]);
    int s = longcom(s1, size1, s2, size2);
    cout<<s;
	return 0;
}