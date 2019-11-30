#include <bits/stdc++.h>

using namespace std;

typedef long double Lf;

map<int, Lf> dp;      // state, prob
char in[9][4];

int main() {
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 4; j++) {
            char str[3];
            scanf(" %s", str);
            in[i][j] = str[0];
        }

    dp[0444444444] = 1.0L;
    while (!dp.empty()) {
        auto cur = --dp.end();
        int cur_state = cur->first;
        Lf cur_prob = cur->second;
        if (!cur_state) {
            printf("%.10Lf", cur_prob);
            return 0;
        }
        dp.erase(cur);
        int idx[9];
        for (int i = 0; i < 9; i++) {
            idx[i] = (cur_state >> (3 * i)) & 0b111;
        }
        vector<pair<int, int> > v;
        for (int i = 0; i < 8; i++)
            for (int j = i + 1; j < 9; j++)
                if (idx[i] && idx[j] && in[i][idx[i] - 1] == in[j][idx[j] - 1])
                    v.emplace_back(i, j);

        for (auto i : v) {
            int nxt_state = cur_state - (1 << (3 * i.first)) - (1 << (3 * i.second));
            dp[nxt_state] += cur_prob / v.size();
        }
    }
    printf("0");
    return 0;
}