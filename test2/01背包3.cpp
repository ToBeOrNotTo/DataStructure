#include<iostream>
using namespace std;

int m[20][20];

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}
int max(int a, int b)
{
	if (a < b)
		return b;
	else
		return a;
}

void bb(int n, int c, int w[], int v[]) {

	int jMax = min(w[n] - 1, c);
	for (int j = 0; j <= jMax; j++) {
		m[n][j] = 0;
	}
	for (int j = w[n]; j <= c; j++) {
		m[n][j] = v[n];
	}
	for (int i = n - 1; i> 1; i--) {
		jMax = min(w[i] - 1, c);
		for (int j = 0; j <= jMax; j++) {
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j <= c; j++) {

			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[1]);

}

void q(int n, int c, int w[], int x[])
{

	for (int i = 1; i<n; i++) {
		if (m[i][c] == m[i + 1][c])
			x[i] = 0;
		else {
			x[i] = 1;
			c -= w[i];
		}
		x[n] = (m[n][c] > 0) ? 1 : 0;
	}
}



int main()
{

	int n;
	cin >> n;  //¸öÊý
	int c;
	cin >> c;  //ÈÝÁ¿
	int*w = new int[n + 1];
	for (int i = 1; i<n + 1; i++)
	{
		cin >> w[i];

	}
	int *v = new int[n + 1];
	for (int i = 1; i<n + 1; i++)
	{
		cin >> v[i];
	}

	bb(n, c, w, v);
	int* x = new int[n + 1];
	q(n, c, w, x);
	for (int i = 1; i<n + 1; i++) {
		cout << x[i] << " ";

	}
}
