class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        const long long MOD = 1e9 + 7;
        int m = r - l + 1;

        vector<long long> up(m), down(m);
        vector<long long> nup(m), ndown(m);
        vector<long long> pd(m+1, 0), pu(m+1, 0);

        // Init for length-2 arrays
        for (int v = 0; v < m; v++) {
            up[v]   = v;       // # values below v → came up to v
            down[v] = m-1-v;   // # values above v → came down to v
        }

        for (int i = 2; i < n; i++) {
            pd[0] = pu[0] = 0;
            for (int v = 0; v < m; v++) {
                pu[v+1] = (pu[v] + up[v])   % MOD;
                pd[v+1] = (pd[v] + down[v]) % MOD;
            }
            // nup[v]   = sum of down[u] for u < v  (was going down, now go up to v)
            // ndown[v] = sum of up[u]   for u > v  (was going up,   now go down to v)
            for (int v = 0; v < m; v++) {
                nup[v]   = pd[v];              // prefix_down up to (not including) v
                ndown[v] = (pu[m] - pu[v+1] + MOD) % MOD; // suffix_up after v
            }
            swap(up, nup);
            swap(down, ndown);
        }

        long long ans = 0;
        for (int v = 0; v < m; v++)
            ans = (ans + up[v] + down[v]) % MOD;
        return (int)(ans % MOD);
    }
};
