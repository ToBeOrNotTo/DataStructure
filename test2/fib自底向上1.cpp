#include<iostream>
using namespace std;
int fib(int n)
{
	int a, b;
	if (n < 2)
		return 1;
	else
	{
		a = 1, b = 1;
		for (int i = 0; i < n - 1; i++)
		{
			a = a + b;
			b = a - b;
		}
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	cout << fib(n);
	return 0;
}
