#include <bits/stdc++.h>
#include <cstring>

const int INF = 2e9;

using namespace std;

vector<pair<int, int> > g[10001];
int d[10001], vis[10001];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int cnt = 0, mx = 0;
        int N, D, C;
        scanf("%d %d %d", &N, &D, &C);
        for_each(g, g + N + 1, [](auto & i) -> void { i.clear(); });
        fill(d, d + N + 1, INF);
        memset(vis, 0, sizeof(vis));
        while (D--) {
            int A, B, S;
            scanf("%d %d %d", &A, &B, &S);
            g[B].emplace_back(A, S);
        }

        priority_queue<pair<int, int> > pq;
        pq.push({0, C});
        d[C] = 0;
        while (!pq.empty()) {
            int now = pq.top().second;
            int now_dist = -pq.top().first;
            pq.pop();
            if (!vis[now]) {
                vis[now] = 1;
                mx = max(mx, d[now]);
                cnt++;
            }
            for (auto i : g[now]) {
                int nxt = i.first;
                int nxt_dist = now_dist + i.second;
                if (d[nxt] > nxt_dist) {
                    d[nxt] = nxt_dist;
                    pq.push({-nxt_dist, nxt});
                }
            }
        }

        printf("%d %d\n", cnt, mx);
    }

    return 0;
}