#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

const long long MOD = 1000000007;

using namespace std;
typedef long long ll;

class HashedString
{
private:
    // change M and B if you want
    static const long long M = 1e9 + 9;
    static const long long B = 9973;

    // pow[i] contains B^i % M
    static vector<long long> pow;

    // p_hash[i] is the hash of the first i characters of the given string
    vector<long long> p_hash;

public:
    HashedString(const string &s) : p_hash(s.size() + 1)
    {
        while (pow.size() <= s.size())
        {
            pow.push_back((pow.back() * B) % M);
        }

        p_hash[0] = 0;
        for (int i = 0; i < s.size(); i++)
        {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }

    long long get_hash(int start, int end)
    {
        long long raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<long long> HashedString::pow = {1};

int main()
{
    iostream::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        HashedString hs(s);
        int ans = 0;
        int n = s.size();
        for (int i = 0; i * 2 <= n; i++)
        {
            // works in zero based indexing 
            if (hs.get_hash(0, i - 1) == hs.get_hash(i, 2 * i - 1) && hs.get_hash(2 * i, 2 * i + (n - 2 * i) / 2 - 1) == hs.get_hash(2 * i + (n - 2 * i) / 2, n - 1))
            {
                ans++;
            }
        }

        cout << ans << "\n";
    }
}


//   d c b a


// forward hashing technque 
//   0   0*31+0    31*31+1  

// B 
// p[i+1]=((p[i]*b)+s[i])%M

//  4  4*B+3    4*B^2+3*B+2      4*(B^3)+(3B^2)+2B+1   
