#include<iostream>
using namespace std;

int m[20][20];
int s[20][20];

void maxchain(int p[], int m[][20], int s[][20], int n)
{
	for (int i = 1; i <= n; i++)m[i][i] = 0;
	for (int r = 2; r <= n; r++)
	for (int i = 1; i <= n - r + 1; i++)
	{
		int j = i + r - 1;
		m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
		s[i][j] = i;
		for (int k = i + 1; k<j; k++)
		{
			int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
			if (t < m[i][j])
			{
				m[i][j] = t;
				s[i][j] = k;
			}
		}
	}

}
void t(int s[][20], int i, int j)
{
	if (i == j)
		cout << "A" << i;
	else if (i + 1 == j)
		cout << "(A" << i << "A" << j << ")";
	else
	{
		cout << "(";
		t(s, i, s[i][j]);
		t(s, s[i][j] + 1, j);
		cout << ")";
	}

}
int main()
{
	int n;
	cin >> n;
	int *p = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		cin >> p[i];
	maxchain(p, m, s, n);
	t(s, 1, n);
}
