#include <bits/stdc++.h>

using namespace std;

int main() {
    map<vector<int>, map<int, long double> > dp;
    int N;
    vector<int> v;

    scanf("%d", &N);
    v.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    dp[v][0] = 1.0L;

    do {
        // find inversions
        vector<pair<int, int> > inv;
        for (int i = 0; i < v.size() - 1; i++)
            for (int j = i + 1; j < v.size(); j++)
                if (v[i] > v[j])
                    inv.push_back({i, j});
        for (auto i : inv) {
            swap(v[i.first], v[i.second]);
            auto & nxt = dp[v];
            swap(v[i.first], v[i.second]);
            for (auto j : dp[v]) {
                nxt[j.first + 1] += j.second / inv.size();
            }
        }

    } while (prev_permutation(v.begin(), v.end()));
    next_permutation(v.begin(), v.end());

    long double ans = 0;
    for (auto i : dp[v])
        ans += i.first * i.second;
    printf("%.10Lf", ans);

    return 0;
}