#include <bits/stdc++.h>
using namespace std;

// if there is no update query go for sparse table

class SparseTable
{

public:
    vector<vector<int>> sparse;
    int k;

    SparseTable(int n, int arr[])
    {

        k = n;

        sparse.resize(n, vector<int>(20, -1)); // resisze the sparse table
        // 2^0 2^1 2^2 2^3

        for (int i = 0; i < n; i++)
        {
            sparse[i][0] = arr[i]; // from i to i max is arr[i]
        }

        for (int j = 1; j < 20; j++)
        {

            for (int i = 0; i < n; i++)
            {

                if ((i + pow(2, j)) <= n)
                {

                    sparse[i][j] = max(sparse[i][j - 1], sparse[i + pow(2, j - 1)][j - 1]); // 
                    // chage here for min max for sum also you can
                }
                else
                {
                    break;
                }
            }

        } // filling table
    }

    void printsparse()
    {

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << sparse[i][j] << " ";
            }

            cout << endl;
        }
    }

    void queryformax(int l, int r)
    {

        // l and r are 0 -based

        int len = r - l + 1;
        int maxi = INT_MIN;

        while (len > 0)
        {

            int k = (int)log2(len);

            maxi = max(maxi, sparse[l][k]);
            l = l + pow(2, k);

            len -= pow(2, k);
        }

        cout << maxi << endl;

        
    }
};

int main()
{

    int arr[5] = {2, 1, 4, 3, 6};
    int n = 5;

    SparseTable s(5, arr);
    // s.printsparse();

    s.queryformax(3, 4);
}
