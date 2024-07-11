#include <bits/stdc++.h>
using namespace std;

int *Z_algo(string s, int n)
{
    int *z = new int[n];
    int l = 0, r = 0;

    // we have to make a z-box l to r

    //   if   i > r
    // reset our box
    // l=i;
    // r=i

    // and see matching in prefix makes matches and r++
    // r will stop at non-matching or end
    // make r--
    //  l.... r match hua hai
    // r-l+1

    //  l .... i ... r

    // see the bnda in the prefix

    for (int i = 1; i < n; i++)
    {
        // condition 1
        if (i > r)
        {
            l = i;
            r = i;
            while (r < n and s[r - l] == s[r])
            {
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        // condition 2
        else
        {
            int j = i - l;

            // condition 2a
            if (z[j] < r - i + 1)
            {
                z[i] = z[j];
            }
            // simple prefix wale ka issee extend nahi hua toh z[i]--> z[j]
            // condition 2b

            // can be possible matching
            // l=i
            // match r again
            else
            {
                l = i;
                while (r < n and s[r - l] == s[r])
                {
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    return z;
}

int main()
{
    string s = "abc$abcdabcfabdabe";
    int n = s.size();
    int *z = Z_algo(s, n);
    for (int i = 1; i < n; i++)
    {
        cout << z[i] << " ";
    }
    cout << endl;
    return 0;
}

// to match a string with pattern
// pat+'$'+originalpattern
