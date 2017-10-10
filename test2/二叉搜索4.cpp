#include<iostream>
using namespace std;

int s[20][20];
int w[20][20];
int m[20][20];


void OptimalBinarySerachTree(int n, int b[], int a[])
{
	for (int i = 0; i <= n; i++)
	{
		w[i + 1][i] = a[i];
		m[i + 1][i] = 0;
	}
	for (int r = 0; r<n; r++){
		for (int i = 1; i <= n - r; i++){
			int j = i + r;
			w[i][j] = w[i][j - 1] + a[j] + b[j];
			m[i][j] = m[i + 1][j];
			s[i][j] = i;
			for (int k = i + 1; k <= j; k++){
				int t = m[i][k - 1] + m[k + 1][j];
				if (t<m[i][j]){
					m[i][j] = t;
					s[i][j] = k;
				}
			}
			m[i][j] += w[i][j];
		}
	}
}
void Traceback(int i, int j)
{
	if (j>i){
		int root = s[i][j];
		cout << "S" << root << "是根" << endl;
		if (s[i][root - 1]>0)
		{
			cout << "S" << root << "的左孩子是S" << s[i][root - 1] << endl;
		}
		if (s[root + 1][j]>0)
		{
			cout << "S" << root << "的右孩子是S" << s[root + 1][j] << endl;
		}
		Traceback(i, root - 1);
		Traceback(root + 1, j);
	}
}

int main()
{
	int n;
	cin >> n;
	int *b = new int[n + 1];
	int *a = new int[n + 1];
	for (int i = 1; i <= n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i <= n; i++)
	{
		cin >> a[i];
	}
	OptimalBinarySerachTree(n, b, a);
	Traceback(1, n);
}
