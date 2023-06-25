#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// if there is no update query go for sparse table

// Segment tree for maximum

class SegmentTree
{

public:
    ll n;
    vector<ll> tree;
    vector<ll> lazy;

    SegmentTree(ll n)
    {
        tree.resize(4000000);
        lazy.resize(4000000, 0);
        this->n = n;
    }

    void build(ll arr[], ll l, ll r, ll node)
    {

        if (l == r)
        {
            tree[node] = arr[l];
            lazy[node] = 0;
            return;
        }

        ll mid = l + (r - l) / 2;

        build(arr, l, mid, 2 * node + 1);
        build(arr, mid + 1, r, 2 * node + 2);

        tree[node] = (tree[2 * node + 1] + tree[2 * node + 2]);
        lazy[node] = 0;
    }

    ll query(ll l, ll r, ll st, ll en, ll arr[], ll node)
    {

        if (lazy[node] != 0)
        {

            tree[node] += (en - st + 1) * (lazy[node]);
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (en < l || st > r || st > en)
        {
            return 0;
        }

        if (st >= l && en <= r)
        {
            return tree[node];
        }

        ll mid = st + (en - st) / 2;

        return query(l, r, st, mid, arr, 2 * node + 1) + query(l, r, mid + 1, en, arr, 2 * node + 2);
    }

    void updaterange(ll l, ll r, ll st, ll en, ll arr[], ll node, ll val)
    {

        if (lazy[node] != 0)
        {

            tree[node] += (en - st + 1) * (lazy[node]);
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
        // some things i have to propogate

        if (en < l || st > r || st > en)
        {
            return;
        }

        if (st >= l && en <= r)
        {
            tree[node] += ((en - st + 1) * (val));
            if (st != en)
            {

                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        ll mid = st + (en - st) / 2;

        updaterange(l, r, st, mid, arr, 2 * node + 1, val);
        updaterange(l, r, mid + 1, en, arr, 2 * node + 2, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

int main()
{

    ll n, q;
    cin >> n >> q;

    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    SegmentTree s(n);
    s.build(arr, 0, n - 1, 0);

    for (ll i = 0; i < q; i++)
    {

        ll x;
        cin >> x;

        if (x == 1)
        {

            ll a, b, u;
            cin >> a >> b >> u;

            s.updaterange(a - 1, b - 1, 0, n - 1, arr, 0, u);
        }
        else
        {

            ll k;
            cin >> k;

            cout << s.query(k - 1, k - 1, 0, n - 1, arr, 0) << endl;
        }
    }

    // ans
}

// 0 to 3
