
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll N = 1e9 + 7;
const ll m = 1e9 + 7;

void dfs(vector<ll> adj[], ll node, stack<ll> &s, vector<ll> &vis)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(adj, it, s, vis);
    }

    s.push(node);
}

// dfs for storing in stack

void dfs2(vector<ll> reversed[], ll node, vector<ll> &vis2, vector<ll> &ans, ll arr[])
{

    vis2[node] = 1;

    for (auto it : reversed[node])
    {
        if (!vis2[it])
            dfs2(reversed, it, vis2, ans, arr);
    }

    ans.push_back(arr[node]);
}

// for final answer dfs

int main()
{

    ll n;
    cin >> n;

    ll arr[n + 1];

    for (ll i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    vector<ll> adj[n + 1];
    vector<ll> reversed[n + 1]; // reveresed edges

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        reversed[v].push_back(u);
    }

    stack<ll> s;
    vector<ll> vis(n + 1, 0);
    for (ll i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(adj, i, s, vis);
        }
    }

    vector<ll> vis2(n + 1, 0);
    vector<vector<ll>> scc;

    while (!s.empty())
    {

        ll a = s.top();
        s.pop();

        if (vis2[a] == 0)
        {

            vector<ll> ans;

            dfs2(reversed, a, vis2, ans, arr);

            sort(ans.begin(), ans.end());
            scc.push_back(ans);
        }
    }

    ll ways = 1;
    ll cost = 0;

    for (auto it : scc)
    {

        ll start = it[0];
        cost += start;

        ll size = it.size();

        ll count = 0;

        for (ll i = 0; i < size; i++)
        {
            if (it[i] == start)
            {
                count++;
            }
            else
            {
                break;
            }
        }

        ways = (ways * count) % N;
    }

    cout << cost << " " << ways << endl;

    // real work starts

    // reverse all edges
}
