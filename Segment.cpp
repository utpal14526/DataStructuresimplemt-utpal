#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{

public:
    vector<int> tree;
    vector<int> lazy;

    SegmentTree(int n)
    {
        tree.resize(4 * n, 0);
        lazy.resize(4 * n, 0);
    }

    void build(int arr[], int st, int en, int node)
    {

        if (st == en)
        {
            tree[node] = arr[st];
            return;
        }
        int mid = st + (en - st) / 2;

        build(arr, st, mid, 2 * node + 1);
        build(arr, mid + 1, en, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query(int arr[], int l, int r, int st, int en, int node)
    {

        if (lazy[node] != 0)
        {

            tree[node] = (en - st + 1) * (lazy[node]);
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (st >= l && en <= r)
        {
            return tree[node];
        }

        if (en < l || st > r)
        {
            return 0;
        }

        int mid = st + (en - st) / 2;

        int sum1 = query(arr, l, r, st, mid, 2 * node + 1);
        int sum2 = query(arr, l, r, mid + 1, en, 2 * node + 2);

        return sum1 + sum2;
    }

    void pointupdate(int arr[], int x, int st, int en, int node, int u)
    {

        if (st == en)
        {
            arr[st] = u;
            tree[node] = u;
            return;
        }

        int mid = st + (en - st) / 2;

        if (x <= mid)
        {
            pointupdate(arr, x, st, mid, 2 * node + 1, u);
        }
        else
        {
            pointupdate(arr, x, mid + 1, en, 2 * node + 2, u);
        }

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // lazy propogation

    void rangeUpdate(int arr[], int st, int en, int l, int r, int u, int node)
    {

        // if there is some updates for this node
        // transfer it down with value increase of this node

        // entered this node if lazy update is there update this node and make a propogate
        // now lazy update is zero

        if (lazy[node] != 0)
        {

            tree[node] = (en - st + 1) * (lazy[node]); // marking it got niiche
            if (st != en)
            {

                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (st > r || en < l)
        {
            return;
        }

        if (st >= l && en <= r)
        {

            tree[node] = ((en - st + 1) * (u));
            if (st != en)
            {

                lazy[2 * node + 1] += u;
                lazy[2 * node + 2] += u;
            }
            return;
        }

        int mid = st + (en - st) / 2;

        rangeUpdate(arr, st, mid, l, r, u, 2 * node + 1);
        rangeUpdate(arr, mid + 1, en, l, r, u, 2 * node + 2);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

int main()
{

    int arr[5] = {2, 3, 1, 4, 7};
    int n = 5;

    SegmentTree s(5);

    s.build(arr, 0, n - 1, 0);

    s.rangeUpdate(arr, 0, n - 1, 0, 2, 1, 0);

    cout << s.query(arr, 0, 4, 0, n - 1, 0) << endl;

    // s.pointupdate(arr, 2, 0, n - 1, 0, 6);
}