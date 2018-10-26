#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 5;

int n, m, res;
vector<int> adj[N];
queue<pair<int, int> > Q;
bool check[N][N], visited[N];

int cnt, edge[N][N], parent[N], low[N], v_time[N];

void Input()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void Bridge(int u)
{
    visited[u] = true;
    cnt++, v_time[u] = low[u] = cnt;

    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (!visited[v])
        {
            parent[v] = u;
            Bridge(v);
            low[u] = min(low[u], low[v]);

            if (v_time[u] < low[v])
            {
                check[u][v] = check[v][u] = true;
                res++;
            }
        }

        else if (v != parent[u])
            low[u] = min(low[u], v_time[v]);
    }
}

void DFS(int u)
{
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if ((visited[v] && edge[u][v] || edge[v][u]) || v == parent[u])
            continue;

        parent[v] = u;
        edge[u][v] = 1;
        Q.push(make_pair(u, v));
        if (check[u][v])
            Q.push(make_pair(v, u));

        DFS(v);

    }
}

void Solve()
{
    Bridge(1);
    cout << m - res << '\n';
    memset(visited, false, sizeof (visited));
    DFS(1);
    while (!Q.empty())
    {
        cout << Q.front().first << " " << Q.front().second << '\n';
        Q.pop();
    }
}

int main()
{
    freopen("PLGT.INP", "r", stdin);
    freopen("PLGT.OUT", "w", stdout);
    Input();
    Solve();
    return 0;
}
