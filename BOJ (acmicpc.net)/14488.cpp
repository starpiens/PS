#include <bits/stdc++.h>

using namespace std;

typedef long long lld;
lld pos[50000];

int main() {
    int N;
    pair<lld, lld> range = {-4e18, 4e18};
    string T_str;
    cin >> N;
    cin >> T_str;
    for (int i = 0; i < N; i++) {
        cin >> pos[i];
        pos[i] *= 1e4;
    }

    // parse T
    lld T = 0;
    int T_pnt = 0;
    for (int i = 0; i < T_str.length(); i++) {
        if (T_pnt) T_pnt++;
        if (T_str[i] == '.') T_pnt = 1;
        else {
            T *= 10;
            T += T_str[i] - '0';
        }
    }
    if (T_pnt) T_pnt--;
    for (int i = T_pnt; i < 4; i++)
        T *= 10;

    for (int i = 0; i < N; i++) {
        lld v;
        cin >> v;
        if ((double)pos[i] / T - v > (double)range.first / T - 1)
            range.first = max(range.first, pos[i] - v * T);
        if ((double)pos[i] / T + v < (double)range.second / T + 1)
            range.second = min(range.second, pos[i] + v * T);
    }

    cout << (range.first <= range.second);
    return 0;
}