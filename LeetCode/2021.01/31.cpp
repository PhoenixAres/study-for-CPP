class Solution {
public:
    vector<int> f;
    int find(int x)
    {
        while (x != f[x]) x = f[x] = f[f[x]];
        return x;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].size();
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int x = find(i);
                int y = find(j);
                if (x == y) continue;
                vector<pair<char, char> > v;
                for (int k = 0; k < len && v.size() < 3; ++k)
                    if (strs[i][k] != strs[j][k]) v.push_back({strs[i][k], strs[j][k]});
                if (v.size() == 0) f[x] = y;
                else if (v.size() == 2)
                {
                    if (v[0].first == v[1].second && v[0].second == v[1].first) f[x] = y;
                }
            }
        int ans = 0;
        for (int i = 0; i < n; ++i) if (f[i] == i) ++ans;
        return ans;
    }
};