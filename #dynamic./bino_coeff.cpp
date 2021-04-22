#include <iostream>
using namespace std;

int findcoeff(int a, int b, int add){
	if (b > a)
		return 0;
	else if(b == a)
		return 1;
	else if(b == 1)
		return a;
	else{
		add = findcoeff(a-1, b, add) + findcoeff(a-1, b-1, add);
		return add;
	}
}


int main()
{
	int n, k;
	int sum = 0;
	cout<<"enter degree of binomial";
	cin>>n;
	cout<<"\nenter the other value(lol)";
	cin>>k;
    int j = findcoeff(n, k, sum);
    cout<<j;
	return 0;
}