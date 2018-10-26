#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 5;

int n, T, res = 1e8, a[N][N], d[N][N], F[N][N];
bool cal[N][N];

void Input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
            d[i][j] = d[i][j - 1] + a[j - 1][j];
    }
}

int DP(int i, int type)
{
	if (i == 1)
		return 0;

	if (cal[i][type]) return F[i][type];

	int res = 1e8;
	for (int c = 2; c < i; c++)
	{
		int c_sum = a[i][i - c] + d[i - c + 1][i - 1];
		if (type == 0)
			c_sum += a[i - 1][i + 1];
		if (i - c == 1)
			c_sum += a[1][2];

		res = min(res, c_sum + DP(i - c, 0));
	}

	if (type == 0)
	{
		int c_sum = 0, root = i;
		for (int j = i - 1; j >= 1; j--)
		{
			c_sum += a[j][root], root = j;
			res = min(res, c_sum + a[max(1, j - 1)][i + 1] + DP(j, 1));
		}
	}

	cal[i][type] = true;
	return (F[i][type] = res);
}

int main()
{
    freopen("HTDL.INP", "r", stdin);
    freopen("HTDL.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        memset(cal, false, sizeof (cal));
        memset(F, 0, sizeof (F));
        Input();
        res = d[2][n] + a[1][2];
        for (int i = 2; i <= n; i++)
        {
            int curr = DP(i, 0) + d[i + 1][n];
            res = min(res, curr);
        }
        cout << res << '\n';
    }
    return 0;
}