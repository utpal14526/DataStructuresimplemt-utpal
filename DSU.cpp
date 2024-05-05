
class DisjollSet
{

public:
    vector<ll> size;
    vector<ll> parent;

    DisjollSet(ll n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1, -1);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }

    ll findUltimateparent(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateparent(parent[node]);
    }

    void unionByRank(ll u, ll v)
    {

        ll upar = findUltimateparent(u);
        ll vpar = findUltimateparent(v);

        if (vpar != upar)
        {
            if (size[vpar] < size[upar])
            {
                swap(vpar, upar);
            }

            // vpar chota upar bada
            parent[upar] = vpar;
            size[vpar] += size[upar];
        }
    }

    bool sameComponent(ll u, ll v)
    {
        return findUltimateparent(u) == findUltimateparent(v);
    }
};
