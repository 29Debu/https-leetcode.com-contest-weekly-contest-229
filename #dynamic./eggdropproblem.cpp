#include <iostream>
#include <cstring>
using namespace std;
int static t[10][30];

int eggdrop(int a, int b){
	if(t[a][b] != -1)
		return t[a][b];
	int temp, minn = 999;
	if(a == 0)
		return 0;
	if(a == 1)
		return b;
	for (int i = 0; i <= b; ++i)
		t[1][b] = b;
	for (int j = 0; j <= a; ++j)
		t[j][1] = 1;
	for (int k = 2; k <= b; ++k)
	{
		temp = 1 + (max(eggdrop(a-1, k-1), eggdrop(a, b-k)));
		if(minn>temp){
			minn = temp;
			t[a][b] = minn;
		}
	}
	return minn;
}

int main()
{
	cout<<"enter egg & floors:";
	int e, f;
	cin>>e>>f;
	memset(t, -1, sizeof(t));
	cout<<eggdrop(e, f);
	return 0;
}