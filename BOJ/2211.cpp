//
// Created by 김지훈 on 2019-01-20.
//

#include <bits/stdc++.h>

const int INF = 2e9;

using namespace std;

vector<pair<int, int> > g[1001];
int d[1001], prv[1001], vis[1001];
set<pair<int, int> > s;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    fill(d, d + N + 1, INF);

    while (M--) {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        g[A].emplace_back(B, C);
        g[B].emplace_back(A, C);
    }
    priority_queue<pair<int, int> > pq;
    pq.push({0, 1});
    d[1] = 0;
    vis[1] = 1;
    while (!pq.empty()) {
        int now = pq.top().second;
        int now_dist = -pq.top().first;
        pq.pop();
        if (!vis[now]) {
            vis[now] = 1;
            s.insert({prv[now], now});
        }
        for (auto i : g[now]) {
            int nxt = i.first;
            int nxt_dist = now_dist + i.second;
            if (d[nxt] > nxt_dist) {
                d[nxt] = nxt_dist;
                pq.push({-nxt_dist, nxt});
                prv[nxt] = now;
            }
        }
    }

    printf("%d\n", s.size());
    for (auto i : s) {
        printf("%d %d\n", i.first, i.second);
    }

    return 0;
}