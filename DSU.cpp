#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 0);
        parent.resize(n + 1, -1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateparent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUltimateparent(parent[node]);
    }

    void unionByRank(int u, int v)
    {

        int upar = findUltimateparent(u);
        int vpar = findUltimateparent(v);

        if (findUltimateparent(u) == findUltimateparent(v))
        {
            return;
        }

        if (size[upar] == size[vpar])
        {
            parent[vpar] = upar;
            size[upar]++;
        }

        else if (size[upar] < size[vpar])
        {
            parent[upar] = vpar;
        }

        else
        {
            parent[vpar] = upar;
        }
    }

    bool sameComponent(int u, int v)
    {
        return findUltimateparent(u) == findUltimateparent(v);
    }
};

int main()
{

    DisjointSet d1(4);

    // 1 2 3 4
    d1.unionByRank(1, 2);
    d1.unionByRank(3, 4);
    // d1.unionByRank(4, 1);

    if (d1.sameComponent(2, 3))
    {
        cout << "SAME";
    }

    

}


// what a dsu can do it can find whether two nodes belong to same compo or not based on some condition
// ultimate parent is used u   v ka ultimate parent kya hai 
